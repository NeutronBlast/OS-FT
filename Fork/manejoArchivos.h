void deleteGarbage(pid_t grandChildren[], int niveles){
    FILE *fp;
    char name [50];
    int status, f;

    for(int inicio=0; inicio<niveles; inicio++){
        sprintf(name, "%d", grandChildren[inicio]);
        strcat(name,".txt");
        status = remove(name);
    }
}

void seek (char * nombre, char texto[], int inicio){
    FILE *e;
    e = fopen(nombre, "r");
			if (e == NULL) 
				/*Si hay errores en el archivo*/
			{
				printf("Archivo se encuentra vacio o no existe\n");
			}
            else { 
                //printf("Archivo cargado con exito\n");    
                fseek(e,inicio,SEEK_SET);
                fgets(texto,1500,e);
            }
    fclose(e);
}

void concatChildren(char salida[], pid_t children[], int niveles){
    FILE *fp;
    FILE *gc;
    char texto[1500];
    char name[50];

    fp = fopen(salida, "w");

	for(int inicio = 0; inicio<niveles; inicio++){
        strcpy(name,"");
        sprintf(name, "%d", children[inicio]);
        strcat(name,".txt");
        gc = fopen(name, "r");
                fgets(texto, 1500, gc);
        fclose(gc);
		fprintf(fp, "%s", texto);
	}

    fclose(fp);
    fprintf(fp, "%c", '\0');
    deleteGarbage(children,niveles);

}

void childFIle(pid_t child, int fin,int op){
    FILE *fp;

    char name [50];
    char texto [500];
    sprintf(name, "%d", child);
    strcat(name,".txt");

    fp = fopen(name, "r");
        fgets(texto, 500, fp);

    if (op == 2)
        encriptarM(texto,0,fin);
    
    else
    {
        desencriptar(texto,0,fin);
    }
    
    
    fclose(fp);

    fp = fopen(name,"w");
	for(int inicio = 0; inicio<=fin; inicio++){
		fprintf(fp, "%c", texto[inicio]);
	}

    fclose(fp);
}


void concatGrandChildren(pid_t child, pid_t grandChildren[], int niveles){
    FILE *fp;
    FILE *gc;
    char name [50];
    char texto[1500];
    sprintf(name, "%d", child);
    strcat(name,".txt");
    fp = fopen(name, "w");

	for(int inicio=0; inicio<niveles; inicio++){
        strcpy(name,"");
        sprintf(name, "%d", grandChildren[inicio]);
        strcat(name,".txt");
        gc = fopen(name, "r");
        fgets(texto, 1400, gc);
        fclose(gc);

        //printf("Nombre de archivo hijo es %s\n", name);
        printf("texto intermedio es %s\n",texto);
		fprintf(fp, "%s", texto);
        strcpy(texto,"");

	}
	fprintf(fp, "%c", '\0');
    fclose(fp);
    deleteGarbage(grandChildren,niveles);
    
}


void grandChildFIle(char entrada[], pid_t grandChild, int inicio, int fin,int length, int op){
    int aux = inicio;
    FILE *fp;
    char message[1500];
    int nc = fin-inicio;
    int i = 0;

    char name [50];
    sprintf(name, "%d", grandChild);
    strcat(name,".txt");
    //printf("Nombre de archivo es %s\n", name);

    seek(entrada,message,inicio);
    fp = fopen(name, "w");
    if (op == 2)
        encriptar(message,0,fin);

    else
        desencriptarM(message,0,fin);

	for(i = 0; i<=nc; i++){
		fprintf(fp, "%c", message[i]);
	}

    if (length == i)
        fprintf(fp, "%c", message[i]);
            fprintf(fp, "%c", '\0');



    fclose(fp);
}


void llenarVector(FILE *e, char texto []) {
    int l;
        fgets(texto, 1000, e);

    l = strlen(texto);
    //printf("%s\n", texto);
    //printf("%d\n", l);

 fclose(e);
}

void abrirArchivoEntrada (char * nombre, char texto[]){
    FILE *e;
    e = fopen(nombre, "r");
			if (e == NULL) 
				/*Si hay errores en el archivo*/
			{
				printf("Archivo se encuentra vacio o no existe\n");
			}
            else { 
                //printf("Archivo cargado con exito\n");    
                llenarVector(e,texto);
            }
}

void replace (char * nombre, char texto[]){
        FILE *e;
    e = fopen(nombre, "w");
			if (e != NULL) 
			{
				int f = removeSpace(texto,strlen(texto));
                fprintf(e,"%s",texto);
			}
    fclose(e);
    }
