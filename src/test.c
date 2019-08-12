#include "fractol.h"
int test(void *mlx_ptr, void *win_ptr)
{
  double cRe, cIm;           //real and imaginary part of the constant c, determinate shape of the Julia Set
  double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old
  hsv color; //the RGB color value for the pixel
  rgb color2;
  int fin_color; //after how much iterations the function should stop

  //pick some values for the constant c, this determines the shape of the Julia Set
  cRe = -0.7;
  cIm = 0.27015;

  //loop through every pixel
  int x,y;
  int i;
  int col_ra;

  x = 0;
  y = 0;
  col_ra=0;
  while(y < RES_Y)
  {
    while(x < RES_X)
    {
        //calculate the initial real and imaginary part of z, based on the pixel location and ZOOM and position values
        newRe = 1.5 * (x - RES_X / 2) / (0.5 * ZOOM * RES_X) + MOVE_X;
        newIm = (y - RES_Y / 2) / (0.5 * ZOOM * RES_Y) + MOVE_Y;
        //i will represent the number of iterations
        
        //start the iteration process
        i = 0;
        while (i < ITER)
        {
            //remember value of previous iteration
            oldRe = newRe;
            oldIm = newIm;
            //the actual iteration, the real and imaginary part are calculated
            newRe = oldRe * oldRe - oldIm * oldIm + cRe;
            newIm = 2 * oldRe * oldIm + cIm;
            //if the point is outside the circle with radius 2: stop
            if((newRe * newRe + newIm * newIm) > 4) break;
            i++;
        }
        //use color model conversion to get rainbow palette, make brightness black if maxIterations reached

        color.h = (i % 255);
        color.s = 255;
        color.v = 255*(i < ITER);
        color2 = hsv2rgb(color);
        if (i < ITER)
        {
          color2.r = i  * st_r % 255;
          color2.g = i * st_g % 255;
          color2.b = i* st_b % 255;
        }
        //draw the pixel
        fin_color = createRGB((color2.r), (color2.g), (color2.b));
        //fin_color = (((i * color2.r) % 255) << 16) + (((i * color2.g) % 255) << 8) + (i * color2.b) % 255;
        mlx_pixel_put(mlx_ptr, win_ptr, x, y, fin_color);
        x++;
    }
    x = 0;
    y++;
  }
  return 0;
}