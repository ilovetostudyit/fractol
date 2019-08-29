/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:08:34 by ehaggon           #+#    #+#             */
/*   Updated: 2019/08/29 17:13:32 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		sierpinskicarpet(void *mlx_ptr, void *win_ptr)
{
	long int		x;
	long int		y;
	long int		dim;
	long int		d;
	hsv				color;
	rgb				color2;
	int				fin_color;
	long long int	py;
	long long int	px;

	x = 0;
	dim = 1;
	while (x < ITER)
	{
		dim *= 3;
		x++;
	}
	x = 0;
	y = 0;
	while (y < RES_Y)
	{
		x = 0;
		while (x < RES_X)
		{
			px = x * zoom + move_x;
			py = y * zoom + move_y;
			d = dim / 3;
			while (d != 0)
			{
				if (((px % (d * 3)) / d == 1 && (py % (d * 3)) / d == 1))
					break ;
				d = d / 3;
			}
			color.h = (d % 255);
			color.s = 255;
			color.v = 255 * (d < dim / 3);
			color2 = hsv2rgb(color);
			if (d < dim / 3)
			{
				color2.r = d * st_r % 255;
				color2.g = d * st_g % 255;
				color2.b = d * st_b % 255;
			}
			fin_color = creatergb((color2.r), (color2.g), (color2.b));
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, fin_color);
			x++;
		}
		y++;
	}
}
