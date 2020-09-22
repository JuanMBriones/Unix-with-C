// cd Desktop
// gcc imprimea.c  -o imprimea         /*  Para compilarlo  */
//   ./imprimea                        /* Para Ejecutarlo   */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char **argv)
{int i;

for (i = 0; i < 5; i++)
{
if (i % 20 == 0) sleep(.5);
printf("\nA");
}
return 0;
}
