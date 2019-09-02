/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:08:34 by ehaggon           #+#    #+#             */
/*   Updated: 2019/09/02 12:29:35 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		sierpinskicarpet(t_shit *arg2)
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
			cd.px = cur.px * arg2->zoom + arg2->move_x;
			cd.py = cur.py * arg2->zoom + arg2->move_y;
			d = dim / 3;
			d = d_count(d, cd);
			mlx_pixel_put(arg2->mlx, arg2->win, cur.px, cur.py,
			(srp_col(d, dim, arg2)));
			cur.px++;
		}
		cur.py++;
	}
}
