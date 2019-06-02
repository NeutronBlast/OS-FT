void concatGrandChildren(char message[], pid_t child, pid_t grandChildren[], int niveles){
    FILE *fp;
    FILE *gc;
    char name [50];
    char texto[50];
    sprintf(name, "%d", child);
    strcat(name,".txt");
    printf("Nombre de archivo hijo es %s\n", name);

    fp = fopen(name, "w");

	for(int inicio; inicio<niveles; inicio++){
        strcpy(name,"");
        sprintf(name, "%d", grandChildren[inicio]);
        strcat(name,".txt");
        gc = fopen(name, "r");
            while (!feof(gc)){
                fgets(texto, 50, gc);
            }
        fclose(gc);
		fprintf(fp, "%s", texto);
	}

    fclose(fp);
}


void grandChildFIle(char message[], pid_t grandChild, int inicio, int nc){
    int fin = inicio+nc;
    int aux = inicio;
    FILE *fp;

    char name [50];
    sprintf(name, "%d", grandChild);
    strcat(name,".txt");
    printf("Nombre de archivo es %s\n", name);

    fp = fopen(name, "w");
	for(inicio; inicio<fin; inicio++){
		fprintf(fp, "%c", message[inicio]);
	}

    fclose(fp);
}


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