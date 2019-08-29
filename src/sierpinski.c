/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:08:34 by ehaggon           #+#    #+#             */
/*   Updated: 2019/08/29 20:29:05 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		sierpinskicarpet(void *mlx_ptr, void *win_ptr)
{
	long int		dim;
	long int		d;
	t_coord			cd;
	t_coord			cur;

	dim = dim_count();
	cur.py = 0;
	while (cur.py < RES_Y)
	{
		cur.px = 0;
		while (cur.px < RES_X)
		{
			cd.px = cur.px * zoom + move_x;
			cd.py = cur.py * zoom + move_y;
			d = dim / 3;
			d = d_count(d, cd);
			mlx_pixel_put(mlx_ptr, win_ptr, cur.px, cur.py, (srp_col(d, dim)));
			cur.px++;
		}
		cur.py++;
	}
}
