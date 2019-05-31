#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "manejoArchivos.h"

int main(int argc, char *argv[]) {
    /*Tomar los argumentos de la linea de comando*/
    int NumEnteros, NumNiveles;
    NumEnteros = atoi(argv[1]);
    NumNiveles = atoi(argv[2]);

    size_t len = strlen(argv[3]);
    /*Nombre archivo de entrada*/
    char * file1 = malloc(len+1);
    strcpy(file1, argv[3]);
    strcat(file1,".bin");

    len = strlen(argv[4]);
    /*Nombre archivo de salida*/
    char * file2 = malloc(len+1);
    strcpy(file2, argv[4]);   

    /*Vector a ordenar*/
    int vector [NumEnteros];

    printf("El numero de enteros a ordenar es: %d\n",NumEnteros); 
    printf("El numero de niveles a ordenar es: %d\n", NumNiveles);
    printf("El nombre del archivo desordenado es: %s\n", file1);
    printf("El nombre del archivo ordenado es: %s\n\n", file2); 
    abrirArchivoEntrada(file1, vector, NumEnteros);
    return 0; 
}