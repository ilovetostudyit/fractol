#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# define RES_X 820
# define RES_Y 640
# define LIM_R 30
# define ITER 300

typedef struct{
	double x,y;
}complex;

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

int isSierpinskiCarpetPixelFilled(long int x, long int y);
void SiepinskiCarpetFill(void *mlx_ptr, void *win_ptr, long int x, long int y);
int ft_usage();
complex add(complex a,complex b);
complex sqr(complex a);
double mod(complex a);
complex mapPoint(double radius,int x,int y);
void juliaSet(void *mlx_ptr, void *win_ptr,complex c,double radius,int n);
int julia2(void *mlx_ptr, void *win_ptr);
hsv   rgb2hsv(rgb in);
rgb   hsv2rgb(hsv in);


#endif