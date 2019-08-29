#include "fractol.h"

int mandelbrot(void *mlx_ptr, void *win_ptr)
{
  //each iteration, it calculates: newz = oldz*oldz + p, where p is the current pixel, and oldz stars at the origin
  double pr, pi;           //real and imaginary part of the pixel p
  double newre, newIm, oldre, oldimm;   //real and imaginary parts of new and old z
  hsv color; //the RGB color value for the pixel
  rgb color2;
  int fin_color; //after how much iterations the function should stop
  FILE * ptrfile = fopen("mandelbrot.txt", "w");
  //loop through every pixel
  int y;
  int x;

  y = 0;
  while (y < RES_Y)
  {
    x = 0;
    while (x < RES_X)
    {
      //calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
      pr = 1.5 * (x - RES_X / 2) / (0.5 * zoom * RES_X) + move_x;
      pi = (y - RES_Y / 2) / (0.5 * zoom * RES_Y) + move_y;
      newre = newIm = oldre = oldimm = 0; //these should start at 0,0
      //"i" will represent the number of iterations
      int i;
      //start the iteration process
      for(i = 0; i < ITER; i++)
      {
        //remember value of previous iteration
        oldre = newre;
        oldimm = newIm;
        //the actual iteration, the real and imaginary part are calculated
        newre = oldre * oldre - oldimm * oldimm + pr;
        newIm = 2 * oldre * oldimm + pi;
        //if the point is outside the circle with radius 2: stop
        if((newre * newre + newIm * newIm) > 4) break;
      }
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
      fin_color = creatergb((color2.r), (color2.g), (color2.b));
      fputs(ft_itoa(fin_color/10000), ptrfile);
      fputs(" ", ptrfile);
      //printf("%d ", fin_color);
          //fin_color = (((i * color2.r) % 255) << 16) + (((i * color2.g) % 255) << 8) + (i * color2.b) % 255;
      mlx_pixel_put(mlx_ptr, win_ptr, x, y, fin_color);
      x++;
    }
    y++;
    fputs("\n", ptrfile);
    //printf("/n");
  }
  fclose(ptrfile);
  return 0;
}