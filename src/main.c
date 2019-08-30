/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:38:18 by ehaggon           #+#    #+#             */
/*   Updated: 2019/08/30 16:39:30 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clear_image(void *mlx_ptr, void *win_ptr)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < RES_X)
	{
		while (y < RES_Y)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x000000);
			y++;
		}
		y = 0;
		x++;
	}
}

void	ft_function(t_shit *argum2)
{
	if (argum2->fr_num == 4)
	{
		sierpinskicarpet(mlx, win);
	}
	else if (argum2->fr_num == 1)
	{
		julia2(argum2);
	}
	else if (argum2->fr_num == 2)
	{
		mandelbrot(mlx, win);
	}
	else if (argum2->fr_num == 3)
	{
		burningship(mlx, win);
	}
}

int		ft_usage(void)
{
	ft_putstr("USAGE: program draws these fractals:\n");
	ft_putstr("Mandelbrot\n");
	ft_putstr("Julia\n");
	ft_putstr("Burningship\n");
	ft_putstr("Sierpinski\n");
	return (0);
}

int		ft_check_args(char *str)
{
	if (!(ft_strcmp(str, "Julia")))
		return (1);
	else if (!(ft_strcmp(str, "Mandelbrot")))
		return (2);
	else if (!(ft_strcmp(str, "Burningship")))
		return (3);
	else if (!(ft_strcmp(str, "Sierpinski")))
		return (4);
	return (0);
}

int		main(int argc, char **argv)
{
	t_shit		*argum2;

	mouse_off = 1;
	cre = -0.7;
	cim = 0.27015;
	st_r = 0;
	st_b = 0;
	st_g = 9;
	move_x = -0.5;
	move_y = 0;
	argum2 = (t_shit*)malloc(sizeof(t_shit));
	ft_init(argum2);
	zoom = 1;
	if ((argc != 2) || (!(argum2->fr_num = ft_check_args(argv[1]))))
		return (ft_usage());
	argum2->mlx = mlx_init();
	mlx = argum2->mlx;
	argum2->win = mlx_new_window(argum2->mlx, RES_X, RES_Y, argv[1]);
	win = argum2->win;
	ft_function(argum2);
	mlx_hook(argum2->win, 6, (1L << 6), ft_track, (void *)argum2);
	mlx_mouse_hook(argum2->win, ft_zoom, (void *)argum2);
	mlx_key_hook(argum2->win, ft_form, (void *)argum2);
	mlx_loop(argum2->mlx);
	return (0);
}
