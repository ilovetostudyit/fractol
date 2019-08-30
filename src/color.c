/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 13:57:56 by ehaggon           #+#    #+#             */
/*   Updated: 2019/08/30 17:00:21 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			coloring(int i, t_shit *argum2)
{
	int		fin_color;
	t_rgb	color2;

	color2.r = 0;
	color2.g = 0;
	color2.b = 0;
	if (i < ITER)
	{
		color2.r = i * argum2->st_r % 255;
		color2.g = i * argum2->st_g % 255;
		color2.b = i * argum2->st_b % 255;
	}
	fin_color = create_rgb((color2.r), (color2.g), (color2.b));
	return (fin_color);
}

int			srp_col(int i, long int d, t_shit *argum2)
{
	int		fin_color;
	t_rgb	color2;

	color2.r = 0;
	color2.g = 0;
	color2.b = 0;
	if (i < d / 3)
	{
		color2.r = i * argum2->st_r % 255;
		color2.g = i * argum2->st_g % 255;
		color2.b = i * argum2->st_b % 255;
	}
	fin_color = create_rgb((color2.r), (color2.g), (color2.b));
	return (fin_color);
}

void 			ft_init(t_shit *argum2)
{
	argum2->mouse_off = 1;
	argum2->cre = -0.7;
	argum2->cim = 0.27015;
	argum2->st_r = 0;
	argum2->st_b = 0;
	argum2->st_g = 9;
	argum2->move_x = -0.5;
	argum2->move_y = 0;
	argum2->zoom = 1;
}
