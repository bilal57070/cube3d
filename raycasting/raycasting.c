/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:47:28 by bsafi             #+#    #+#             */
/*   Updated: 2024/06/24 14:47:51 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	raycasting(t_map *map)
{
	map->stru.mapX = (int)map->stru.pX;
	map->stru.mapY = (int)map->stru.pY;
	map->stru.lineheight = 0;
	map->stru.x = 0;
	map->stru.wallX = 0;
	map->stru.raydX = 0;
	map->stru.raydY = 0;
	while (map->stru.x < WIDTH)
	{
		rayinit(map);
		raydist(map);
		dda(map);
		todraw(map);
		draw(map);
		drawsky(map);
		drawground(map);
		map->stru.x++;
	}
	mlx_put_image_to_window(map->mlx, map->win, map->img->img, 0, 0);
}

void	todraw(t_map *map)
{
	if (map->stru.side == 0)
		map->stru.perpwalld = (map->stru.sidedX - map->stru.deltadX);
	else
		map->stru.perpwalld = (map->stru.sidedY - map->stru.deltadY);
	if (map->stru.side)
		map->stru.wallX = map->stru.pX + map->stru.perpwalld * map->stru.raydX;
	else
		map->stru.wallX = map->stru.pY + map->stru.perpwalld * map->stru.raydY;
	map->stru.wallX -= floor(map->stru.wallX);
	map->stru.lineheight = HEIGHT / map->stru.perpwalld;
	map->stru.drawstart = 0;
	map->stru.drawend = 0;
	map->stru.drawstart = (int)-(map->stru.lineheight / 2) + HEIGHT / 2;
	map->stru.drawend = (int)map->stru.lineheight / 2 + HEIGHT / 2;
}

void	dda(t_map *map)
{
	while (map->stru.hit == 0)
	{
		if (map->stru.sidedX < map->stru.sidedY)
		{
			map->stru.sidedX += map->stru.deltadX;
			map->stru.mapX += map->stru.stepX;
			map->stru.side = 0;
		}
		else
		{
			map->stru.sidedY += map->stru.deltadY;
			map->stru.mapY += map->stru.stepY;
			map->stru.side = 1;
		}
		if (map->map[map->stru.mapX][map->stru.mapY] == '1')
			map->stru.hit = 1;
	}
}

void	raydist(t_map *map)
{
	if (map->stru.raydX < 0)
	{
		map->stru.stepX = -1;
		map->stru.sidedX = (map->stru.pX - map->stru.mapX) * map->stru.deltadX;
	}
	else
	{
		map->stru.stepX = 1;
		map->stru.sidedX = (map->stru.mapX + 1.0 - map->stru.pX)
			* map->stru.deltadX;
	}
	if (map->stru.raydY < 0)
	{
		map->stru.stepY = -1;
		map->stru.sidedY = (map->stru.pY - map->stru.mapY)
			* map->stru.deltadY;
	}
	else
	{
		map->stru.stepY = 1;
		map->stru.sidedY = (map->stru.mapY + 1.0 - map->stru.pY)
			* map->stru.deltadY;
	}
}

void	rayinit(t_map *map)
{
	map->stru.cameraX = 2 * map->stru.x / (double)WIDTH - 1;
	map->stru.raydX = map->stru.dX + map->stru.planeX * map->stru.cameraX;
	map->stru.raydY = map->stru.dY + map->stru.planeY * map->stru.cameraX;
	map->stru.mapX = (int)map->stru.pX;
	map->stru.mapY = (int)map->stru.pY;
	map->stru.hit = 0;
	if (map->stru.raydX == 0)
		map->stru.deltadX = 1e30;
	else
		map->stru.deltadX = fabs(1 / map->stru.raydX);
	if (map->stru.raydY == 0)
		map->stru.deltadY = 1e30;
	else
		map->stru.deltadY = fabs(1 / map->stru.raydY);
}
