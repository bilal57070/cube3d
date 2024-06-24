/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:26:05 by bsafi             #+#    #+#             */
/*   Updated: 2024/06/24 19:39:42 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw(t_map	*map)
{
	if (map->stru.side == 0 && map->stru.stepX == -1)
		drawnorth(map);
	if (map->stru.side == 0 && map->stru.stepX == 1)
		drawsouth(map);
	if (map->stru.side == 1 && map->stru.stepY == 1)
		drawest(map);
	if (map->stru.side == 1 && map->stru.stepY == -1)
		drawwest(map);
}

void	drawwest(t_map *map)
{
	int		y;
	double	y_texture;
	double	step;
	t_img	*texture;

	texture = map->W;
	y_texture = 0;
	step = (double)((double)texture->height
			/ (double)(map->stru.drawend - map->stru.drawstart));
	if (map->stru.drawstart < 0)
	{
		y_texture = step * map->stru.drawstart * -1;
		map->stru.drawstart = 0;
	}
	y = map->stru.drawstart;
	while (y < map->stru.drawend)
	{
		if (y >= HEIGHT)
			break ;
		my_mlx_pixel_put(map->img, map->stru.x, y, choose_color(texture,
				map->stru.wallX * (double)texture->width, y_texture));
		y++;
		y_texture += step;
	}
}

void	drawest(t_map *map)
{
	int		y;
	double	y_texture;
	double	step;
	t_img	*texture;

	texture = map->E;
	y_texture = 0;
	step = (double)((double)texture->height
			/ (double)(map->stru.drawend - map->stru.drawstart));
	if (map->stru.drawstart < 0)
	{
		y_texture = step * map->stru.drawstart * -1;
		map->stru.drawstart = 0;
	}
	y = map->stru.drawstart;
	while (y < map->stru.drawend)
	{
		if (y >= HEIGHT)
			break ;
		my_mlx_pixel_put(map->img, map->stru.x, y, choose_color(texture,
				map->stru.wallX * (double)texture->width, y_texture));
		y++;
		y_texture += step;
	}
}

void	drawsouth(t_map *map)
{
	int		y;
	double	y_texture;
	double	step;
	t_img	*texture;

	texture = map->SO;
	y_texture = 0;
	step = (double)((double)texture->height
			/ (double)(map->stru.drawend - map->stru.drawstart));
	if (map->stru.drawstart < 0)
	{
		y_texture = step * map->stru.drawstart * -1;
		map->stru.drawstart = 0;
	}
	y = map->stru.drawstart;
	while (y < map->stru.drawend)
	{
		if (y >= HEIGHT)
			break ;
		my_mlx_pixel_put(map->img, map->stru.x, y, choose_color(texture,
				map->stru.wallX * (double)texture->width, y_texture));
		y++;
		y_texture += step;
	}
}

void	drawnorth(t_map *map)
{
	int		y;
	double	y_texture;
	double	step;
	t_img	*texture;

	texture = map->NO;
	y_texture = 0;
	step = (double)((double)texture->height
			/ (double)(map->stru.drawend - map->stru.drawstart));
	if (map->stru.drawstart < 0)
	{
		y_texture = step * map->stru.drawstart * -1;
		map->stru.drawstart = 0;
	}
	y = map->stru.drawstart;
	while (y < map->stru.drawend)
	{
		if (y >= HEIGHT)
			break ;
		my_mlx_pixel_put(map->img, map->stru.x, y, choose_color(texture,
				map->stru.wallX * (double)texture->width, y_texture));
		y++;
		y_texture += step;
	}
}
