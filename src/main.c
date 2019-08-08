/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:38:18 by ehaggon           #+#    #+#             */
/*   Updated: 2019/08/08 15:53:03 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int ft_zoom(int button, argum argum2)
{
    if (button == MOUSE_UP)
    {
        ft_putnbr(argum2.zoom);
        //julia2(argum2.mlx, argum2.win);
    }
    else if (button == MOUSE_DOWN)
    {
        ft_putstr("I am free");
    }
    return(0);
}

int ft_usage()
{
    ft_putstr("USAGE: program draws these fractals:\n");
    ft_putstr("Mandelbrot\n");
    ft_putstr("Julia\n");
    ft_putstr("Sierpinski\n");
    return(0);
}

int ft_check_args(char *str)
{
    if (!(ft_strcmp(str, "Julia")))
       return (1);
    else if (!(ft_strcmp(str, "Mandelbrot")))
       return (2);
    else if (!(ft_strcmp(str, "Sierpinski")))
      return (3);
    return(0);
}

int main(int argc, char **argv)
{
    int fr_num;
    int zoom;
    void *mlx_ptr;
    void *win_ptr;
    argum *argum2;

    argum2 = (argum*)malloc(sizeof(argum));
    
    //c.x = -0.7;
    //c.y = 0.27015;
    zoom = 0;
    if ((argc != 2) || (!(fr_num = ft_check_args(argv[1]))))
        return(ft_usage());
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, RES_X, RES_Y, argv[1]);
    if (fr_num == 3)
    {
        SiepinskiCarpetFill(mlx_ptr, win_ptr, RES_X, RES_Y);
    }
    else if (fr_num == 1)
    {
        julia2(mlx_ptr,win_ptr);
    }
    else if (fr_num == 2)
    {
        mandelbrot(mlx_ptr, win_ptr);
    }
    argum2->zoom = zoom;
    argum2->mlx = mlx_ptr;
    argum2->win = win_ptr;
    mlx_mouse_hook(win_ptr, ft_zoom, argum2);
    mlx_loop(mlx_ptr);
    return(0);
}