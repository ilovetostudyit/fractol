/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:38:18 by ehaggon           #+#    #+#             */
/*   Updated: 2019/08/08 15:19:01 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include <stdio.h>

void draw_circle(void *mlx_ptr, void *win_ptr, float x, float y, float r)
{
    float min_x;
    float min_y;

    min_x = x - r;

    while (min_x <= (x + r))
    {
        min_y = r*r - (min_x - x)*(min_x - x);
        min_y = sqrt(min_y) + y;
        mlx_pixel_put(mlx_ptr, win_ptr, min_x, min_y, 0xFFFFFF);
        /*mlx_pixel_put(mlx_ptr, win_ptr, min_y, min_x, 0xFFFFFF);*/
        min_y = 2*y - min_y;
        mlx_pixel_put(mlx_ptr, win_ptr, min_x, min_y, 0xFFFFFF);
        //mlx_pixel_put(mlx_ptr, win_ptr, min_y, min_x, 0xFFFFFF);
        min_x = min_x + 0.01;
    }
    if (r > 1)
    {
        r = r - r/10;
        draw_circle(mlx_ptr, win_ptr, x, y, r);
    }
}

int main()
{
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
    draw_circle(mlx_ptr, win_ptr, 250, 250, 1000);
    mlx_loop(mlx_ptr);
}
