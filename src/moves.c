/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 03:05:08 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/27 16:49:01 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mov_up(t_list *list)
{
	if (list->map[list->p_y - 1][list->p_x] == '1')
		return ;
	if (list->map[list->p_y - 1][list->p_x] == 'E')
	{
		if (list->collectible == 0)
			(winner(), destroy_images(list, 0));
		list->new_x = list->p_y - 1;
		list->new_y = list->p_x;
	}
	if (list->map[list->new_x][list->new_y] == 'P')
		list->map[list->p_y][list->p_x] = 'E';
	else
		list->map[list->p_y][list->p_x] = '0';
	list->p_y--;
	if (list->map[list->p_y][list->p_x] == 'C')
		list->collectible--;
	list->map[list->p_y][list->p_x] = 'P';
	print_moves();
}

void	mov_down(t_list *game)
{
	if (game->map[game->p_y + 1][game->p_x] == '1')
		return ;
	if (game->map[game->p_y + 1][game->p_x] == 'E')
	{
		if (game->collectible == 0)
			(winner(), destroy_images(game, 0));
		game->new_x = game->p_y + 1;
		game->new_y = game->p_x;
	}
	if (game->map[game->new_x][game->new_y] == 'P')
		game->map[game->p_y][game->p_x] = 'E';
	else
		game->map[game->p_y][game->p_x] = '0';
	game->p_y++;
	if (game->map[game->p_y][game->p_x] == 'C')
		game->collectible--;
	game->map[game->p_y][game->p_x] = 'P';
	game->move_count++;
	print_moves();
}

void	mov_left(t_list *game)
{
	if (game->map[game->p_y][game->p_x - 1] == '1')
		return ;
	if (game->map[game->p_y][game->p_x - 1] == 'E')
	{
		if (game->collectible == 0)
			(winner(), destroy_images(game, 0));
		game->new_x = game->p_y;
		game->new_y = game->p_x - 1;
	}
	if (game->map[game->new_x][game->new_y] == 'P')
		game->map[game->p_y][game->p_x] = 'E';
	else
		game->map[game->p_y][game->p_x] = '0';
	game->p_x--;
	if (game->map[game->p_y][game->p_x] == 'C')
		game->collectible--;
	game->map[game->p_y][game->p_x] = 'P';
	game->move_count++;
	print_moves();
}

void	mov_right(t_list *game)
{
	if (game->map[game->p_y][game->p_x + 1] == '1')
		return ;
	if (game->map[game->p_y][game->p_x + 1] == 'E')
	{
		if (game->collectible == 0)
			(winner(), destroy_images(game, 0));
		game->new_x = game->p_y;
		game->new_y = game->p_x + 1;
	}
	if (game->map[game->new_x][game->new_y] == 'P')
		game->map[game->p_y][game->p_x] = 'E';
	else
		game->map[game->p_y][game->p_x] = '0';
	game->p_x++;
	if (game->map[game->p_y][game->p_x] == 'C')
		game->collectible--;
	game->map[game->p_y][game->p_x] = 'P';
	game->move_count++;
	print_moves();
}

int	key_hook(int keycode, t_list *game)
{
	if (keycode == 65307)
		destroy_images(game, 0);
	if (keycode == 119 || keycode == KEY_UP)
		mov_up(game);
	else if (keycode == 115 || keycode == KEY_DOWN)
		mov_down(game);
	else if (keycode == 97 || keycode == KEY_LEFT)
		mov_left(game);
	else if (keycode == 100 || keycode == KEY_RIGHT)
		mov_right(game);
	mlx_clear_window(game->mlx, game->window);
	put_image(game);
	return (0);
}
