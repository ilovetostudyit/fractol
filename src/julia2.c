#include "fractol.h"
int julia2(void *mlx_ptr, void *win_ptr)
{
  //double cRe, cIm;           //real and imaginary part of the constant c, determinate shape of the Julia Set
  double newre, newIm, oldre, oldimm;   //real and imaginary parts of new and old
  hsv color; //the RGB color value for the pixel
  rgb color2;
  int fin_color; //after how much iterations the function should stop
  FILE * ptrfile = fopen("julia.txt", "w");

  //pick some values for the constant c, this determines the shape of the Julia Set

  //loop through every pixel
  int x,y;
  int i;
  int col_ra;
  x = 0;
  y = 0;
  col_ra=0;
  printf("%f\n", cRe);
  while(y < RES_Y)
  {
    while(x < RES_X)
    {
        //calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
        newre = 1.5 * (x - RES_X / 2) / (0.5 * zoom * RES_X) + move_x;
        newIm = (y - RES_Y / 2) / (0.5 * zoom * RES_Y) + move_y;
        //i will represent the number of iterations
        
        //start the iteration process
        i = 0;
        while (i < ITER)
        {
            //remember value of previous iteration
            oldre = newre;
            oldimm = newIm;
            //the actual iteration, the real and imaginary part are calculated
            newre = oldre * oldre - oldimm * oldimm + cRe;
            newIm = 2 * oldre * oldimm + cIm;
            //if the point is outside the circle with radius 2: stop
            if((newre * newre + newIm * newIm) > 4) break;
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
        fputs(ft_itoa(fin_color / (RES_X * RES_Y)), ptrfile);
        fputs(" ", ptrfile);
        x++;
    }
    x = 0;
    fputs("\n", ptrfile);
    y++;
  }
  fclose(ptrfile);
  return 0;
}