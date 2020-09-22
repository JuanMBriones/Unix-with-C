//Este programa crea 3 threads y los ejecuta para mostrar como cambia el control
//de la ejecución de un thread a otro.

/* gcc pruebaestados.c -lpthread -o pruebaestados  */
/* cd Desktop   */
/* ./pruebaestados  */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define MAX 1500

void *escribirA (void *nada)  {
  int num;

  for (num = 0; num < MAX; num++)  {
    printf ("A");
    fflush (stdout);
  }
  pthread_exit (NULL);
}

void *escribirB (void *nada)  {
  int num;

  for (num = 0; num < MAX; num++)  {
    printf ("B");
    fflush (stdout);
  }
  pthread_exit (NULL);
}

void *escribirC (void *nada)  {
  int num;

  for (num = 0; num < MAX; num++) {
    printf ("C");
    fflush (stdout);
  }
  pthread_exit (NULL);
}

int main (int argc, char *argv[])  {
    pthread_t th1, th2, th3;
    pthread_create (&th1, NULL, escribirA, NULL);
    pthread_create (&th2, NULL, escribirB, NULL);
    pthread_create (&th3, NULL, escribirC, NULL);
    pthread_join (th1, NULL);
    pthread_join (th2, NULL);
    pthread_join (th3, NULL);
    printf("\n");

    return (0);
}
