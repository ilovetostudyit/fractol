/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:21:44 by ehaggon           #+#    #+#             */
/*   Updated: 2019/08/29 17:28:44 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			julia2(void *mlx_ptr, void *win_ptr)
{
	double		newre;
	double		newim;
	double		oldre;
	double		oldim;
	hsv			color;
	rgb			color2;
	int			fin_color;
	FILE		*ptrfile;
	int			x;
	int			y;
	int			i;
	int			col_ra;

	ptrfile = fopen("julia.txt", "w");
	x = 0;
	y = 0;
	col_ra = 0;
	while (y < RES_Y)
	{
		while (x < RES_X)
		{
			newre = 1.5 * (x - RES_X / 2) / (0.5 * zoom * RES_X) + move_x;
			newim = (y - RES_Y / 2) / (0.5 * zoom * RES_Y) + move_y;
			i = 0;
			while (i < ITER)
			{
				oldre = newre;
				oldim = newim;
				newre = oldre * oldre - oldim * oldim + cRe;
				newim = 2 * oldre * oldim + cIm;
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
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, fin_color);
			fputs(ft_itoa(fin_color / (RES_X * RES_Y)), ptrfile);
			fputs(" ", ptrfile);
			x++;
		}
		x = 0;
		fputs("\n", ptrfile);
		y++;
	}
	fclose(ptrfile);
	return (0);
}
