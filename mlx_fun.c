/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:57:08 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/27 03:10:22 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void calcul_lenMap(t_list *list)
{
    int (height) ,width;

    width = 0;
    height = 0;
    while(list->map[width])
    {
       while(list->map[width][height])
            height++;
        width++;
    }
    list->width = width;
    list->height = height;
}


void mlx_img(t_list *list, int h, int w)
{
    list->img_player = mlx_xpm_file_to_image(list->mlx,"textures/pac.xpm",&h,&w);
    list->img_exit = mlx_xpm_file_to_image(list->mlx,"textures/portal.xpm", &h,&w);
    list->img_wall =  mlx_xpm_file_to_image(list->mlx,"textures/wall.xpm", &h,&w);
    list->img_floor =  mlx_xpm_file_to_image(list->mlx,"textures/black.xpm",&h,&w);
    list->img_collectible =  mlx_xpm_file_to_image(list->mlx,"textures/FOOD.xpm",&h,&w);

    // if(!list->img_collectible) // hhadi khaseha te9ade
}
void put_image(t_list *list)
{
    int (x), y;

    x = 0;
    while(list->map[x])
    {
        y = 0;
        while(list->map[x][y])
        {
            if(list->map[x][y] == '1')
                mlx_put_image_to_window(list->mlx,list->window,list->img_wall,y * 32,x * 32);
            if(list->map[x][y] == '0')
                mlx_put_image_to_window(list->mlx,list->window,list->img_floor,y * 32,x * 32);
            if(list->map[x][y] == 'P')
                mlx_put_image_to_window(list->mlx,list->window,list->img_player,y * 32, x * 32);
            if(list->map[x][y] == 'C')
                mlx_put_image_to_window(list->mlx,list->window,list->img_collectible,y * 32,x * 32);
            if(list->map[x][y] == 'E')
                mlx_put_image_to_window(list->mlx,list->window,list->img_exit,y * 32,x * 32);
            y++;
        }
        x++;
    }
}
 void    destroy_images(t_list *list,int flag)
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
    if(list->window)
        mlx_destroy_window(list->mlx,list->window);
    if(list->mlx)
    {
        mlx_destroy_display(list->mlx);
        free(list->mlx);
    }
    free_mem(list->map);
    free(list);
    exit(flag);
}




void winner()
{
    printf("win");
    exit(0);
}
void new_pos(t_list *list)
{
    if(list->map[list->new_y][list->new_x] == '1')
    {
        return;
    }
    printf("ana dk\n");
    if(list->map[list->new_y][list->new_x] == 'C')
        list->collectible--;
    if(list->map[list->new_y][list->new_x] == 'E' && list->collectible == 0)
        winner();
    list->map[list->new_y][list->new_x] = 'P';
    list->map[list->p_y][list->p_x] = '0';
    list->p_x = list->new_x;
    list->p_y = list->new_y;
    put_image(list);
}
// int key_hook(int key,t_list *list)
// {
//     if(key == KEY_ESC)
//         destroy_images(list,0);
//     if(key == KEY_UP)
//         list->new_y--;
//     if(key == KEY_DOWN)
//         list->new_y++;
//     if(key == KEY_RIGHT)
//         list->new_x++;
//     if(key == KEY_LEFT)
//         list->new_x--;
//     new_pos(list);
//     return 1;
// }

void fun_mlx(t_list *list)
{
    int h;
    int w;

    h = IMAGE_SIZE;
    w = IMAGE_SIZE;
    list->mlx = mlx_init();
    calcul_lenMap(list);
    if(!list->mlx)
        return;
    list->window = mlx_new_window(list->mlx,list->height * h,list->width * w,"so_long");
    mlx_img(list, h , w);
    put_image(list);
    position_player(list);
    
    mlx_key_hook(list->window,key_hook,list);
    mlx_loop(list->mlx);
}


