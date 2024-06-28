/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:49:38 by isouaidi          #+#    #+#             */
/*   Updated: 2024/06/28 15:27:49 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*without_space(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' && s[i] == '\t')
		i++;
	return (s + i);
}

bool	is_texture(char *s, t_map *map)
{
	if (s[0] == 'N' && s[1] == 'O' && s[2] == ' ')
	{
		map->no ++;
		return (true);
	}
	else if (s[0] == 'W' && s[1] == 'E' && s[2] == ' ')
	{
		map->w ++;
		return (true);
	}
	else if (s[0] == 'E' && s[1] == 'A' && s[2] == ' ')
	{
		map->e++;
		return (true);
	}
	else if (s[0] == 'S' && s[1] == 'O' && s[2] == ' ' )
	{
		map->so++;
		return (true);
	}
	else
		return (false);
}

void	init_map(t_map *map)
{
	map->so = 0;
	map->no = 0;
	map->e = 0;
	map->w = 0;
	map->c = 0;
	map->f = 0;
}

bool	count_text(t_map *map)
{
	if (map->so == 1 && map->no == 1 && map->w == 1 && map->e == 1)
		return (true);
	else
		return (false);
}

void	check_texture(t_map *map, int i)
{
	int	j;
	int	count;

	map->text = malloc(sizeof(char *) * 5);
	if (!(map->text))
		ft_exit("file");
	init_map(map);
	j = 0;
	count = 0;
	while (map->file[i])
	{
		if (is_texture(map->file[i], map) == true)
		{
			if (count == 4)
				ft_exit(TOO_MUCH_TEXTURES);
			map->text[j] = modif_ft_strdup(map->file[i]);
			j++;
			count++;
		}
		i++;
	}
	map->text[j] = NULL;
	if (count_text(map) == false)
		ft_exit("Error\nCheck your directions");
}
