/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:08:34 by ehaggon           #+#    #+#             */
/*   Updated: 2019/08/29 20:15:33 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		sierpinskicarpet(void *mlx_ptr, void *win_ptr)
{
	long int		x;
	long int		y;
	long int		dim;
	long int		d;
	long long int	py;
	long long int	px;

	dim = dim_count();
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
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, (serp_coloring(d, dim)));
			x++;
		}
		y++;
	}
}
