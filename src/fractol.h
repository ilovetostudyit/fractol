#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>

int isSierpinskiCarpetPixelFilled(long int x, long int y);
void SiepinskiCarpetFill(void *mlx_ptr, void *win_ptr, long int x, long int y);
int ft_usage();
#endif