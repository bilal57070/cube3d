/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastutils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:32:18 by bsafi             #+#    #+#             */
/*   Updated: 2024/06/24 19:40:10 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*tab;

	i = 0;
	tab = (void *)malloc(size * nmemb);
	if (!tab)
		return (NULL);
	while (i < nmemb * size)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

void	findpos(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			findpos2(map, i, j);
		}
	}
}

void	findpos2(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'N')
	{
		map->stru.pX = i + 0.5;
		map->stru.pY = j + 0.5;
		map->stru.dX = -1;
		map->stru.dY = 0;
		map->stru.planeX = 0;
		map->stru.planeY = 0.66;
	}
	if (map->map[i][j] == 'S')
	{
		map->stru.pX = i + 0.5;
		map->stru.pY = j + 0.5;
		map->stru.dX = 1;
		map->stru.dY = 0;
		map->stru.planeX = 0;
		map->stru.planeY = -0.66;
	}
	findpos3(map, i, j);
}

void	findpos3(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'W')
	{
		map->stru.pX = i + 0.5;
		map->stru.pY = j + 0.5;
		map->stru.dX = 0;
		map->stru.dY = -1;
		map->stru.planeX = -0.66;
		map->stru.planeY = 0;
	}
	if (map->map[i][j] == 'E')
	{
		map->stru.pX = i + 0.5;
		map->stru.pY = j + 0.5;
		map->stru.dX = 0;
		map->stru.dY = 1;
		map->stru.planeX = 0.66;
		map->stru.planeY = 0;
	}
}
