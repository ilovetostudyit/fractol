/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 18:03:55 by ehaggon           #+#    #+#             */
/*   Updated: 2019/08/30 16:44:15 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>

# define RES_X 400
# define RES_Y 400
# define LIM_R 30
# define ITER 50
# define ZOOM 1
# define MOVE_X 0
# define MOVE_Y 0
# define KEY_R			15
# define KEY_1			18
# define KEY_2			19
# define KEY_3			20
# define KEY_4			21
# define KEY_5			23
# define KEY_6			22
# define KEY_7			26
# define KEY_M			46
# define KEY_ESCAPE		53
# define KEY_PLUS		69
# define KEY_MINUS		78
# define KEY_LEFT		123
# define KEY_UP			126
# define KEY_RIGHT		124
# define KEY_DOWN		125
# define KEY_CLEAR      117
# define MOUSE_LEFT		1
# define MOUSE_RIGHT	2
# define MOUSE_DOWN		5
# define MOUSE_UP		4

int st_r;
int st_g;
int st_b;
double zoom;
double move_x;
double move_y;
void *mlx;
void *win;
int fr_num;
double cre;
double cim;
int mouse_off;

typedef struct	s_shit{
	int st_r;
	int st_g;
	int st_b;
	double zoom;
	double move_x;
	double move_y;
	void *mlx;
	void *win;
	int fr_num;
	double cre;
	double cim;
	int mouse_off;
}				t_shit;

typedef struct	s_rgb{
	double	r;
	double	g;
	double	b;
}				t_rgb;

typedef struct	s_coord{
	long long int px;
	long long int py;
}				t_coord;

typedef struct	s_fract{
	double		newre;
	double		newim;
	double		oldre;
	double		oldim;
}				t_fract;

typedef struct	s_pnum{
	double		pr;
	double		pi;
}				t_pnum;

int				hextodec(long dec);
void			sierpinskicarpet(void *mlx_ptr, void *win_ptr);
int				ft_usage(void);
int				julia2(t_shit *argum2);
unsigned long	create_rgb(int r, int g, int b);
int				mandelbrot(void *mlx_ptr, void *win_ptr);
void			ft_function(t_shit *argum2);
void			clear_image(void *mlx_ptr, void *win_ptr);
int				ft_form(int button, void *param);
int				ft_clear(int button);
int				ft_track(int x, int y, void *param);
int				burningship(void *mlx_ptr, void *win_ptr);
int				ft_zoom(int button, int x,int y, void *param);
int				coloring(int i);
int				srp_col(int i, long int d);
long int		dim_count(void);
long int		d_count(long int d, t_coord cd);
int				mand_count(t_pnum p);
int				julia_count(t_pnum p, t_shit *argum2);
int				burning_count(t_pnum p);
int				ft_form2(int button, t_shit *argum2);
void 			ft_init(t_shit *argum2);
#endif
