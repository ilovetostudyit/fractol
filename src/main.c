/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:38:18 by ehaggon           #+#    #+#             */
/*   Updated: 2019/08/06 11:30:18 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
    void *mlx_ptr;
    void *win_ptr;  
    complex c;
    
    c.x = -0.7;
    c.y = 0.27015;
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
        //juliaSet(mlx_ptr, win_ptr,c, LIM_R, ITER);
        julia2(mlx_ptr,win_ptr);
    }
    mlx_loop(mlx_ptr);
    return(0);
}