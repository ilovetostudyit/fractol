/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:15:13 by ehaggon           #+#    #+#             */
/*   Updated: 2019/08/30 13:51:13 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			burningship(void *mlx_ptr, void *win_ptr)
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
			p.pr = 1.5 * (cur.px - RES_X / 2) / (0.5 * zoom * RES_X) + move_x;
			p.pi = (cur.py - RES_Y / 2) / (0.5 * zoom * RES_Y) + move_y;
			i = burning_count(p);
			fputs(ft_itoa(coloring(i) / 10000), ptrfile);
			fputs(" ", ptrfile);
			mlx_pixel_put(mlx_ptr, win_ptr, cur.px, cur.py, coloring(i));
			cur.px++;
		}
		cur.py++;
		fputs("\n", ptrfile);
	}
	fclose(ptrfile);
	return (0);
}
