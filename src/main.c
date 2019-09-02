/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:38:18 by ehaggon           #+#    #+#             */
/*   Updated: 2019/09/02 12:20:32 by ehaggon          ###   ########.fr       */
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

void	ft_function(t_shit *arg2)
{
	if (arg2->fr_num == 4)
	{
		sierpinskicarpet(arg2);
	}
	else if (arg2->fr_num == 1)
	{
		julia2(arg2);
	}
	else if (arg2->fr_num == 2)
	{
		mandelbrot(arg2);
	}
	else if (arg2->fr_num == 3)
	{
		burningship(arg2);
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
	t_shit		*arg2;

	arg2 = (t_shit*)malloc(sizeof(t_shit));
	ft_init(arg2);
	if ((argc != 2) || (!(arg2->fr_num = ft_check_args(argv[1]))))
		return (ft_usage());
	arg2->mlx = mlx_init();
	arg2->win = mlx_new_window(arg2->mlx, RES_X, RES_Y, argv[1]);
	ft_function(arg2);
	mlx_hook(arg2->win, 6, (1L << 6), ft_track, (void *)arg2);
	mlx_mouse_hook(arg2->win, ft_zoom, (void *)arg2);
	mlx_key_hook(arg2->win, ft_form, (void *)arg2);
	mlx_loop(arg2->mlx);
	return (0);
}
