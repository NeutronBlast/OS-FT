void llenarVector(FILE *e, char texto [], int n) {
    int l;
    while (!feof(e)){
        fgets(texto, 1000, e);
    }

    l = strlen(texto);
    printf("%s\n", texto);
    printf("%d\n", l);

 fclose(e);
}

void abrirArchivoEntrada (char * nombre, char texto[], int n){
    FILE *e;
    e = fopen(nombre, "r");
			if (e == NULL) 
				/*Si hay errores en el archivo*/
			{
				printf("Archivo se encuentra vacio o no existe\n");
			}
            else { 
                printf("Archivo cargado con exito\n");    
                llenarVector(e,texto,n);
            }
}