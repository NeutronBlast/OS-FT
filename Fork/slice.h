void children(char entrada[], int length, int niveles, int inicio, int op, int fin, char salida[]){
    /*Inicio indica donde va a iniciar cada hijo al cifrar el texto*/
    pid_t child_pid[100], wpid;
    int status = 0;
    pid_t grandchild_pid[100];

    //int nc = length/niveles;
	int finNieto = 0;
    int nietos = 0;


    //printf("A cada proceso hijo le corresponde %d caracteres\n", nc);

    //int nietos = nc/niveles;

    //printf("A cada proceso nieto le corresponde %d caracteres\n",  nietos);

    //int inicionietos = inicio;
	int mult = 1; //Multiplicador
		fin = (mult*(length/niveles))-1;

//Father code (before child processes start)

    for (int progress=0; progress<niveles; progress++) {
if (progress > 0) fin = (mult*(length/niveles))-1;
    for (int id=0; id<1; id++) {
        if ((child_pid[progress] = fork()) == 0) {

            //inicionietos = inicio;

fin = (mult*(length/niveles))-1;
            sleep(progress);
            //printf("Hijo %d empieza en %d\n", progress, inicio);
            //printf("child pid %d   parent pid %d\n",getpid(),getppid());fflush(stdout);
            
                if (progress+1 == niveles){
			fin = length;
                    /*Añadir lo que sobra en caso de division inexacta, si no sobra nada añade 0*/
                    //nc = (length/niveles) + (length%niveles);
                    //printf("Division inexacta, a este ultimo hijo le corresponde %d caracteres\n\n\n\n", nc);
                }
	printf("Hijo comienza en %d , termina en %d , con multiplicador %d\n", inicio, fin ,mult);

		int inicionietos = inicio;
		int multnietos = 1;
        int nc = 0;
        nc = fin-inicio;
                printf("nc %d\n",nc);

            for (int g = 0; g<niveles; g++,inicionietos=finNieto+1,multnietos++){
                if (g == 0) finNieto = (multnietos*(nc/niveles))-1;
                else if (g>0 && g+1 < niveles) finNieto = (multnietos*(nc/niveles));

                if (progress != 0) finNieto = (multnietos*(nc/niveles))+inicio;

                //Nietos
                if ((grandchild_pid[g] = fork()) == 0) {
                //printf("Nieto %d empieza en %d\n", g,inicionietos);
                //printf("child pid %d   parent pid %d\n",getpid(),getppid());fflush(stdout);

                    if (g+1 == niveles){
			finNieto = fin;
                    /*Añadir lo que sobra en caso de division inexacta, si no sobra nada añade 0*/
                    //nietos = (nc/niveles) + (nc%niveles);
                    //printf("Division inexacta, a este ultimo nieto le corresponde %d caracteres\n", nietos);
			
                    }
		printf("Nieto inicia en %d termina en %d con multiplicador %d\n",inicionietos,finNieto,multnietos);

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

                //Each grandchildren takes a different beginning, so first has to wait before creating a second one and so on
                waitpid(grandchild_pid[g],&status,WNOHANG);
                fflush(stdin);
                fflush(stdout);
                exit(0);
                
                }
            }
            while ((wpid = wait(&status)) > 0); // this way, the father waits for all the child processes 
            //All grandchildren pids, saves the one I created last in first position
            for (int q=niveles-1; q>=0; q--) {
                /*do not comment this printf*/
                fflush(stdin);
                fflush(stdout);
                //printf("Saved grandchild %d pid %d\n", q,grandchild_pid[q]);                
            }

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
    //inicio = inicio + nc ;
printf("fin %d\n",fin);
	inicio = fin+1;
printf("nuevo inicio es igual a %d\n", inicio);
	mult++;
    }

while ((wpid = wait(&status)) > 0); // this way, the father waits for all the child processes 
//Father code (After all child processes end)    

/*All children pids, saves and exes in order*/
    for (int p=0; p<niveles; p++) {
        //printf("Saved child %d pid %d\n", p,child_pid[p]);
    } 
        concatChildren(salida,child_pid,niveles);

}
