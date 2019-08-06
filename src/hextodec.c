#include "fractol.h"
/*char *hextodec(long dec)
{
 long long decimal, place;
 int i = 0, val, len;

 decimal = 0;
 place = 1;

 len = ft_strlen(hex);
 len--;

 while (hex[i] != '\0')
 {
    if(hex[i]>='0' && hex[i]<='9')
        val = hex[i] - 48;
    else if(hex[i]>='a' && hex[i]<='f')
        val = hex[i] - 97 + 10;
    else if(hex[i]>='A' && hex[i]<='F')
        val = hex[i] - 65 + 10;
    decimal += val * pow(16, len);
    len--;
    i++;
 }
 return (decimal);
}*/

unsigned long createRGB(int r, int g, int b)
{   
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}