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

void SiepinskiCarpetFill(void *mlx_ptr, void *win_ptr)
{   
    long int x, y, dim, d;
    hsv color; //the RGB color value for the pixel
    rgb color2;
    int fin_color; //after how much iterations the function should stop

    x = 0;
    dim = 1;
    while  (x < ITER)
    {
        dim*=3;
        x++;
    }
    x = 0;
    y = 0;
    while (y < RES_Y)
    {
        x = 0;
        while (x < RES_X)
        {
            d = dim / 3;
            while (d != 0)
            {
                if (((x % (d * 3)) / d == 1 && (y % (d * 3)) / d == 1))
					break;
                d = d / 3;
            }
            color.h = (d % 255);
            color.s = 255;
            color.v = 255*(d < dim/3);
            color2 = hsv2rgb(color);
            if (d < dim/3)
            {
                color2.r = d  * st_r % 255;
                color2.g = d * st_g % 255;
                color2.b = d * st_b % 255;
            }
          //draw the pixel
            fin_color = createRGB((color2.r), (color2.g), (color2.b));
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, fin_color);
            x++;
        }
        y++;
    }
}