/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:54:53 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/27 16:49:31 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

int	count_line(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	free_mem(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	fun_error(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}

void	fun_free(char *str, char **double_array, t_list *list)
{
	if (str)
		free(str);
	if (double_array)
		free_mem(double_array);
	if (list)
		free(list);
	exit(1);
}

void	initialize(t_list *list)
{
	list->map = NULL;
	list->content = NULL;
	list->player = NULL;
	list->p_x = 0;
	list->p_y = 0;
	list->new_x = 0;
	list->new_y = 0;
	list->collectible = 0;
	list->exit = 0;
	list->move_count = 0;
	list->mlx = NULL;
	list->window = NULL;
	list->height = 0;
	list->width = 0;
	list->img_player = NULL;
	list->img_collectible = NULL;
	list->img_wall = NULL;
	list->img_exit = NULL;
	list->img_floor = NULL;
}
