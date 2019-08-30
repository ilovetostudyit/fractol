/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:21:44 by ehaggon           #+#    #+#             */
/*   Updated: 2019/08/30 15:05:57 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			julia2(void *mlx_ptr, void *win_ptr)
{
	t_pnum		p;
	FILE		*ptrfile;
	int			i;
	t_coord		cur;

	ptrfile = fopen("julia.txt", "w");
	cur.py = 0;
	while (cur.py < RES_Y)
	{
		cur.px = 0;
		while (cur.px < RES_X)
		{
			p.pr = 1.5 * (cur.px - RES_X / 2) / (0.5 * zoom * RES_X) + move_x;
			p.pi = (cur.py - RES_Y / 2) / (0.5 * zoom * RES_Y) + move_y;
			i = julia_count(p);
			mlx_pixel_put(mlx_ptr, win_ptr, cur.px, cur.py, coloring(i));
			fputs(ft_itoa(coloring(i) / (RES_X * RES_Y)), ptrfile);
			fputs(" ", ptrfile);
			cur.px++;
		}
		fputs("\n", ptrfile);
		cur.py++;
	}
	fclose(ptrfile);
	return (0);
}
