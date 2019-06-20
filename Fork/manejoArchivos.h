#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef MANEJO_ARCHIVOS_H
#define MANEJO_ARCHIVOS_H

void deleteGarbage(pid_t grandChildren[], int niveles);

void seek (char * nombre, char texto[], int inicio);

void concatChildren(char salida[], pid_t children[], int niveles);

void childFIle(pid_t child, int fin,int op);

void concatGrandChildren(pid_t child, pid_t grandChildren[], int niveles);

void grandChildFIle(char entrada[], pid_t grandChild, int inicio, int fin,int length, int op);

void llenarVector(FILE *e, char texto []);

void replace (char * nombre, char texto[]);

#endif // MANEJO_ARCHIVOS_H