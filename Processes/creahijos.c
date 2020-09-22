//Este programa crea procesos hijo de acuerdo al valor de n.
//gcc creahijos.c -o creahijos
//cd Desktop
//  ./creahijos n <número de hijos>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char *argv[] )
{
    int i, pid;

    for(i = 0; i < atoi(argv[1]); i++)
    {
        pid = fork();
        if(pid < 0) {
            printf("Error occured");
            exit(1);
        } else if (pid == 0) {
            printf("Child (%d): %d\n", i + 1, getpid());
            exit(0);
        } else  {
            wait(NULL);
        }
    }
}
