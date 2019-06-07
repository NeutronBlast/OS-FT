void deleteGarbage(pid_t grandChildren[], int niveles){
    /*Eliminar archivos hijos y nietos*/
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
    /*Leer archivo desde var inicio hasta fin*/
    FILE *e;
    e = fopen(nombre, "r");

	if (e == NULL) 
	/*Si hay errores en el archivo*/
	{
        perror("No fue posible abrir el archivo \n");
        exit(0);
	}

    else { 
        fseek(e,inicio,SEEK_SET);
        fgets(texto,1500,e);
    }

    fclose(e);
}

void concatChildren(char salida[], pid_t children[], int niveles){
    /*Concatenar archivos hijos para generara ArchivoSalidaConTexto*/
    FILE *fp;
    FILE *gc;
    char texto[1500];
    char name[50];

    fp = fopen(salida, "w");


    if (fp == NULL) 
	/*Si hay errores en el archivo*/
    {
        perror("No fue posible abrir el archivo de salida\n");
        exit(0);
	}

	for(int inicio = 0; inicio<niveles; inicio++){
        strcpy(name,"");
        sprintf(name, "%d", children[inicio]);
        strcat(name,".txt");
        gc = fopen(name, "r");


    if (gc == NULL) 
	/*Si hay errores en el archivo*/
    {
        perror("No fue posible abrir el archivo hijo\n");
        exit(0);
	}

        fgets(texto, 1500, gc);
        fclose(gc);
		fprintf(fp, "%s", texto);
	}

    fclose(fp);
    fprintf(fp, "%c", '\0');
    deleteGarbage(children,niveles);

}

void childFIle(pid_t child, int fin,int op){
    /*Crear archivos hijos*/
    FILE *fp;

    char name [50];
    char texto [500];
    sprintf(name, "%d", child);
    strcat(name,".txt");

    fp = fopen(name, "r");


    if (fp == NULL) 
	/*Si hay errores en el archivo*/
    {
        perror("No fue posible abrir el archivo\n");
        exit(0);
	}

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
    /*Concatenar archivos nietos para que los procesos de nivel 1 lo reciban y encriptar o desencriptar el texto nuevamente*/
    FILE *fp;
    FILE *gc;
    char name [50];
    char texto[1500];
    sprintf(name, "%d", child);
    strcat(name,".txt");
    fp = fopen(name, "w");

    if (fp == NULL) 
	/*Si hay errores en el archivo*/
    {
        perror("No fue posible abrir el archivo hijo\n");
        exit(0);
	}

	for(int inicio=0; inicio<niveles; inicio++){
        strcpy(name,"");
        sprintf(name, "%d", grandChildren[inicio]);
        strcat(name,".txt");
        gc = fopen(name, "r");


        if (gc == NULL) 
        /*Si hay errores en el archivo*/
        {
            perror("No fue posible abrir el archivo nieto\n");
            exit(0);
        }
        fgets(texto, 1400, gc);
        fclose(gc);

        //printf("Nombre de archivo hijo es %s\n", name);
		fprintf(fp, "%s", texto);
        strcpy(texto,"");

	}
	fprintf(fp, "%c", '\0');
    fclose(fp);
    deleteGarbage(grandChildren,niveles);
    
}


void grandChildFIle(char entrada[], pid_t grandChild, int inicio, int fin,int length, int op){
    /*Crear archivos de procesos nivel 2*/
    int aux = inicio;
    FILE *fp;
    char message[1500];
    int nc = fin-inicio;
    int i = 0;

    char name [50];
    sprintf(name, "%d", grandChild);
    strcat(name,".txt");
    //printf("Nombre de archivo es %s\n", name);

    //Lee archivo de entrada desde var inicio
    seek(entrada,message,inicio);
    fp = fopen(name, "w");

    if (fp == NULL){
        perror("Hubo un error al abrir el archivo nieto\n");
        exit(1);        
    }

    if (op == 2)
        encriptar(message,0,fin);

    else
        desencriptarM(message,0,fin);

    /*Escribir texto encriptado/desencriptado hasta donde fin lo indique (nc depende de fin)*/
	for(i = 0; i<=nc; i++){
		fprintf(fp, "%c", message[i]);
	}

    if (length == i)
        fprintf(fp, "%c", message[i]);

    /*Escribir el caracter nulo para evitar generar archivos con basura*/
        fprintf(fp, "%c", '\0');

    fclose(fp);
}


void llenarVector(FILE *e, char texto []) {
    int l;
        fgets(texto, 1000, e);

    l = strlen(texto);
 fclose(e);
}

void abrirArchivoEntrada (char * nombre, char texto[]){
    FILE *e;
    e = fopen(nombre, "r");
			if (e == NULL) 
				/*Si hay errores en el archivo*/
			{
                perror("No fue posible abrir el archivo de entrada\n");
                exit(0);
			}
            else { 
                //printf("Archivo cargado con exito\n");    
                llenarVector(e,texto);
            }
}

void replace (char * nombre, char texto[]){
    FILE *e;
    e = fopen(nombre, "w");
    		if (e == NULL) 
				/*Si hay errores en el archivo*/
			{
                perror("No fue posible abrir el archivo de entrada\n");
                exit(0);
			}
			if (e != NULL) 
			{
				int f = removeSpace(texto,strlen(texto));
                fprintf(e,"%s",texto);
			}
    fclose(e);
    }
