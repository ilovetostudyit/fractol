/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:32:41 by ehaggon           #+#    #+#             */
/*   Updated: 2019/09/02 12:30:14 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_track(int x, int y, void *param)
{
	t_shit		*arg2;

	arg2 = (t_shit *)param;
	if (arg2->fr_num == 1 && arg2->mouse_off)
	{
		param = 0;
		if (x >= 0 && x <= RES_X && y >= 0 && y <= RES_Y)
		{
			arg2->cre = (double)x * -0.002205;
			arg2->cim = (double)y * 0.00081;
			ft_function(arg2);
		}
	}
	return (0);
}

int	ft_form(int button, void *param)
{
	t_shit		*arg2;

	arg2 = (t_shit *)param;
	if (button == KEY_ESCAPE)
		exit(0);
	else if (button == KEY_UP)
		arg2->move_y = arg2->move_y - 0.1;
	else if (button == KEY_DOWN)
		arg2->move_y = arg2->move_y + 0.1;
	else if (button == KEY_LEFT)
		arg2->move_x = arg2->move_x - 0.1;
	else if (button == KEY_RIGHT)
		arg2->move_x = arg2->move_x + 0.1;
	else if (button == 18 || button == 19 || button == 20)
	{
		arg2->fr_num = button - 17;
		clear_image(arg2->mlx, arg2->win);
	}
	else
		ft_form2(button, arg2);
	ft_function(arg2);
	return (0);
}

int	ft_form2(int button, t_shit *arg2)
{
	if (button == 21)
		(arg2->st_r < 9) ? (arg2->st_r++) : (arg2->st_r = 0);
	else if (button == 22)
		(arg2->st_g < 9) ? (arg2->st_g++) : (arg2->st_g = 0);
	else if (button == 23)
		(arg2->st_b < 9) ? (arg2->st_b++) : (arg2->st_b = 0);
	else if (button == KEY_CLEAR)
		clear_image(arg2->mlx, arg2->win);
	else if (button == KEY_M)
		arg2->mouse_off ? (arg2->mouse_off--) : (arg2->mouse_off++);
	ft_function(arg2);
	return (0);
}

int	ft_zoom(int button, int x, int y, void *param)
{
	t_shit		*arg2;

	x = 0;
	y = 0;
	arg2 = (t_shit *)param;
	if (button == MOUSE_UP)
	{
		arg2->zoom = arg2->zoom + 0.1;
		clear_image(arg2->mlx, arg2->win);
	}
	else if (button == MOUSE_DOWN)
	{
		if (arg2->zoom > 0)
		{
			arg2->zoom = arg2->zoom - 0.1;
		}
	}
	ft_function(arg2);
	return (0);
}
