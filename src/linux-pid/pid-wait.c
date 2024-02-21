#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
    int i;
    pid_t pid;
    for(i = 0; i< 5; i++){
        pid = fork();
        if(pid == 0){
            break;
        }
    }

    if(5 == i){
        wait(NULL);//一次wait/waitpid调用只能回收一个子进程
        printf("I'm parent \n");
    }else{
        sleep(i);
        printf("I'm %dth child \n",i+1);
    }
    return 0;
}