/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:53:05 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/27 01:39:12 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"


void	check_walls(t_list *list)
{
	int	i;
	int	j;
	int	len;
	int	c_line;

	i = -1;
	len = ft_strlen(list->map[0]);
	c_line = count_line(list->map);
	while (list->map[++i])
	{
		if (i == 0 || i == c_line - 1)
		{
			j = -1;
			while (list->map[i][++j])
				if (list->map[i][j] != '1')
					return (fun_error("wall error"), fun_free(NULL, list->map, list));
		}
		else if (list->map[i][0] != '1' || list->map[i][len - 1] != '1')
			return (fun_error("wall error"), fun_free(NULL, list->map, list));
	}
}

void check_map(char *str,t_list *list)
{
    int i = 0;

    if(!str)
        return (fun_error("Map Error"), fun_free(str, list->map, list));
    if(str[i] == '\n')
        return (fun_error("Map Error"), fun_free(str, list->map, list));
    while(str[i])
    {
        if(str[i] != '1' && str[i] != '0' && str[i] != 'C' && str[i] != 'E' && str[i] != '\n' && str[i] != 'P')
        {
            return (fun_error("Map Error"), fun_free(str, list->map, list));
        }
        if(str[i] == '\n')
        {
            if(str[i + 1] == '\n' || str[i + 1] == '\0')
            return (fun_error("Map Error"), fun_free(str, list->map, list));
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
        {
            fun_error("not rectangular");
           fun_free(NULL,list->map,list);
        }
        i++;
    }
}
void check_name(char *str)
{
    int len;

    len = ft_strlen(str);
    if(len <= 4 || str[len - 1] != 'r' || str[len - 2] != 'e' || str[len - 3] != 'b' || str[len -4 ]!= '.' || str[len - 5] == '/')
    {
        fun_error("Invalid Name");
        exit(1);
    }
}
void check_intru(t_list *list)
{
    int i = 0;
    int count = 0;
    int j;
    while(list->map[i])
    {
        j = 0;
        while(list->map[i][j])
        {
            if(list->map[i][j] == 'E' || list->map[i][j] == 'P')
            {   
                count++;
            }
            j++;   
        }
        i++;
    }
    if(count != 2)
        return(fun_error("Prbl Player/exit"), fun_free(NULL,list->map,list));
    count = 0;
    i = 0;
    while(list->map[i])
    {
        j = 0;
        while(list->map[i][j])
        {
            if(list->map[i][j] == 'C')
            {   
                count++;
            }
            j++;   
        }
        i++;
    }
    if(count < 1)
         return(fun_error("no Collectible"), fun_free(NULL,list->map,list));
    list->collectible = count;
}
