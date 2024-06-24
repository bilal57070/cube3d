/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:27:41 by bsafi             #+#    #+#             */
/*   Updated: 2024/06/24 18:21:14 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	drawsky(t_map *map)
{
	int		d;

	d = 0;
	while (d < map->stru.drawstart)
	{
		if (d >= HEIGHT)
			break ;
		my_mlx_pixel_put(map->img, map->stru.x, d, create_trgb(0,
				map->int_c[0], map->int_c[1], map->int_c[2]));
		d++;
	}
}

void	drawground(t_map *map)
{
	int		g;

	g = map->stru.drawend;
	while (g < HEIGHT)
	{
		if (g >= HEIGHT)
			break ;
		my_mlx_pixel_put(map->img, map->stru.x, g, create_trgb(0,
				map->int_f[0], map->int_f[1], map->int_f[2]));
		g++;
	}
}
