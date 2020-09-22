//Multiplicación de matrices con threads.  Cada thread calcula un renglón de la matriz
//resultante (MATRIZ C)
//cd Desktop
//gcc Multmatrices.c -lpthread -o Multmatrices
//  ./Multmatrices

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int A [500][500];
int B [500][500];
int C [500][500];
int numreng, numcolu;

void * Calrenglon (void *arg)
{
int i, j, k;
int *n;

n = (int *)arg;

  i = (*n);

  for (j = 0; j < numreng; j++)  {
  for (k = 0; k < numcolu; k++)
  { C[i][j] = C[i][j] + A[i][k] * B[k][j]; }
  }

pthread_exit(NULL);

}

int main (int argc, char *argv[])  {
int i, j;
int ren[500];

do
{
printf("Multiplicación de 2 matrices cuadradas\n");
printf("Teclea el número de renglones y columnas de las matrices (máximo 380)\n");
scanf("%d %d", &numreng, &numcolu);
}
while((numreng != numcolu) | numreng > 380);

for (i = 0; i < numreng; i++) {ren[i]=i;}

//Se incializan las matrices A, B y C.
for (i = 0; i < numreng; i++) {
  for (j = 0; j < numcolu; j++) {
    A[i] [j] = rand()%5;
    B[i] [j] = rand()%5;
    C[i] [j] = 0;  }}


/*  Impresión de datos  */
printf("MATRIZ A\n");
for (i = 0; i < numreng; i++) {
for (j = 0; j < numcolu; j++) {
printf("%d ", A[i] [j]);

}
printf("\n");
}

printf("MATRIZ B\n");
for (i = 0; i < numreng; i++) {
for (j = 0; j < numcolu; j++) {
printf("%d ", B[i] [j]);

}
printf("\n");
}

/*   Inicia la multiplicación de matrices   */

  pthread_t hilo [numreng];
  for (i = 0; i < numreng; i++)
    {  pthread_create (&hilo[i], NULL, Calrenglon, &ren[i]);  }

  for (i = 0; i < numreng; i++)
  {  pthread_join (hilo[i], NULL);  }

/*  Impresión de resultados (MATRIZ C)  */
printf("Terminó la multiplicación\n");
printf("MATRIZ C\n");
for (i = 0; i < numreng; i++) {
for (j = 0; j < numcolu; j++) {
printf("%d ", C[i] [j]);

}
printf("\n");
}

  return 0;
  }
