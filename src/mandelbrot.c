/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:17:56 by ehaggon           #+#    #+#             */
/*   Updated: 2019/09/02 12:20:32 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot(t_shit *arg2)
{
	t_pnum		p;
	FILE		*ptrfile;
	int			i;
	t_coord		cur;

	cur.py = 0;
	ptrfile = fopen("mandelbrot.txt", "w");
	while (cur.py < RES_Y)
	{
		cur.px = 0;
		while (cur.px < RES_X)
		{
			p.pr = 1.5 * (cur.px - RES_X / 2) / (0.5 * arg2->zoom * RES_X) + arg2->move_x;
			p.pi = (cur.py - RES_Y / 2) / (0.5 * arg2->zoom * RES_Y) + arg2->move_y;
			i = mand_count(p);
			fputs(ft_itoa(coloring(i, arg2) / 10000), ptrfile);
			fputs(" ", ptrfile);
			mlx_pixel_put(arg2->mlx, arg2->win, cur.px, cur.py, coloring(i, arg2));
			cur.px++;
		}
		cur.py++;
		fputs("\n", ptrfile);
	}
	fclose(ptrfile);
	return (0);
}
