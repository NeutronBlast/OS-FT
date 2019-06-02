#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include "encript.h"
#include "decypher.h"
#include "manejoArchivos.h"
#include "slice.h"


int main(int argc, char *argv[]) {
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

    printf("La operacion es: %s\n",operacion); 
    printf("El numero de enteros a ordenar es: %d\n",NumHijos); 
    printf("El nombre del archivo desordenado es: %s\n", file1);
    printf("El nombre del archivo ordenado es: %s\n\n", file2); 

    abrirArchivoEntrada(file1, vector, NumHijos);

    int i = 1;
    int length = strlen(vector);

    if (operacion[1] == 'd'){
        printf("Toca desencriptar\n");
        op = 1;
    }

    else if (operacion[1] == 'c'){
        printf("Toca encriptar\n");
        op = 2;
    }

    /*Crear arbol de procesos*/
    int inicio=0;
    children(vector,length,NumHijos, inicio, op,file2);

    return 0; 
}