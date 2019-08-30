/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:15:13 by ehaggon           #+#    #+#             */
/*   Updated: 2019/08/30 16:51:17 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			burningship(t_shit *argum2)
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
			p.pr = 1.5 * (cur.px - RES_X / 2) / (0.5 * argum2->zoom * RES_X) + argum2->move_x;
			p.pi = (cur.py - RES_Y / 2) / (0.5 * argum2->zoom * RES_Y) + argum2->move_y;
			i = burning_count(p);
			fputs(ft_itoa(coloring(i, argum2) / 10000), ptrfile);
			fputs(" ", ptrfile);
			mlx_pixel_put(argum2->mlx, argum2->win, cur.px, cur.py, coloring(i, argum2));
			cur.px++;
		}
		cur.py++;
		fputs("\n", ptrfile);
	}
	fclose(ptrfile);
	return (0);
}
