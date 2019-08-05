#include "fractol.h"

int isSierpinskiCarpetPixelFilled(int x, int y)
{
    while (x > 0 || y > 0) // when either of these reaches zero the pixel is determined to be on the edge                            // at that square level and must be filled
    {
        if (x % 3 == 1 && y % 3 == 1) //checks if the pixel is in the center for the current square level
            return 0;
        x /= 3; //x and y are decremented to check the next larger square level
        y /= 3;
    }
    return 1; // if all possible square levels are checked and the pixel is not determined 
                   // to be open it must be filled
}

void SiepinskiCarpetFill(void *mlx_ptr, void *win_ptr)
{
    ft_putstr("WOW <0.0> i am here");
    mlx_pixel_put(mlx_ptr, win_ptr, 500, 500, 0xFFFFFF);
}