/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:38:00 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/27 17:55:29 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

int	size_array(t_list *list)
{
	int	count;

	count = 0;
	while (list->map[count])
		count++;
	return (count);
}

char	**copy_map(t_list *list)
{
	char	**map;
	int		i;
	int		j;

	map = malloc(sizeof(char *) * (size_array(list) + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (list->map[i])
	{
		map[i] = malloc(sizeof(char) * (ft_strlen(list->map[i]) + 1));
		if (!map[i])
			return (NULL);
		j = 0;
		while (list->map[i][j])
		{
			map[i][j] = list->map[i][j];
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	position_player(t_list *list)
{
	int	i;
	int	j;

	i = 0;
	while (list->map[i])
	{
		j = 0;
		while (list->map[i][j])
		{
			if (list->map[i][j] == 'P')
			{
				list->p_x = j;
				list->p_y = i;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
}

void	calcul_lenmap(t_list *list)
{
	int	height;
	int	width;

	width = 0;
	height = 0;
	while (list->map[width])
	{
		while (list->map[width][height])
			height++;
		width++;
	}
	list->width = width;
	list->height = height;
}
