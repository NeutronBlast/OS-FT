void children(char entrada[], int length, int niveles, int inicio, int op, int fin, char salida[]){
    /*Inicio indica donde va a iniciar cada hijo al cifrar el texto*/
    pid_t child_pid[100], wpid;
    int status = 0;
    pid_t grandchild_pid[100];
	int finNieto = 0;
    int nietos = 0;

	int mult = 1; //Multiplicador
	fin = (mult*(length/niveles))-1;


    for (int progress=0; progress<niveles; progress++) {
        if (progress > 0) fin = (mult*(length/niveles))-1;

    for (int id=0; id<1; id++) {
        child_pid[progress] = fork();

        if (child_pid[progress]<0){
            perror("Hubo error al hacer el fork\n");
            exit(1);
        }

        if (child_pid[progress] == 0) {
        fin = (mult*(length/niveles))-1;
        sleep(progress);

        //printf("child pid %d   parent pid %d\n",getpid(),getppid());fflush(stdout);
            
        if (progress+1 == niveles){
        /*La ultima division termina cuando se termine el texto en lugar de seguir la formula*/
			fin = length;
        }

	    //printf("Hijo comienza en %d , termina en %d , con multiplicador %d\n", inicio, fin ,mult);

		int inicionietos = inicio;
		int multnietos = 1;
        int nc = 0;
        nc = fin-inicio;
        //printf("Numero de caracteres en nieto %d\n",nc);

        for (int g = 0; g<niveles; g++,inicionietos=finNieto+1,multnietos++){
            if (g == 0) finNieto = (multnietos*(nc/niveles))-1;
            else if (g>0 && g+1 < niveles) finNieto = (multnietos*(nc/niveles));

            if (progress != 0) finNieto = (multnietos*(nc/niveles))+inicio;

            //Nietos
            grandchild_pid[g] = fork();

            if (grandchild_pid[g]<0){
                perror("Hubo error al hacer el fork\n");
                exit(1);
            }
            
            if (grandchild_pid[g] == 0) {
                //printf("child pid %d   parent pid %d\n",getpid(),getppid());fflush(stdout);

            if (g+1 == niveles){
			    finNieto = fin;
            }
		
            //printf("Nieto inicia en %d termina en %d con multiplicador %d\n",inicionietos,finNieto,multnietos);

            if (op == 1){
                grandChildFIle(entrada,getpid(),inicionietos,finNieto,length,1);
            }

            else if (op == 2){
            /*Encriptar en cesar*/
                fflush(stdin);
                fflush(stdout);
                grandChildFIle(entrada,getpid(),inicionietos,finNieto,length,2);
                fflush(stdin);
                fflush(stdout);
            }

                //Se agrega este wait para que cada nieto tome un valor de finNieto distinto, si se quita existe el riesgo de que a dos nietos les toque la misma porcion de texto
                waitpid(grandchild_pid[g],&status,WNOHANG);
                fflush(stdin);
                fflush(stdout);
                exit(0);
                }
            }

            while ((wpid = wait(&status)) > 0); //Cada proceso nivel 1 espera por todos sus hijos antes de continuar

            concatGrandChildren(getpid(), grandchild_pid, niveles);

            
            if (op == 1){
                childFIle(getpid(),fin,op);
            }

            else if (op == 2){
                childFIle(getpid(),fin,op);
            }


            exit(0);
        }

    }
    //printf("fin %d\n",fin);
	inicio = fin+1;
    //printf("nuevo inicio es igual a %d\n", inicio);
	mult++;
    }

while ((wpid = wait(&status)) > 0); // El padre espera que todos los procesos hijos terminen para poder generar el archivo final
    concatChildren(salida,child_pid,niveles);

}
