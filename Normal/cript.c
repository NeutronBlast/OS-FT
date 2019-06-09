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


int main(int argc, char *argv[]) {
    setlocale(LC_ALL,"");
    struct timeval begin, end;
    gettimeofday(&begin,NULL);
    /*Tomar los argumentos de la linea de comando*/
    int op = 0;

    /*Encriptar o desencriptar*/
    size_t len = strlen(argv[1]);
    char * operacion = malloc(len+2);
    strcpy(operacion, argv[1]);

 
    len = strlen(argv[2]);
    /*Nombre archivo de entrada*/
    char * file1 = malloc(len+5);
    strcpy(file1, argv[2]);
    strcat(file1,".txt");

    /*Texto a encriptar o desencriptar*/
    char vector [1000];

    abrirArchivoEntrada(file1, vector);

    int i = 1;

    int length = strlen(vector);
  
    if (operacion[1] == 'd'){
        /*Toca desencriptar*/
        op = 1;
    }

    else if (operacion[1] == 'c'){
        /*Toca encriptar*/
        op = 2;
    }

    int inicio=0;
    int fin = 0;
    if (op == 2){
        length = removeSpace(vector,length)-2;
        encriptar(vector,inicio,length);
        encriptarM(vector,inicio,length);
    }
    else{
        length = strlen(vector);
        desencriptarM(vector,inicio,length);
        desencriptar(vector,inicio,length);
    }

    replace(file1,vector);

    gettimeofday(&end,NULL);

    printf("Fin del programa, tiempo total de ejecucion %f segundos\n", (double)(end.tv_usec - begin.tv_usec)/1000000+ (double)(end.tv_sec - begin.tv_sec)) ;
    return 0; 
}
