/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_col2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:57:07 by isouaidi          #+#    #+#             */
/*   Updated: 2024/06/24 18:37:58 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	char_int(t_map *map)
{
	int		i;
	char	**f;
	char	**c;

	check_int_col(map);
	f = ft_split(map->f_col, ',');
	c = ft_split(map->c_col, ',');
	if (count_tab(f) != 3 || count_tab(c) != 3)
		ft_exit(NBR_COLORS);
	map->int_f = malloc(sizeof(int *) * 3);
	map->int_c = malloc(sizeof(int *) * 3);
	convert(f, map->int_f);
	convert(c, map->int_c);
	i = 0;
	while (i < 3)
	{
		if ((map->int_c[i] < 0 || map->int_c[i] > 255)
			|| (map->int_f[i] < 0 || map->int_f[i] > 255))
			ft_exit(COLORS_ERREUR);
		i++;
	}
	free_tab(c);
	free_tab(f);
}

void	cpy_color(char **tab, char *cpy, int *i, int *j)
{
	int	d;
	int	f;

	f = 0;
	d = 0;
	while (tab[*i][*j])
	{
		while (tab[*i][*j] == ' ')
			(*j)++;
		if (tab[*i][*j] == ',' && f == 0)
			ft_exit(COLORS_ERREUR);
		if (!(tab[*i][*j] >= '0' && tab[*i][*j] <= '9')
			&& (!(tab[*i][*j] == ','))
				&& (!(tab[*i][*j] == '\n')))
			ft_exit(COLORS_ERREUR);
		if ((tab[*i][*j] == ',' && (tab[*i][*j + 1] == '\n'
			|| tab[*i][*j + 1] == ',')))
			ft_exit(NBR_COLORS);
		cpy[d++] = tab[*i][*j];
		f ++;
		(*j)++;
	}
	cpy[d] = '\0';
}

void	tab_col(t_map *map, int i, int j)
{
	while (map->colors[i])
	{
		j = 2;
		if (map->colors[i][j - 2] == 'F')
		{
			map->f_col = malloc(sizeof(char) * (ft_strlen(map->colors[i]) * 2));
			cpy_color (map->colors, map->f_col, &i, &j);
		}
		else if (map->colors[i][j - 2] == 'C')
		{
			map->c_col = malloc(sizeof(char) * (ft_strlen(map->colors[i]) * 2));
			cpy_color(map->colors, map->c_col, &i, &j);
		}
		i++;
	}
	char_int(map);
}
