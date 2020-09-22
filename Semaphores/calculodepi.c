// cd Desktop
// gcc calculodepi.c -lpthread -o calculodepi  /*  Para comiplarlo */
// ./calculodepi     /*  Para Ejecutarlo  *

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/times.h>
#include <semaphore.h>
#include <math.h>

#define MAX_NUM_THREADS 32000
/*  Variables Globales  */
sem_t     lock;
double    pi;
int       intervals;
int       numthreads;
char str[80];
// void *computepi(void*);

void * computepi (void *arg)
{ int *id;
  int  i;
  double localsum, width, x;

  id = (int *)arg;
  localsum = 0.0;
  width = 1.0 / intervals;
  for (i = (*id); i < intervals; i+=numthreads)
  {
    x = (i + 0.5) * width;
  //  printf("Valor de x = %8.7f\n", x);
    localsum+= (4.0/(1.0 + x * x));
  }
  localsum*=width;
  sem_wait(&lock);
    pi+=localsum;
  sem_post(&lock);

pthread_exit(NULL);
}

int main()
{
int  ids[MAX_NUM_THREADS], i;
/*  Variables para mediciones de tiempos  */
struct  tms  buff1,  buff2;
clock_t      clock1, clock2;
float        utime,  stime;
//unsigned int utime,  stime;
//unsigned int micros;
float        micros;
long int ticksPerSec;

/*  Inicialización  */
printf("\nCaptura el número de threads ");
scanf("%d", &numthreads);
printf("\nCaptura el número de rectángulos ");
scanf("%d", &intervals);
clock1 = times(&buff1);
pi = 0.0;
for (i = 0; i < numthreads; i++)
    ids[i] = i;

/*   Inicia el cálculo de pi   */

  pthread_t hilo [numthreads];
  sem_init (&lock, 0, 1);  /*  Habilitado     */

  for (i = 0; i < numthreads; i++)
      pthread_create (&hilo[i], NULL, computepi, &ids[i]);

  for (i = 0; i < numthreads; i++)
      pthread_join (hilo[i], NULL);

clock2 = times(&buff2);

/*  Imprimir resultados   */
printf("El valor calculado de pi es  = %12.11f\n", pi);
/* imprimir el valor de pi con la biblioteca matemática  */
sprintf(str, "El valor de biblioteca de pi = %12.11f", M_PI);
puts(str);
printf("Número de threads: %d\n", numthreads);
micros = clock2 - clock1;

ticksPerSec = sysconf(_SC_CLK_TCK);
printf("Ticks por segundo = %lu\n", ticksPerSec);

printf("Tiempo real: %10.5f segundos \n", micros/ticksPerSec);
utime = buff2.tms_utime - buff1.tms_utime;
printf("Tiempo de usuario: %10.5f segundos \n", utime/ticksPerSec);
stime = buff2.tms_stime - buff1.tms_stime;
printf("Tiempo de sistema: %10.5f segundos \n", stime/ticksPerSec);
printf("Tiempo de ejecución: %10.5f segundos \n", (utime + stime)/ticksPerSec);
return 0;
}
