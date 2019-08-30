/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:32:41 by ehaggon           #+#    #+#             */
/*   Updated: 2019/08/30 15:04:38 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_track(int x, int y, void *param)
{
	t_shit		*argum2;

	argum2 =(t_shit *)param;
	//printf("%f\n", argum2->zoom);
	if (fr_num == 1 && mouse_off)
	{
		param = 0;
		if (x >= 0 && x <= RES_X && y >= 0 && y <= RES_Y)
		{
			cre = (double)x * -0.002205;
			cim = (double)y * 0.00081;
			ft_function(fr_num, argum2);
		}
	}
	return (0);
}

int	ft_form(int button, void *param)
{
	t_shit		*argum2;

	argum2 =(t_shit *)param;
	printf("%f\n", argum2->zoom);
	if (button == KEY_UP)
		move_y = move_y - 0.1;
	else if (button == KEY_DOWN)
		move_y = move_y + 0.1;
	else if (button == KEY_LEFT)
		move_x = move_x - 0.1;
	else if (button == KEY_RIGHT)
		move_x = move_x + 0.1;
	else if (button == 18 || button == 19 || button == 20)
	{
		fr_num = button - 17;
		clear_image(mlx, win);
	}
	else
		ft_form2(button, argum2);
	ft_function(fr_num, argum2);
	return (0);
}

int	ft_form2(int button, t_shit *argum2)
{
	if (button == 21)
		(st_r < 9) ? (st_r++) : (st_r = 0);
	else if (button == 22)
		(st_g < 9) ? (st_g++) : (st_g = 0);
	else if (button == 23)
		(st_b < 9) ? (st_b++) : (st_b = 0);
	else if (button == KEY_CLEAR)
		clear_image(mlx, win);
	else if (button == KEY_M)
		mouse_off ? (mouse_off--) : (mouse_off++);
	ft_function(fr_num, argum2);
	return (0);
}

int	ft_zoom(int button, int x,int y, void *param)
{
	t_shit		*argum2;

	x = 0;
	y = 0;
	argum2 =(t_shit *)param;
	if (button == MOUSE_UP)
	{
		zoom = zoom + 0.1;
		clear_image(mlx, win);
		//ft_function(fr_num,argum2);
	}
	else if (button == MOUSE_DOWN)
	{
		if (zoom > 0)
		{
			zoom = zoom - 0.1;
		}
	}
	ft_function(fr_num,argum2);
	return (0);
}
