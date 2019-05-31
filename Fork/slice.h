void slice(char vector[], int length, int niveles){
        printf("child pid %d   parent pid %d\n",getpid(),getppid());fflush(stdout);
}

void children(char vector[], int length, int niveles){
    pid_t child_pid, wpid;
    int status = 0;

//Father code (before child processes start)
    for (int progress=0; progress<niveles; progress++) {
    for (int id=0; id<1; id++) {
    //Create 2 children
        if ((child_pid = fork()) == 0) {
            slice(vector,length,niveles);
            //child code
            exit(0);
        }
    }
    }

while ((wpid = wait(&status)) > 0); // this way, the father waits for all the child processes 

//Father code (After all child processes end)    
}