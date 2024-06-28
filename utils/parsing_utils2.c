/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:53:33 by isouaidi          #+#    #+#             */
/*   Updated: 2024/06/28 15:28:19 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == ' ' || str[i] == '\n'))
			return (false);
		i++;
	}
	return (true);
}

bool	is_colors2(char *s)
{
	if (s[0] == 'F' && s[1] == ' ')
	{
		return (true);
	}
	else if (s[0] == 'C' && s[1] == ' ' )
	{
		return (true);
	}
	else
		return (false);
}

bool	is_texture2(char *s)
{
	if (s[0] == 'N' && s[1] == 'O' && s[2] == ' ')
	{
		return (true);
	}
	else if (s[0] == 'W' && s[1] == 'E' && s[2] == ' ')
	{
		return (true);
	}
	else if (s[0] == 'E' && s[1] == 'A' && s[2] == ' ')
	{
		return (true);
	}
	else if (s[0] == 'S' && s[1] == 'O' && s[2] == ' ' )
	{
		return (true);
	}
	else
		return (false);
}

void	check_char_aut(t_map *map)
{
	int	i;

	i = 0;
	while (map->file[i])
	{
		if ((is_colors2(map->file[i]) == false)
			&& (is_space(map->file[i]) == false)
			&& (is_map(map->file[i]) == false)
			&& (is_texture2(map->file[i]) == false))
		{
			free_tab(map->map);
			ft_exit("Error\nCharacter incorrect");
		}
		i++;
	}
}

void	apl_pars(t_map *map, char **av)
{
	check_name_cube(av[1]);
	size_fd(map, av[1]);
	recup(map, av[1]);
	check_texture(map, 0);
	check_colors(map, 0, 0);
	tab_col(map, 0, 0);
	recup_map(map, 0, 0, 0);
	first_sapce(map);
	check_all_map(map, 0, 0, 0);
	check_char_aut(map);
	rctext(map);
}
