/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_text2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:21:11 by isouaidi          #+#    #+#             */
/*   Updated: 2024/06/28 17:01:54 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*textmap(char **tab, char a, char b, int i)
{
	int		j;
	int		c;
	char	*str;

	while (tab[++i])
	{
		if (tab[i][0] == a && tab[i][1] == b)
		{
			j = 2;
			c = 0;
			while (tab[i][j] == ' ')
				j++;
			str = malloc(sizeof(char) * (ft_strlen(tab[i]) - j + 1));
			while (tab[i][j])
			{
				if (tab[i][j] == ' ')
					j++;
				else 
					str[c++] = tab[i][j++];
			}
			str[c] = '\0';
			return (str);
		}
	}
	return (NULL);
}

void	rctext(t_map *map)
{
	map->_no = textmap(map->text, 'N', 'O', -1);
	map->_ea = textmap(map->text, 'E', 'A', -1);
	map->_so = textmap(map->text, 'S', 'O', -1);
	map->_we = textmap(map->text, 'W', 'E', -1);
}
