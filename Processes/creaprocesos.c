/*sudo kill -9 pid
/* gcc creaprocesos.c -o creaprocesos           */
/* cd Desktop                                   */
/* ./creaprocesos                               */
/* Simula un Schell de comandos                 */
/* se teclea como proceso a lanzar "salir" para terminar el programa  */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//#define TRUE 1

int main()
{
pid_t wait(int *status);
char c,  comando[80];
bool fin = true;
int i, j, status;

  while (fin)
  {
   printf("\nQué proceso deseas lanzar ");
   scanf("%s", comando);
   printf("comando %s\n", comando);
   if (strcmp(comando, "salir") == 0) fin = false;
   {
   if (fin == true) {
   if (fork() != 0)
   {
      /*  El proceso padre ejecuta ésta sección de código  */
      printf("%d - El ProcessID del -- padre es %d\n", i, getpid());
      fflush(stdout);
      wait(&status);
    } else {
      /*  El proceso hijo ejecuta ésta sección de código  */
      printf("%d - El ProcessID del -- hijo es %d\n", i, getpid());
      fflush(stdout);
      //La siguiente instrucción subsituye a la instrucción execve que
      //anteriormente se utilizaba que era execve(.....).
      execlp(comando, comando, NULL);
     }
    i++;
    }
    }
  }
}
