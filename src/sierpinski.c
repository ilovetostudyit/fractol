#include "fractol.h"

int isSierpinskiCarpetPixelFilled(long int x, long int y)
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

void SiepinskiCarpetFill(void *mlx_ptr, void *win_ptr, long int x, long int y)
{
    long int x_1;
    long int y_1;

    x_1 = 0;
    y_1 = 0;
    while (x_1 < x)
    {
        while (y_1 < y)
        {
            if (isSierpinskiCarpetPixelFilled(x_1, y_1))
                mlx_pixel_put(mlx_ptr, win_ptr, x_1, y_1, 0xFFFFFF);
            y_1++;
        }
        y_1 = 0;
        x_1++;
    }
}