#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

int main(int argc, char *argv[])
{

    int i;
    pid_t pid;
    int var = 100;
    pid = fork();

    if(pid == -1){
        perror("fork error");
        exit(1);
    }else if(pid == 0){
		printf("child,var = %d\n",var);
        var = 3000;
        printf("child,var = %d\n",var);
        printf("I'm child pid=%d, getpid=%d\n",getpid(),getppid());
    }else if(pid > 0){
		sleep(1);
		printf("parent,var = %d\n",var);
        var = 200;
        printf("parent,var = %d\n",var);
        printf("I'm parent pid=%d, getpid=%d\n",getpid(),getppid());
    }

    printf("finish\n");

    return 0;
}
