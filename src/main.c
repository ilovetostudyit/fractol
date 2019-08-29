/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:38:18 by ehaggon           #+#    #+#             */
/*   Updated: 2019/08/29 15:03:42 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_track(int x, int y, void *param)
{
    //printf("button = %d\n", button);
    if (fr_num == 1 && mouse_off)
    {
        param = 0;
        if (x >=0 && x <= RES_X && y>=0 && y <=RES_Y)
        {
            cRe = (double)x * -0.002205;
            cIm = (double)y * 0.00081;
            ft_function(fr_num);
        }
    }
    return(0);
}

int ft_form(int button)
{
    if (button == KEY_UP)
    {
        move_y = move_y - 0.1;
    }
    else if (button == KEY_DOWN)
    {
        move_y= move_y + 0.1;
    }
    else if (button == KEY_LEFT)
    {
        move_x = move_x - 0.1;
    }
    else if (button == KEY_RIGHT)
    {
        move_x = move_x + 0.1;
    }
    else if (button == 18 || button == 19 || button == 20)
    {
        fr_num = button - 17;
        clear_image(mlx, win);
    }
    else if (button == 21)
    {
        if (st_r < 9)
            st_r++;
        else
            st_r = 0;
    }
    else if (button == 22)
    {
        if (st_g < 9)
            st_g++;
        else
            st_g = 0;
    }
    else if (button == 23)
    {
        if (st_b < 9)
            st_b++;
        else
            st_b = 0;
    }
    else if (button == KEY_CLEAR)
    {
        clear_image(mlx, win);
    }
    else if (button == KEY_M)
    {
        if (mouse_off)
            mouse_off = 0;
        else
            mouse_off = 1;
        
    }
    ft_function(fr_num);
    return(0);
}

void clear_image(void *mlx_ptr, void *win_ptr)
{
    int x;
    int y;
    
    x = 0;
    y = 0;
    while (x < RES_X)
    {
        while (y < RES_Y)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x000000);
            y++;
        }
        y = 0;
        x++;
    }
}

void ft_function(int fr_num)
{
     if (fr_num == 4)
    {
        SiepinskiCarpetFill(mlx, win);
    }
    else if (fr_num == 1)
    {
        julia2(mlx, win);
    }
    else if (fr_num == 2)
    {
        mandelbrot(mlx, win);
    }
    else if (fr_num == 3)
    {
        burningship(mlx, win);
    }
}

int ft_zoom(int button)
{
    //zoom = 0;
    if (button == MOUSE_UP)
    {
        zoom = zoom + 0.1;
        clear_image(mlx, win);
        ft_function(fr_num);
        //julia2(argum2.mlx, argum2.win);
    }
    else if (button == MOUSE_DOWN)
    {
        if (zoom > 0)
        {
            zoom = zoom - 0.1;
            //clear_image(mlx, win);
            ft_function(fr_num);
        }
    }
    return(0);
}

int ft_usage()
{
    ft_putstr("USAGE: program draws these fractals:\n");
    ft_putstr("Mandelbrot\n");
    ft_putstr("Julia\n");
    ft_putstr("Burningship\n");
    ft_putstr("Sierpinski\n");
    return(0);
}

int ft_check_args(char *str)
{
    if (!(ft_strcmp(str, "Julia")))
       return (1);
    else if (!(ft_strcmp(str, "Mandelbrot")))
       return (2);
    else if (!(ft_strcmp(str, "Burningship")))
      return (3);
    else if (!(ft_strcmp(str, "Sierpinski")))
      return (4);
    return(0);
}

int main(int argc, char **argv)
{
    t_argum *argum2;

    mouse_off = 1;
    cRe = -0.7;
    cIm = 0.27015;
    st_r = 0;
    st_b = 0;
    st_g = 9;
    move_x = -0.5;
    move_y = 0;
    argum2 = (t_argum*)malloc(sizeof(t_argum));
    zoom = 1;
    if ((argc != 2) || (!(fr_num = ft_check_args(argv[1]))))
        return(ft_usage());
    argum2->mlx = mlx_init();
    mlx = argum2->mlx;
    
    argum2->win = mlx_new_window(argum2->mlx, RES_X, RES_Y, argv[1]);
    win = argum2->win;
    ft_function(fr_num);
    argum2->zoom = zoom;
    mlx_hook(argum2->win, 6, (1L << 6), ft_track, argum2);
    mlx_mouse_hook(argum2->win, ft_zoom, argum2);
    mlx_key_hook(argum2->win, ft_form, argum2);
    mlx_loop(argum2->mlx);
    return(0);
}