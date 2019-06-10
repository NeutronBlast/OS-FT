typedef struct data_t{
    int finNieto;
    int nietos;
    int mult;
    int fin;
	int inicionietos;
    int nietoP;
	int multnietos;
    int nc;
    int op;
    int niveles;
    int length;
    int inicio;
    int progress;
    char * texto;
    }data;

sem_t end;
sem_t Echild;
sem_t endGC;
sem_t Egc;
sem_t x;

void * grandChild(void *arg){
    sem_wait(&Egc);
    data* dat = (data*)arg;
    pthread_t grandChildren[dat->niveles];
    printf("Hi, soy el nieto %d, mi inicio es %d, termino en %d, con multiplicador %d opcion %d\n",dat->nietoP,dat->inicionietos,dat->finNieto,dat->multnietos,dat->op);

    if (dat->nietoP+1 == dat->niveles){
    dat->finNieto = dat->length;
    }

    if (dat->op == 2)
    encriptar(dat->texto,dat->inicionietos,dat->finNieto);

    else if (dat->op == 1)
    desencriptarM(dat->texto,dat->inicionietos,dat->finNieto);

    printf("Mi texto es %s\n\n",dat->texto);
    sem_post(&x);
    sem_post(&Egc);

    pthread_exit(NULL);

}

void * child(void *arg){
    sem_wait(&Echild);
    data* dat = (data*)arg;
    pthread_t grandChildren[dat->niveles];
    data d2 [dat->niveles];
    printf("Hi, soy el hijo %d, mi inicio es %d, termino en %d, con multiplicador %d y op %d\n\n",dat->progress,dat->inicio,dat->fin,dat->mult,dat->op);


     for (int progress=0; progress<dat->niveles; progress++,
     dat->multnietos++, dat->inicionietos=dat->finNieto+1
    ,dat->nc=dat->fin-dat->inicio,dat->finNieto=(dat->multnietos*(dat->nc/dat->niveles))-1){
        dat->finNieto=dat->inicio+(dat->multnietos*(dat->nc/dat->niveles))-1;
        if (progress+1 == dat->niveles) dat->finNieto = dat->fin;
        //printf("Test for nieto %d, mi inicio es %d, termino en %d, con multiplicador %d\n",progress,dat->inicionietos,dat->finNieto,dat->multnietos);
        sem_wait(&x);
        d2[progress].nietos = dat->nietos;
        d2[progress].mult = dat->mult;
        d2[progress].fin = dat->fin;
        d2[progress].niveles = dat->niveles;
        d2[progress].inicionietos = dat->inicionietos;
        d2[progress].multnietos = dat->multnietos;
        d2[progress].nc = dat->nc;
        d2[progress].texto = dat->texto;
        d2[progress].op = dat->op;
        d2[progress].length = dat->length;
        d2[progress].inicio = dat->inicio;
        d2[progress].nietoP = progress;
        d2[progress].finNieto = dat->finNieto;

 
        pthread_create(&grandChildren[progress],NULL,&grandChild,(void*)&d2[progress]);
        pthread_join(grandChildren[progress],NULL);
    }
    
    if (dat->op == 2)
    encriptarM(dat->texto,dat->inicio,dat->fin);

    else if (dat->op == 1)
    {
        desencriptar(dat->texto,dat->inicio,dat->fin);
    }
    
    printf("Mi texto es %s\n\n",dat->texto);

    if (dat->progress == 0)
        sem_post(&end);

    sem_post(&Echild);
    pthread_exit(NULL);

}


void hilos(char texto[],int length,int niveles, int inicio, int op, int fin,  char salida[]){
    sem_init(&end,0,0);
    sem_init(&Echild,0,1);
    sem_init(&Egc,0,1);
    sem_init(&x,0,1);
    
    pthread_t children[niveles];
    int nietos = 0;
    int mult = 1;
	int inicionietos = inicio;
	int multnietos = 1;
    fin = (mult*(length/niveles))-1;
    int nc = fin-inicio;
    int finNieto = 0;


    data d [niveles];
    for (int progress=0; progress<niveles; progress++, mult++, inicio=fin+1,fin=(mult*(length/niveles))-1
    ,nc=fin-inicio) {

    finNieto = (multnietos*(nc/niveles))-1;

        if (progress+1 == niveles) fin = length;
        d[progress].finNieto = finNieto;
        d[progress].nietos = nietos;
        d[progress].mult = mult;
        d[progress].fin = fin;
        d[progress].niveles = niveles;
        d[progress].inicionietos = inicio;
        d[progress].multnietos = multnietos;
        d[progress].nc = nc;
        d[progress].texto = texto;
        d[progress].op = op;
        d[progress].length = length;
        d[progress].inicio = inicio;
        d[progress].progress = progress;
        

        pthread_create(&children[progress],NULL,&child,(void*)&d[progress]);
        pthread_join(children[progress],NULL);

        }
    

    sem_wait(&end);
    printf("Fin del programa\n");
    printf("Texto es %s\n",texto);
    sem_destroy(&end);
    sem_destroy(&endGC);
    sem_destroy(&Egc);
    sem_destroy(&Echild);

    /* for (int progress=0; progress<niveles; progress++) {
        pthread_join(children[progress],NULL);
        printf("Termino el thread %ld\n",children[progress]);    
    }*/
}