/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:34:17 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/27 17:44:44 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MAX_LINES 100;
# define IMAGE_SIZE 32;

# define KEY_W 119
# define KEY_UP 65362
# define KEY_S 115
# define KEY_DOWN 65364
# define KEY_A 97
# define KEY_LEFT 65361
# define KEY_D 100
# define KEY_RIGHT 65363
# define KEY_ESC 65307

# include "/usr/include/minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char	**map;
	char	*content;
	int		*player;
	void	*img_player;
	void	*img_collectible;
	void	*img_wall;
	void	*img_exit;
	void	*img_floor;
	void	*mlx;
	void	*window;
	int		exit;
	int		p_x;
	int		p_y;
	int		new_x;
	int		new_y;
	int		collectible;
	int		move_count;
	int		height;
	int		width;

}			t_list;

int			ft_strlen1(char *str);
void		ft_lst_add_back(t_list **lst, char *value);
t_list		*new_node(char *content);
void		free_node(t_list *node);
char		**ft_split(char const *s, char c);
void		fun_error(char *msg);
void		free_mem(char **array);
void		fun_free(char *str, char **double_array, t_list *list);
int			count_line(char **array);
void		check_walls(t_list *list);
void		check_map(char *str, t_list *list);
void		check_rectangular(t_list *list);
void		check_intru(t_list *list);
void		check_name(char *str);
char		**copy_map(t_list *list);
void		flood_fill(char **map, int x, int y);
void		help_image(t_list *list, int x, int y);
void		calcul_lenmap(t_list *list);
void		position_player(t_list *list);
void		initialize(t_list *list);
void		fun_mlx(t_list *list);
int			key_hook(int key, t_list *game);
int			destroy_images(t_list *list, int flag);
int			count_characters(t_list *list, char c);
void		winner(void);
void		put_image(t_list *list);
void		ft_putchar(char c);
void		ft_putnbr(int nb);
void		print_moves(void);

#endif