/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:54:50 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/25 03:24:44 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include "so_long.h"


int     count_line(int fd)
{
    int len;
    char *line;

    len = 0;
    lseek(fd,0,SEEK_SET);
    while((line = get_next_line(fd))!= NULL)
    {
        len++;
    }
    return(len);
}
void fun_error()
{
    write(2,"Error\n",6);
    write(2,"Invalid Map",12);
    exit(1);
}
void fun_free(char *str,char **double_array,t_list *list)
{
    if(str)
        free(str);
    if(double_array)
        free_mem(double_array);
    if(list)
        free (list);
    fun_error();
}
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

void check_map(char *str,t_list *list)
{
    int i = 0;

    if(!str)
        fun_free(str,NULL,list);
    if(str[i] == '\n')
        fun_free(str,NULL,list);
    while(str[i])
    {
        if(str[i] != '1' && str[i] != '0' && str[i] != 'C' && str[i] != 'E' && str[i] != '\n' && str[i] != 'P')
        {
            fun_free(str,NULL,list);
        }
        if(str[i] == '\n')
        {
            if(str[i + 1] == '\n' || str[i + 1] == '\0')
                fun_free(str,NULL,list);
        } 
        i++;
    }
}
void    check_rectangular(t_list *list)
{
    int i;

    i = 0;
    size_t len = ft_strlen(list->map[i]);

    while(list->map[i])
    {
        if(len != ft_strlen(list->map[i]))
           fun_free(NULL,list->map,list);
        i++;
    }
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
    free_mem(list->map);
    free(list);
    close(fd);
    return 0;        
    
}





