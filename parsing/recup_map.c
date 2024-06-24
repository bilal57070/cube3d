/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:14:38 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/24 16:01:12 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	is_map(char *s)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '1')
			j = 1;
		i++;
	}
	if (s[0] != 'F' && s[0] != 'C' && (s[0] == '1' || j != 0))
		return (true);
	else
		return (false);
}

int	countmap(char **tab)
{
	int	i;
	int	count;
	int	f;

	f = 0;
	count = 0;
	i = 0;
	while (tab[i])
	{
		if (is_map(tab[i]) == true && f == 0)
			f = 1;
		if (f == 1)
			count++;
		i++;
	}
	return (count);
}

void	recup_map(t_map *map, int i, int j, int f)
{
	int	count;

	count = countmap(map->file);
	if (count < 1)
		ft_exit("Error\nMap is NULL");
	map->map = malloc(sizeof(char *) * count * 3);
	if (!map->map)
		ft_exit("Error\nMap is NULL");
	map->map[j++] = modif_ft_strdup(" ");
	while (map->file[i])
	{
		if (is_map(map->file[i]) == true && f == 0)
		{
			map->map[j++] = modif_ft_strdup(map->file[i]);
			f = 1;
		}
		else if (f == 1)
			map->map[j++] = modif_ft_strdup(map->file[i]);
		i++;
	}
	map->map[j++] = modif_ft_strdup(" ");
	map->map[j] = NULL;
}
