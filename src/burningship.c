/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:15:13 by ehaggon           #+#    #+#             */
/*   Updated: 2019/08/29 17:23:39 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			burningship(void *mlx_ptr, void *win_ptr)
{
	double		pr;
	double		pi;
	double		newre;
	double		newim;
	double		oldre;
	double		oldim;
	hsv			color;
	rgb			color2;
	int			fin_color;
	FILE		*ptrfile;
	int			y;
	int			x;
	int			i;

	y = 0;
	ptrfile = fopen("mandelbrot.txt", "w");
	while (y < RES_Y)
	{
		x = 0;
		while (x < RES_X)
		{
			pr = 1.5 * (x - RES_X / 2) / (0.5 * zoom * RES_X) + move_x;
			pi = (y - RES_Y / 2) / (0.5 * zoom * RES_Y) + move_y;
			newre = 0;
			newim = 0;
			i = 0;
			while (i < ITER)
			{
				oldre = newre;
				oldim = newim;
				if (oldre < 0)
					oldre = -oldre;
				if (oldim < 0)
					oldim = -oldim;
				newre = oldre * oldre - oldim * oldim + pr;
				newim = 2 * oldre * oldim + pi;
				if ((newre * newre + newim * newim) > 4)
					break ;
				i++;
			}
			color.h = (i % 255);
			color.s = 255;
			color.v = 255 * (i < ITER);
			color2 = hsv2rgb(color);
			if (i < ITER)
			{
				color2.r = i * st_r % 255;
				color2.g = i * st_g % 255;
				color2.b = i * st_b % 255;
			}
			fin_color = creatergb((color2.r), (color2.g), (color2.b));
			fputs(ft_itoa(fin_color / 10000), ptrfile);
			fputs(" ", ptrfile);
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, fin_color);
			x++;
		}
		y++;
		fputs("\n", ptrfile);
	}
	fclose(ptrfile);
	return (0);
}
