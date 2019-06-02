void concatChildren(char message[], char salida[], pid_t children[], int niveles){
    FILE *fp;
    FILE *gc;
    char texto[1500];
    char name[50];

    fp = fopen(salida, "w");

	for(int inicio; inicio<niveles; inicio++){
        strcpy(name,"");
        sprintf(name, "%d", children[inicio]);
        strcat(name,".txt");
        gc = fopen(name, "r");
            while (!feof(gc)){
                fgets(texto, 1500, gc);
            }
        fclose(gc);
		fprintf(fp, "%s", texto);
	}

    fclose(fp);
}

void childFIle(char message[], pid_t child, int nc){
    int fin = nc;
    FILE *fp;

    char name [50];
    char texto [500];
    sprintf(name, "%d", child);
    strcat(name,".txt");

    fp = fopen(name, "r");
     while (!feof(fp)){
        fgets(texto, 500, fp);
    }

    encriptarM(texto,0,nc);    
    fclose(fp);

    fp = fopen(name,"w");
	for(int inicio = 0; inicio<=fin; inicio++){
		fprintf(fp, "%c", texto[inicio]);
	}

    fclose(fp);
}

void concatGrandChildren(char message[], pid_t child, pid_t grandChildren[], int niveles){
    FILE *fp;
    FILE *gc;
    char name [50];
    char texto[50];
    sprintf(name, "%d", child);
    strcat(name,".txt");
    //printf("Nombre de archivo hijo es %s\n", name);

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
    //printf("Nombre de archivo es %s\n", name);

    fp = fopen(name, "w");
	for(inicio; inicio<=fin; inicio++){
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