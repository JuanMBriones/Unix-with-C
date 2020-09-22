//Este programa crea “n” threads y los ejecuta para mostrar cómo cambia el control
//de la ejecución de un thread a otro.

/* gcc threadscombinados.c -lpthread -o threadscombinados  */
/* cd Desktop   */
/* ./treadscombinados  */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX 200
int A [10][10];
int B [10][10];
int C [10][10];

void *escribirA (void *nada)  {
  int num;

  for (num = 0; num < MAX; num++)  {
    printf ("A");
    fflush (stdout);
  }
  pthread_exit (NULL);
}

void * Calcasilla (void *arg)
{
int i, j, k;
int *n;

n = (int *)arg;

  i = (*n);

  for (j = 0; j < 10; j++)  {
  for (k = 0; k < 10; k++)
  { C[i][j] = C[i][j] + A[i][k] * B[k][j]; }
  }

pthread_exit(NULL);

}

void *multiplica (void *nada)
{
int i, j;
int ren[20];

for (i = 0; i < 10; i++) {ren[i]=i;}
//Se incializan las matrices A, B y C.
for (i = 0; i < 10; i++) {
  for (j = 0; j < 10; j++) {
    A[i] [j] = rand()%5;
    B[i] [j] = rand()%5;
    C[i] [j] = 0;  }}

/*  Impresión de datos  */
printf("\n");
printf("MATRIZ A\n");
for (i = 0; i < 10; i++) {
for (j = 0; j < 10; j++) {
printf("%d ", A[i] [j]);

}
printf("\n");
}

printf("\n");
printf("MATRIZ B\n");
for (i = 0; i < 10; i++) {
for (j = 0; j < 10; j++) {
printf("%d ", B[i] [j]);

}
printf("\n");
}

/*   Inicia la multiplicación de matrices   */
  pthread_t hilo [10];
  for (i = 0; i < 10; i++)
    {  pthread_create (&hilo[i], NULL, Calcasilla, &ren[i]);  }

  for (i = 0; i < 10; i++)
  {  pthread_join (hilo[i], NULL);  }

/*  Impresión de resultados (MATRIZ C)  */
printf("\n");
printf("MATRIZ C\n");
for (i = 0; i < 10; i++) {
for (j = 0; j < 10; j++) {
printf("%d ", C[i] [j]);

}
printf("\n");
}
  pthread_exit (NULL);
  // return 0;
  }
//*******************************************************************************

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
    pthread_create (&th2, NULL, multiplica, NULL);
    pthread_create (&th3, NULL, escribirC, NULL);
    pthread_join (th1, NULL);
    pthread_join (th2, NULL);
    pthread_join (th3, NULL);
    printf("\n");

    return (0);
}
