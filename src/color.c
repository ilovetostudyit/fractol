/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 13:57:56 by ehaggon           #+#    #+#             */
/*   Updated: 2019/08/30 13:59:45 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			coloring(int i)
{
	int		fin_color;
	t_rgb	color2;

	color2.r = 0;
	color2.g = 0;
	color2.b = 0;
	if (i < ITER)
	{
		color2.r = i * st_r % 255;
		color2.g = i * st_g % 255;
		color2.b = i * st_b % 255;
	}
	fin_color = create_rgb((color2.r), (color2.g), (color2.b));
	return (fin_color);
}

int			srp_col(int i, long int d)
{
	int		fin_color;
	t_rgb	color2;

	color2.r = 0;
	color2.g = 0;
	color2.b = 0;
	if (i < d / 3)
	{
		color2.r = i * st_r % 255;
		color2.g = i * st_g % 255;
		color2.b = i * st_b % 255;
	}
	fin_color = create_rgb((color2.r), (color2.g), (color2.b));
	return (fin_color);
}
