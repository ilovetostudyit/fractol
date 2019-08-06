#include "fractol.h"

complex add(complex a,complex b)
{
	complex c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}
 
complex sqr(complex a){
	complex c;
	c.x = a.x*a.x - a.y*a.y;
	c.y = 2*a.x*a.y;
	return c;
}
 
double mod(complex a)
{
	return sqrt(a.x*a.x + a.y*a.y);
}
 
complex mapPoint(double radius,int x,int y)
{
	complex c;
	int l = (RES_X<RES_Y)?RES_X:RES_Y;
 
	c.x = 2*radius*(x - RES_X/2.0)/l;
	c.y = 2*radius*(y - RES_Y/2.0)/l;
 
	return c;
}
 
void juliaSet(void *mlx_ptr, void *win_ptr,complex c,double radius,int n)
{
	int x,y,i;
	complex z0,z1;
 
	for(x=0;x<=RES_X;x++)
		for(y=0;y<=RES_Y;y++){
			z0 = mapPoint(radius,x,y);
			for(i=1;i<=n;i++){
				z1 = add(sqr(z0),c);
				if(mod(z1)>radius){
					printf("%s\n", "I am here");
                    mlx_pixel_put(mlx_ptr, win_ptr, x, y, i%15+1);
					break;
				}
				z0 = z1;
			}
			if(i>n)
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0);
		}
}
 