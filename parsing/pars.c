/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:44:53 by isouaidi          #+#    #+#             */
/*   Updated: 2024/06/18 15:36:58 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	size_fd(t_map *map, char *av)
{
	int		fd;
	char	*line;

	map->size = 0;
	fd = open(av, O_RDONLY);
	line = get_next_line_bonus(fd);
	while (line)
	{
		map->size++;
		free(line);
		line = get_next_line_bonus(fd);
	}
	close(fd);
}

void	ft_strcopy(char *dst, const char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
}

void	recup(t_map *map, char *av)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	if (map->size < 1)
		ft_exit("Erros\nMap is Null");
	map->file = malloc(sizeof(char *) * (map->size * 2));
	if (!map->file)
		ft_exit("Error\nEmpty File");
	fd = open(av, O_RDONLY);
	line = get_next_line_bonus(fd);
	while (line)
	{
		map->file[i++] = ft_strdup(line);
		free(line);
		line = get_next_line_bonus(fd);
	}
	map->file[i] = NULL;
	close(fd);
}

void	check_name_cube(char *av)
{
	int	i;

	if (open(av, __O_DIRECTORY) != -1)
		ft_exit("Error\n Sorry it's a folder");
	if (open(av, O_RDONLY) == -1)
		ft_exit("Error\n Check your File");
	i = ft_strlen(av);
	i -= 4;
	if (i < 1)
		ft_exit("Error\n Check your File");
	if ((ft_strncmp(&av[i], ".cub", 4)) != 0)
		ft_exit("Error\n Check your .cub");
}
