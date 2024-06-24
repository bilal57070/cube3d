/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:28:18 by bsafi             #+#    #+#             */
/*   Updated: 2024/06/24 18:29:57 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	move(t_map *map)
{
	if (map->stru.themove == 1)
		movefront(map);
	if (map->stru.themove == 2)
		moveleft(map);
	if (map->stru.themove == 3)
		moveback(map);
	if (map->stru.themove == 4)
		moveright(map);
	if (map->stru.themove == 5)
		exit(0);
	if (map->stru.themove == 6)
		turnleft(map);
	if (map->stru.themove == 7)
		turnright(map);
	if (map->stru.happen == 1)
	{
		map->stru.happen = 0;
		mlx_clear_window(map->mlx, map->win);
		raycasting(map);
	}
	return (0);
}

void	turnright(t_map *map)
{
	double	oldplanex;
	double	olddirx;

	map->stru.happen = 1;
	olddirx = map->stru.dX;
	oldplanex = map->stru.planeX;
	map->stru.dX = map->stru.dX * cos(-ROT_SPEED)
		- map->stru.dY * sin(-ROT_SPEED);
	map->stru.dY = olddirx * sin(-ROT_SPEED)
		+ map->stru.dY * cos(-ROT_SPEED);
	map->stru.planeX = map->stru.planeX * cos(-ROT_SPEED)
		- map->stru.planeY * sin(-ROT_SPEED);
	map->stru.planeY = oldplanex * sin(-ROT_SPEED)
		+ map->stru.planeY * cos(-ROT_SPEED);
}

void	turnleft(t_map *map)
{
	double	oldplanex;
	double	olddirx;

	map->stru.happen = 1;
	olddirx = map->stru.dX;
	oldplanex = map->stru.planeX;
	map->stru.dX = map->stru.dX * cos(ROT_SPEED)
		- map->stru.dY * sin(ROT_SPEED);
	map->stru.dY = olddirx * sin(ROT_SPEED)
		+ map->stru.dY * cos(ROT_SPEED);
	map->stru.planeX = map->stru.planeX * cos(ROT_SPEED)
		- map->stru.planeY * sin(ROT_SPEED);
	map->stru.planeY = oldplanex * sin(ROT_SPEED)
		+ map->stru.planeY * cos(ROT_SPEED);
}

void	moveleft(t_map *map)
{
	map->stru.happen = 1;
	if (map->map[(int)floor(map->stru.pX - map->stru.planeX * PLAYER_SPEED)]
		[(int)floor(map->stru.pY)] != '1')
		map->stru.pX -= map->stru.planeX * PLAYER_SPEED;
	if (map->map[(int)floor(map->stru.pX)]
		[(int)floor(map->stru.pY - map->stru.planeY * PLAYER_SPEED)] != '1')
		map->stru.pY -= map->stru.planeY * PLAYER_SPEED;
}

void	moveright(t_map *map)
{
	map->stru.happen = 1;
	if (map->map[(int)floor(map->stru.pX + map->stru.planeX * PLAYER_SPEED)]
		[(int)floor(map->stru.pY)] != '1')
		map->stru.pX += map->stru.planeX * PLAYER_SPEED;
	if (map->map[(int)floor(map->stru.pX)]
		[(int)floor(map->stru.pY + map->stru.planeY * PLAYER_SPEED)] != '1')
		map->stru.pY += map->stru.planeY * PLAYER_SPEED;
}
