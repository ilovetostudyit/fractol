/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:32:41 by ehaggon           #+#    #+#             */
/*   Updated: 2019/08/30 16:54:12 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_track(int x, int y, void *param)
{
	t_shit		*argum2;

	argum2 =(t_shit *)param;
	if (argum2->fr_num == 1 && argum2->mouse_off)
	{
		param = 0;
		if (x >= 0 && x <= RES_X && y >= 0 && y <= RES_Y)
		{
			argum2->cre = (double)x * -0.002205;
			argum2->cim = (double)y * 0.00081;
			ft_function(argum2);
		}
	}
	return (0);
}

int	ft_form(int button, void *param)
{
	t_shit		*argum2;

	argum2 =(t_shit *)param;
	if (button == KEY_UP)
		argum2->move_y = argum2->move_y - 0.1;
	else if (button == KEY_DOWN)
		argum2->move_y = argum2->move_y + 0.1;
	else if (button == KEY_LEFT)
		argum2->move_x = argum2->move_x - 0.1;
	else if (button == KEY_RIGHT)
		argum2->move_x = argum2->move_x + 0.1;
	else if (button == 18 || button == 19 || button == 20)
	{
		argum2->fr_num = button - 17;
		clear_image(argum2->mlx, argum2->win);
	}
	else
		ft_form2(button, argum2);
	ft_function(argum2);
	return (0);
}

int	ft_form2(int button, t_shit *argum2)
{
	if (button == 21)
		(argum2->st_r < 9) ? (argum2->st_r++) : (argum2->st_r = 0);
	else if (button == 22)
		(argum2->st_g < 9) ? (argum2->st_g++) : (argum2->st_g = 0);
	else if (button == 23)
		(argum2->st_b < 9) ? (argum2->st_b++) : (argum2->st_b = 0);
	else if (button == KEY_CLEAR)
		clear_image(argum2->mlx, argum2->win);
	else if (button == KEY_M)
		argum2->mouse_off ? (argum2->mouse_off--) : (argum2->mouse_off++);
	ft_function(argum2);
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
		argum2->zoom = argum2->zoom + 0.1;
		clear_image(argum2->mlx, argum2->win);
		//ft_function(fr_num,argum2);
	}
	else if (button == MOUSE_DOWN)
	{
		if (argum2->zoom > 0)
		{
			argum2->zoom = argum2->zoom - 0.1;
		}
	}
	ft_function(argum2);
	return (0);
}
