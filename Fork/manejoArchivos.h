void llenarVector(FILE *e, int vector [], int n) {
	int i = 0, l = 0;
	char placeholder[15];
	char *linea;
	unsigned long int fileLen;




}

void abrirArchivoEntrada (char * nombre, int vector[], int n){
    FILE *e;
    e = fopen(nombre, "rb");
	    if (e == NULL){
		/*Si hay errores en el archivo*/
			    printf("Archivo de enteros desordenados esta vacio o no existe\n");
                system("clear");
        }
        else {
            printf("Archivo de enteros desordenados cargado con éxito\n");
			llenarVector(e,vector,n);
        }        
}