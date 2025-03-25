/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:34:17 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/25 03:15:49 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#define MAX_LINES 100;

#include <stdlib.h>
#include <unistd.h>


typedef struct s_list
{
    char        **map;
    char     *content;
    int        *player;
    int         collectible;
    int         Exit;
    
}t_list;

int     ft_strlen1(char *str);
void	ft_lst_add_back(t_list **lst, char *value);
t_list  *new_node(char *content);
void    free_node(t_list *node);
char	**ft_split(char const *s, char c);
void    fun_error();
void	free_mem(char **array);
void    fun_free(char *str,char **double_array,t_list *list);




#endif