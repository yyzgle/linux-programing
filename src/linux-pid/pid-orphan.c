#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

//孤儿进程
//kill -9 孤儿进程id
int main(int argc, char *argv[])
{

    pid_t pid = fork();
    if(pid == -1){
        perror("fork error");
        exit(1);
    }else if(pid == 0){//子进程
        while(1){
            printf("I'm child, pid=%d ppid = %d\n", getpid(),getppid());
            sleep(1);
        }
    }else if(pid > 0){//父进程
        printf("I'm parent : %d\n",getpid());
        sleep(2);
        printf("--parent going to die--");
    }

    return 0;
}
