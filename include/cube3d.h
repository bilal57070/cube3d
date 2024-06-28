/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:31:10 by isouaidi          #+#    #+#             */
/*   Updated: 2024/06/28 17:03:50 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include "mlx.h"

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line_bonus.h"

# define TOO_MUCH_TEXTURES "Error \nThere is too much textures" 
# define TOO_MUCH_COLORS "Error \nThere is too much colors"
# define COLORS_ERREUR "Error \nColors take integer between 0 and 255"
# define NBR_COLORS "Error \n Three numbers are required for colors"
# define PLAYER_SPEED 0.09
# define ROT_SPEED 0.01
# define PI 3.14159265359
# define WIDTH 1000
# define HEIGHT 600


typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

    int		width;
	int		height;
}       t_img;

typedef struct s_stru
{
	double	cameraX;
	double	raydX;
	double	raydY;

	double sidedX;
    double sidedY;

	double deltadX;
    double deltadY;
    double perpwalld;
	double lineheight;

	int	hit;


	void	*ground;
	void	*wall;
	double	time;
	double	movespeed;
	double	rotspeed;
	double	pX;
	double	pY;
	double	dX;
	double	dY;
	int		mapX;
	int		mapY;
	int		themove;
	int		happen;
	int		drawstart;
	int		drawend;
	double	wallX;
	int		x;
	double	planeX;
	double	planeY;
	int		stepX;
	int		stepY;
	double	turn;
	int		side;
}	t_stru;

typedef struct s_map
{
	char	**file;
	int		size;
	char	**text;
	char	*_no;
	char	*_so;
	char	*_ea;
	char	*_we;
	char	**colors;
	char	**map;
	char	*f_col;
	char	*c_col;
	int		cont_int;
	int		*int_f;
	int		*int_c;
	int		no;
	size_t	count;
	int		so;
	int		es;
	int		we;
	int		w;
	int		e;
	int		f;
	int		c;
	void	*win;
	void	*mlx;
	t_stru	stru;
	t_img	*img;

	t_img	*NO;
	t_img	*SO;
	t_img	*E;
	t_img	*W;
}	t_map;


int		main();

//Pars :
void	size_fd(t_map *map, char *av);
void	recup(t_map *map, char *av);
void	ft_strcopy(char *dst, const char *src);
void	check_name_cube(char *av);
int		tablen(char **tab);
void	inti_var(t_map *map);
void	print_char_tab(char **tab);
void	check_texture(t_map *map, int i);
void	ft_exit(char *str);
void	check_colors(t_map *map, int i, int j);
char	*without_space(char *s);
void	tab_col(t_map *map, int i, int j);
void	convert(char **str, int *col);
void	check_int_col(t_map *map);
int		count_tab(char **tab);
void	recup_map(t_map *map, int i, int j, int f);
void	first_sapce(t_map *nmap);
char	*modif_ft_strdup(const char *src);
void	check_all_map(t_map *map, int n, int w, int s);
void	null_map(char **tab);
bool	count_colors(t_map *map);
bool	is_map(char *s);
bool	is_texture(char *s, t_map *map);
bool	count_text(t_map *map);
void	check_char_aut(t_map *map);
void	apl_pars(t_map *map, char **av);
void	free_all(t_map *map);
void	free_tab(char **tab);
char	*free_strjoins2(char *s1, char *s2);
char	*free_strjoins1(char *s1, char *s2);
char	*textmap(char **tab, char a, char b, int i);
void	rctext(t_map *map);


//raycasting
void	la2d(t_map *map, t_stru *stru);
void	cpymap(char *av, t_map *map);
int		countmape(char *av);
void	raycasting(t_map *map);
void 	draw_line(t_map *map, int x0, int y0, int x1, int y1, int color);
int		choose_color(t_img *img, int x, int y);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		ft_exit2(t_map *map);
int		key_press(int keycode, t_map *map);
int		move(t_map *map);
void	movefront(t_map *map);
void	moveback(t_map *map);
int		key_release(int	keycode, t_map *map);
void	draw(t_map	*map);
void	drawsky(t_map *map);
void	drawground(t_map *map);
void	moveright(t_map *map);
void	moveleft(t_map *map);
void	turnleft(t_map *map);
void	turnright(t_map *map);
void	findpos(t_map *map);
void	findpos2(t_map *map, int i, int j);
void	findpos3(t_map *map, int i, int j);
void	initimg(t_map *map);
void	drawnorth(t_map *map);
void	drawsouth(t_map *map);
void	drawest(t_map *map);
void	drawwest(t_map *map);
int		create_trgb(int t, int r, int g, int b);
void	todraw(t_map *map);
void	dda(t_map *map);
void	rayinit(t_map *map);
void	raydist(t_map *map);
void	initimg2(t_map *map);

#endif