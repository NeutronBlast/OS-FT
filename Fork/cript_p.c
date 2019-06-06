#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/time.h>
#include <locale.h>
#include "encript.h"
#include "decypher.h"
#include "manejoArchivos.h"
#include "slice.h"

int main(int argc, char *argv[]) {
    setlocale(LC_ALL,"");
    struct timeval begin, end;
    gettimeofday(&begin,NULL);
    /*Tomar los argumentos de la linea de comando*/
    int NumHijos;
    int op = 0;

    /*Encriptar o desencriptar*/
    size_t len = strlen(argv[1]);
    char * operacion = malloc(len+2);
    strcpy(operacion, argv[1]);

    NumHijos = atoi(argv[2]);

    len = strlen(argv[3]);
    /*Nombre archivo de entrada*/
    char * file1 = malloc(len+5);
    strcpy(file1, argv[3]);
    strcat(file1,".txt");

    len = strlen(argv[4]);
    /*Nombre archivo de salida*/
    char * file2 = malloc(len+10);
    strcpy(file2, argv[4]); 
    strcat(file2,".txt");  

    /*Texto a encriptar o desencriptar*/
    char vector [1000];

    /*printf("La operacion es: %s\n",operacion); 
    printf("El numero de enteros a ordenar es: %d\n",NumHijos); 
    printf("El nombre del archivo desordenado es: %s\n", file1);
    printf("El nombre del archivo ordenado es: %s\n\n", file2); */

    abrirArchivoEntrada(file1, vector);

    int i = 1;

    int length = strlen(vector);

    if (operacion[1] == 'd'){
        //printf("Toca desencriptar\n");
        op = 1;
    }

    else if (operacion[1] == 'c'){
        //printf("Toca encriptar\n");
        op = 2;
    }

    /*Crear arbol de procesos*/
    int inicio=0;
    int fin = 0;

if (op==2)
    length = removeSpace(vector,length)-2;

else
    length = strlen(vector);

     printf("Text after removing blanks\n%s\n", vector);
     printf("New length %d\n", length);

    replace(file1,vector);

    children(file1,length,NumHijos, inicio, op,fin,file2);
    gettimeofday(&end,NULL);
    printf("Fin del programa, tiempo total de ejecucion %f segundos\n", (double)(end.tv_usec - begin.tv_usec)/1000000+ (double)(end.tv_sec - begin.tv_sec)) ;
    return 0; 
}
