/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:52:41 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/24 15:54:06 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	last_space(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i + 1])
	{
		if (i == 0)
		{
			if (ft_strlen(map->map[i]) > ft_strlen(map->map[i + 1]))
				(map->count) = ft_strlen(map->map[i]);
			else
				(map->count) = ft_strlen(map->map[i + 1]);
		}
		else
		{
			if ((map->count) < ft_strlen(map->map[i + 1]))
				(map->count) = ft_strlen(map->map[i + 1]);
		}
		i++;
	}
}

void	first_sapce(t_map *map)
{
	int		i;
	size_t	j;

	i = 0;
	if (map->map == NULL)
		ft_exit("Error\nMap is NULL");
	while (map->map[i])
	{
		map->map[i] = free_strjoins2(" ", map->map[i]);
		map->map[i] = free_strjoins1(map->map[i], " ");
		i++;
	}
	last_space(map);
	i = 0;
	while (map->map[i])
	{
		j = ft_strlen(map->map[i]);
		while (j <= map->count)
		{
			map->map[i] = free_strjoins1(map->map[i], " ");
			j++;
		}
		i++;
	}
}

int	check_char(char *str, int *n, int *w, int *s)
{
	int	i;
	int	e;

	e = 0;
	i = 0;
	while (str[i])
	{
		if (!(str[i] == '1' || str[i] == '0' || str[i] == 'N'
				|| str[i] == 'W' || str[i] == 'E' || str[i] == 'S'
				|| str[i] == ' '))
			ft_exit("Error\nMap take only 1,0,W,S,N,E");
		if (str[i] == 'E')
			e++;
		if (str[i] == 'N')
			(*n)++;
		if (str[i] == 'S')
			(*s)++;
		if (str[i] == 'W')
			(*w)++;
		i++;
	}
	return (e);
}

void	check_vide(char **tab, int *j, int *i)
{
	if ((tab[*i][*j] == '0' || tab[*i][*j] == 'N' ||
		tab[*i][*j] == 'W' || tab[*i][*j] == 'E' ) && (tab[*i][(*j) + 1] == ' '
		|| tab[*i][(*j) - 1] == ' ' || tab[(*i) + 1][*j] == ' '
		|| tab[(*i) - 1][*j] == ' ' ))
	{
		free_tab(tab);
		ft_exit("Error\nThe Map must be closed");
	}
}

void	check_all_map(t_map *map, int n, int w, int s)
{
	int	i;
	int	e;
	int	j;

	e = 0;
	i = 0;
	while (map->map[i])
		e += check_char(map->map[i++], &n, &w, &s);
	if ((e + n + w + s) != 1)
	{
		free_tab(map->map);
		ft_exit("Error\nCube take 1 player");
	}
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			check_vide(map->map, &j, &i);
			j++;
		}
		i++;
	}
}
