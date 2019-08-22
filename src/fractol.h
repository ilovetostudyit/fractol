#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# define RES_X 200
# define RES_Y 200
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
typedef struct{
	int x,y;
}complex;

typedef struct s_argum {
    void *mlx;       // a fraction between 0 and 1
    void *win;       // a fraction between 0 and 1
    double zoom;       // a fraction between 0 and 1
} t_argum;

typedef struct {
    double r;       // a fraction between 0 and 1
    double g;       // a fraction between 0 and 1
    double b;       // a fraction between 0 and 1
} rgb;

typedef struct {
    double h;       // angle in degrees
    double s;       // a fraction between 0 and 1
    double v;       // a fraction between 0 and 1
} hsv;

int hextodec(long dec);
int isSierpinskiCarpetPixelFilled(long int x, long int y);
void SiepinskiCarpetFill(void *mlx_ptr, void *win_ptr, long int x, long int y);
int ft_usage();
complex add(complex a,complex b);
complex sqr(complex a);
int mod(complex a);
complex mapPoint(int radius,int x,int y);
void juliaSet(void *mlx_ptr, void *win_ptr,complex c,int radius,int n);
int julia2(void *mlx_ptr, void *win_ptr);
hsv   rgb2hsv(rgb in);
rgb   hsv2rgb(hsv in);
unsigned long createRGB(int r, int g, int b);
int mandelbrot(void *mlx_ptr, void *win_ptr);
void ft_function(int fr_num);
void clear_image(void *mlx_ptr, void *win_ptr);
int ft_form(int button);
#endif
