//Este programa despiega el valor de la constante pi.
//gcc despliegapi.c -o despliegapi
//cd Desktop
//  ./despliegapi

#include <stdio.h>
#include <math.h>

int main()
{
   char str[80];

   sprintf(str, "Valor de Pi = %f", M_PI);
   puts(str);

   return(0);
}
