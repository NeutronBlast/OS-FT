void llenarVector(FILE *e, int vector [], int n) {
	for (int i=0; i<n; i++){
		fscanf(e, "%d", &vector[i]);
		printf("value %d\n", vector[i]);
	}

 fclose(e);
}

void abrirArchivoEntrada (char * nombre, int vector[], int n){
    FILE *e;
    e = fopen(nombre, "rb+");
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