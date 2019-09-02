/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 13:57:56 by ehaggon           #+#    #+#             */
/*   Updated: 2019/09/02 12:27:17 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			coloring(int i, t_shit *arg2)
{
	int		fin_color;
	t_rgb	color2;

	color2.r = 0;
	color2.g = 0;
	color2.b = 0;
	if (i < ITER)
	{
		color2.r = i * arg2->st_r % 255;
		color2.g = i * arg2->st_g % 255;
		color2.b = i * arg2->st_b % 255;
	}
	fin_color = create_rgb((color2.r), (color2.g), (color2.b));
	return (fin_color);
}

int			srp_col(int i, long int d, t_shit *arg2)
{
	int		fin_color;
	t_rgb	color2;

	color2.r = 0;
	color2.g = 0;
	color2.b = 0;
	if (i < d / 3)
	{
		color2.r = i * arg2->st_r % 255;
		color2.g = i * arg2->st_g % 255;
		color2.b = i * arg2->st_b % 255;
	}
	fin_color = create_rgb((color2.r), (color2.g), (color2.b));
	return (fin_color);
}

void		ft_init(t_shit *arg2)
{
	arg2->mouse_off = 1;
	arg2->cre = -0.7;
	arg2->cim = 0.27015;
	arg2->st_r = 0;
	arg2->st_b = 0;
	arg2->st_g = 9;
	arg2->move_x = -0.5;
	arg2->move_y = 0;
	arg2->zoom = 1;
}
