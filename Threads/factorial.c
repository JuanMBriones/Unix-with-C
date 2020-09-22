#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void * factorial (void * dato)
{
  long long int resultado = 1;
  int num, n = atoi((char *) dato);

  for (num = 2; num <= n; num++)
  {
    resultado = resultado * num;
    printf("Factorial de %d, resultado parcial %lld\n", n, resultado);
    sleep (random() %3);
  }
  printf("El factorial de %d es %lld\n", n, resultado);
  pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
  pthread_t hilo[argc - 1];
  int param;
  if(argc < 2)
  {
    printf("Faltó indicar parámetros: los números de los que quieres obtener su factorial.\n");
    exit (0);
  }
  for (param = 0; param < argc - 1; param++)
    pthread_create(&hilo[param], NULL, factorial, (void *) argv[param + 1]);
  for (param = 0; param < argc - 1; param++)
  {
    pthread_join(hilo[param], NULL);
    printf("Hilo %d finalizado\n", param + 1);
  }
  printf("Factoriales calculados\n");
  return 0;
}
