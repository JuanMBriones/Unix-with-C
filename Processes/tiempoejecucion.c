#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
//#define NULL 0

int main (int argc, char *argv[])
{
time_t inicio = 0, fin = 0;

char c, comando[255];

  printf("\nQué proceso deseas lanzar ");
  scanf("%s", comando);

if (fork() != 0)
  {
  inicio = time (NULL);
  printf("inicio %ld\n", inicio);
  wait (NULL);
  fin = time (NULL);
  printf("fin %ld\n", fin);
  printf ("Tiempo empleado:  %ld\n", fin - inicio);
  }
  else
  {
  printf("comando %s\n", comando);
  execlp (comando, comando, NULL);
  }
}
