/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:59:07 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/24 16:00:41 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	is_colors(char *s, t_map *map)
{
	if (s[0] == 'F' && s[1] == ' ')
	{
		map->f ++;
		return (true);
	}
	else if (s[0] == 'C' && s[1] == ' ' )
	{
		map->c ++;
		return (true);
	}
	else
		return (false);
}

bool	count_colors(t_map *map)
{
	if (map->c == 1 && map->f == 1)
		return (true);
	else
		return (false);
}

void	check_colors(t_map *map, int i, int j)
{
	int	count;

	map->colors = malloc(sizeof(char *) * 5);
	if (!(map->colors))
		ft_exit("colors");
	count = 0;
	while (map->file[i])
	{
		map->file[i] = without_space(map->file[i]);
		if (is_colors(map->file[i], map) == true)
		{
			if (count == 2)
				ft_exit(TOO_MUCH_TEXTURES);
			map->colors[j] = ft_strdup(map->file[i]);
			j++;
			count++;
		}
		i++;
	}
	map->colors[j] = NULL;
	if (count_colors(map) == false)
		ft_exit("Error\nCheck your colors");
}

void	check_int_col(t_map *map)
{
	int	i;

	i = 0;
	while (map->c_col[i])
		i++;
}

void	convert(char **str, int *col)
{
	int	i;
	int	b;

	b = 0;
	i = 0;
	while (str[i])
	{
		col[b] = ft_atoi(str[i]);
		b++;
		i++;
	}
	col[3] = 0;
}
