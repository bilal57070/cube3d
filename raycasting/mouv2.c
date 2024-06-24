/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:29:21 by bsafi             #+#    #+#             */
/*   Updated: 2024/06/24 17:59:32 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	movefront(t_map *map)
{
	map->stru.happen = 1;
	if (map->map[(int)floor(map->stru.pX + map->stru.dX * PLAYER_SPEED)]
		[(int)floor(map->stru.pY)] != '1')
		map->stru.pX += map->stru.dX * PLAYER_SPEED;
	if (map->map[(int)floor(map->stru.pX)]
		[(int)floor(map->stru.pY + map->stru.dY * PLAYER_SPEED)] != '1')
		map->stru.pY += map->stru.dY * PLAYER_SPEED;
}

void	moveback(t_map *map)
{
	map->stru.happen = 1;
	if (map->map[(int)floor(map->stru.pX - map->stru.dX * PLAYER_SPEED)]
		[(int)floor(map->stru.pY)] != '1')
		map->stru.pX -= map->stru.dX * PLAYER_SPEED;
	if (map->map[(int)floor(map->stru.pX)]
		[(int)floor(map->stru.pY - map->stru.dY * PLAYER_SPEED)] != '1')
		map->stru.pY -= map->stru.dY * PLAYER_SPEED;
}

int	key_press(int keycode, t_map *map)
{
	if (keycode == 119)
		map->stru.themove = 1;
	else if (keycode == 97)
		map->stru.themove = 2;
	else if (keycode == 115)
		map->stru.themove = 3;
	else if (keycode == 100)
		map->stru.themove = 4;
	else if (keycode == 65307)
		map->stru.themove = 5;
	else if (keycode == 65361)
		map->stru.themove = 6;
	else if (keycode == 65363)
		map->stru.themove = 7;
	return (0);
}

int	key_release(int keycode, t_map *map)
{
	if (keycode)
		map->stru.themove = 0;
	return (0);
}

int	ft_exit2(void)
{
	exit(0);
	return (0);
}
