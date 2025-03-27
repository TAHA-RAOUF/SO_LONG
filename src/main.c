/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:54:50 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/27 17:58:11 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

void	check_pass(char **str, t_list *list)
{
	int	i;
	int	j;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] != '0' && str[i][j] != '1' && str[i][j] != 'X')
			{
				return (fun_error("Map is Not Valid"), free_mem(str),
					fun_free(NULL, list->map, list));
			}
			j++;
		}
		i++;
	}
}

void	help_image(t_list *list, int x, int y)
{
	if (list->map[x][y] == '1')
		mlx_put_image_to_window(list->mlx, list->window,
			list->img_wall, y * 32, x * 32);
	else if (list->map[x][y] == '0')
		mlx_put_image_to_window(list->mlx, list->window,
			list->img_floor, y * 32, x * 32);
	else if (list->map[x][y] == 'P')
		mlx_put_image_to_window(list->mlx, list->window,
			list->img_player, y * 32, x * 32);
	else if (list->map[x][y] == 'C')
		mlx_put_image_to_window(list->mlx, list->window,
			list->img_collectible, y * 32, x * 32);
	else if (list->map[x][y] == 'E')
		mlx_put_image_to_window(list->mlx, list->window,
			list->img_exit, y * 32, x * 32);
}

char	*read_data(int fd, t_list *list)
{
	char	*line;
	char	*map;
	char	*tmp;

	if (fd == -1)
	{
		write(1, "error\n", 6);
		write(2, "INVALID FD", 11);
		free(list);
		exit(1);
	}
	line = get_next_line(fd);
	map = ft_strdup("");
	while (line)
	{
		tmp = map;
		map = ft_strjoin(map, line);
		free(tmp);
		free(line);
		if (!map)
			return (NULL);
		line = get_next_line(fd);
	}
	return (map);
}

void	check_all(t_list *list, int fd)
{
	char	*line;
	char	**tmp;

	line = NULL;
	line = read_data(fd, list);
	check_map(line, list);
	list->map = ft_split(line, '\n');
	free(line);
	check_rectangular(list);
	check_walls(list);
	check_intru(list);
	tmp = copy_map(list);
	position_player(list);
	flood_fill(tmp, list->p_x, list->p_y);
	check_pass(tmp, list);
	free_mem(tmp);
}

int	main(int ac, char **av)
{
	t_list	*list;
	int		fd;

	if (ac < 2)
	{
		fun_error("Arg Not Valid");
		exit(1);
	}
	check_name(av[1]);
	list = malloc(sizeof(t_list));
	initialize(list);
	fd = open(av[1], O_RDONLY);
	check_all(list, fd);
	fun_mlx(list);
	free_mem(list->map);
	free(list);
	close(fd);
	return (0);
}
