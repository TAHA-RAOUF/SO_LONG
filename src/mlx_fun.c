/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:57:08 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/27 17:50:38 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_img(t_list *list, int h, int w)
{
	list->img_player = mlx_xpm_file_to_image(list->mlx, "textures/pac.xpm", &h,
			&w);
	list->img_exit = mlx_xpm_file_to_image(list->mlx, "textures/portal.xpm", &h,
			&w);
	list->img_wall = mlx_xpm_file_to_image(list->mlx, "textures/wall.xpm", &h,
			&w);
	list->img_floor = mlx_xpm_file_to_image(list->mlx, "textures/black.xpm", &h,
			&w);
	list->img_collectible = mlx_xpm_file_to_image(list->mlx,
			"textures/FOOD.xpm", &h, &w);
	if (!list->img_collectible || !list->img_player || !list->img_wall
		|| !list->img_exit || !list->img_floor)
	{
		fun_error("fail_mlx");
		destroy_images(list, 1);
	}
}

void	put_image(t_list *list)
{
	int	x;
	int	y;

	x = 0;
	while (list->map[x])
	{
		y = 0;
		while (list->map[x][y])
		{
			help_image(list, x, y);
			y++;
		}
		x++;
	}
}

int	destroy_images(t_list *list, int flag)
{
	if (list->img_wall)
		mlx_destroy_image(list->mlx, list->img_wall);
	if (list->img_floor)
		mlx_destroy_image(list->mlx, list->img_floor);
	if (list->img_player)
		mlx_destroy_image(list->mlx, list->img_player);
	if (list->img_collectible)
		mlx_destroy_image(list->mlx, list->img_collectible);
	if (list->img_exit)
		mlx_destroy_image(list->mlx, list->img_exit);
	if (list->window)
		mlx_destroy_window(list->mlx, list->window);
	if (list->mlx)
	{
		mlx_destroy_display(list->mlx);
		free(list->mlx);
	}
	free_mem(list->map);
	free(list);
	exit(flag);
	return (0);
}

void	new_pos(t_list *list)
{
	if (list->map[list->new_y][list->new_x] == '1')
	{
		return ;
	}
	if (list->map[list->new_y][list->new_x] == 'C')
		list->collectible--;
	if (list->map[list->new_y][list->new_x] == 'E' && list->collectible == 0)
		winner();
	list->map[list->new_y][list->new_x] = 'P';
	list->map[list->p_y][list->p_x] = '0';
	list->p_x = list->new_x;
	list->p_y = list->new_y;
	put_image(list);
}

void	fun_mlx(t_list *list)
{
	int	h;
	int	w;

	h = IMAGE_SIZE;
	w = IMAGE_SIZE;
	list->mlx = mlx_init();
	if (!list->mlx)
		return (fun_error("fail mlx"), fun_free(NULL, list->map, list));
	calcul_lenmap(list);
	list->window = mlx_new_window(list->mlx, list->height * h, list->width * w,
			"so_long");
	if (!list->window)
	{
		fun_error("fail mlx");
		destroy_images(list, 1);
	}
	mlx_img(list, h, w);
	put_image(list);
	position_player(list);
	mlx_hook(list->window, 2, 1L << 0, key_hook, list);
	mlx_hook(list->window, 17, 0, destroy_images, list);
	mlx_loop(list->mlx);
}
