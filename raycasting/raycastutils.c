/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:31:17 by bsafi             #+#    #+#             */
/*   Updated: 2024/06/28 17:05:36 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	initimg(t_map *map)
{
	map->img = ft_calloc(1, sizeof(t_img));
	map->img->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	map->img->addr = mlx_get_data_addr(map->img->img, &map->img->bits_per_pixel,
			&map->img->line_length, &map->img->endian);
	map->NO = ft_calloc(1, sizeof(t_img));
	map->NO->img = mlx_xpm_file_to_image(map->mlx, map->_no, &map->NO->width,
			&map->NO->height);
	if (!map->NO->img)
		ft_exit("Error\nBad path");
	map->NO->addr = mlx_get_data_addr(map->NO->img, &map->NO->bits_per_pixel,
			&map->NO->line_length, &map->NO->endian);
	map->SO = ft_calloc(1, sizeof(t_img));
	map->SO->img = mlx_xpm_file_to_image(map->mlx, map->_so, &map->SO->width,
			&map->SO->height);
	if (!map->SO->img)
		ft_exit("Error\nBad path");
	map->SO->addr = mlx_get_data_addr(map->SO->img, &map->SO->bits_per_pixel,
			&map->SO->line_length, &map->SO->endian);
	initimg2(map);
}

void	initimg2(t_map *map)
{
	map->W = ft_calloc(1, sizeof(t_img));
	map->W->img = mlx_xpm_file_to_image(map->mlx, map->_we, &map->W->width,
			&map->W->height);
	if (!map->W->img)
		ft_exit("Error\nBad path");
	map->W->addr = mlx_get_data_addr(map->W->img, &map->W->bits_per_pixel,
			&map->W->line_length, &map->W->endian);
	map->E = ft_calloc(1, sizeof(t_img));
	map->E->img = mlx_xpm_file_to_image(map->mlx, map->_ea, &map->E->width,
			&map->E->height);
	if (!map->E->img)
		ft_exit("Error\nBad path");
	map->E->addr = mlx_get_data_addr(map->E->img, &map->E->bits_per_pixel,
			&map->E->line_length, &map->E->endian);
}

int	choose_color(t_img *img, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	color = *(unsigned int *)pixel;
	return (color);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
