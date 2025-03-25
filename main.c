/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:54:50 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/25 18:21:04 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include "so_long.h"



char  *read_data(int fd)
{
    char    *line;
    char    *map;
    char    *tmp;
    
    if(fd == -1)
    {
        write(1,"error\n",6);
        write(2,"INVALID FD",11);
        exit(1);
    }
    line = get_next_line(fd);
    map = ft_strdup("");
    while(line)
    {
        tmp = map;
        map = ft_strjoin(map,line);
        free(tmp);
        free(line);
        if(!map)
            return NULL;
        line = get_next_line(fd);
    }
    return(map);
}


int main(int ac,char **av)
{
    t_list *list;
    char *line;
    list = malloc(sizeof(t_list));
    (void)ac;
    int fd = open(av[1], O_RDONLY);
    line = read_data(fd);
    check_map(line,list);
    list->map = ft_split(line,'\n');
    free(line);
    check_rectangular(list);
    check_walls(list);
    check_intru(list);
    free_mem(list->map);
    free(list);
    close(fd);
    return 0;
}





