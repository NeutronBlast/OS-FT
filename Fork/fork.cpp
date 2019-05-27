#include <stdio.h>
#include <stdlib.h>

struct nodo {
	int valor;
	nodo *izq, *der;
};

nodo *crear(int x) {
	nodo *temp = new nodo;
	temp->valor = x;
	temp->izq = NULL,
		temp->der = temp->izq;
	return temp;
}

void insertar(nodo **p, int x) {
	if (!(*p))
		*p = crear(x);
	else if ((*p)->valor > x)
		insertar(&((*p)->izq), x);
	else if ((*p)->valor < x)
		insertar(&((*p)->der), x);
	else {
		printf(" No se pueden insertar claves repetidas \n\n");
        system("read -p 'Presiona enter para continuar...' var");
	}
}

void  preorden(nodo * p) {
	if (p) {
		printf(" %i ", p->valor);
		preorden(p->izq);
		preorden(p->der);
	}
}


int main() {
	int op = -1, n = 0, g = 0;
	nodo *p = NULL;
	while (1 == 1) {
		system("cls");
		printf("\n\n        Menu Principal Arboles ABB\n\n    1. Insertar dato en arbol\n");
		printf("    2. Imprimir en preorden \n");
			printf("    0. Salir\n\n Marque opcion =>");
		scanf_s("%i", &op);
		system("clear");

		switch (op) {
		case 1: printf("\n\n    1. Agregar dato\n\n");
			printf(" Valor a agregar = ");
			scanf_s("%i", &n);
			insertar(&p, n);
			printf("\n\n  Valor agregado\n\n");
			break;
		case 2: printf("\n\n    2. Mostrar\n\n");
			preorden(p);
			break;
		case 0:
        break;
		default:
			printf("Opcion NO Valida ... intente de nuevo");
			break;
		}
		if (!(op)) break;
	}
}