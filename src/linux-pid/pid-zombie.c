#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

int main(int argc, char *argv[])
{

    pid_t pid = fork();
    if(pid == -1){
        perror("fork error");
        exit(1);
    }else if(pid == 0){
        printf("I'm child : %d\n",getpid());
        sleep(2);
        printf("--child going to die--\n");
    }else if(pid > 0){

        while(1){
            printf("I'm parent pid = %d\n", getpid());
            sleep(1);
        }       
    }

    return 0;
}