/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:46:52 by isouaidi          #+#    #+#             */
/*   Updated: 2024/06/28 16:41:45 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac)
	{
		apl_pars(&map, av);
		map.mlx = mlx_init();
		initimg(&map);
		map.win = mlx_new_window(map.mlx, WIDTH, HEIGHT, "bekhey");
		map.stru.themove = 0;
		map.stru.happen = 0;
		findpos(&map);
		raycasting(&map);
		mlx_hook(map.win, 17, 0, &ft_exit2, &map);
		mlx_hook(map.win, 2, 1L << 0, &key_press, &map);
		mlx_hook(map.win, 3, 1L << 1, &key_release, &map);
		mlx_loop_hook(map.mlx, &move, &map);
		mlx_loop(map.mlx);
		free(map.mlx);
		free_all(&map);
	}
}
