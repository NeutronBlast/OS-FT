void slice(char vector[], int length, int niveles){
        printf("child pid %d   parent pid %d\n",getpid(),getppid());fflush(stdout);
}


void children(char vector[], int length, int niveles){
    pid_t child_pid[100], wpid;
    int status = 0;
    pid_t grandchild_pid[100];

//Father code (before child processes start)
    for (int progress=0; progress<niveles; progress++) {
    for (int id=0; id<1; id++) {
        if ((child_pid[progress] = fork()) == 0) {
            sleep(progress);
            slice(vector,length,niveles);
            for (int g = 0; g<niveles; g++){
                //Nietos
                if ((grandchild_pid[g] = fork()) == 0) {
                slice(vector,length,niveles);
                exit(0);
                }
            }
            while ((wpid = wait(&status)) > 0); // this way, the father waits for all the child processes 
            /*All grandchildren pids, saves the one I created last in first position
            for (int q=0; q<niveles; q++) {
                printf("Saved grandchild %d pid %d\n", q,grandchild_pid[q]);
            } */
            exit(0);
        }
    }
    }

while ((wpid = wait(&status)) > 0); // this way, the father waits for all the child processes 
//Father code (After all child processes end)    

/*All children pids, saves and exes in order
    for (int p=0; p<niveles; p++) {
        printf("Saved child %d pid %d\n", p,child_pid[p]);
    } */


}