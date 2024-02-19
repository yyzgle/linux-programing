#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
int main(int argc, char *argv[])
{

    printf("befork fork\n");

    pid_t pid = fork();
    if(pid == -1){
        perror("fork error");
        exit(1);
    }else if(pid == 0){
        printf("child,  pid= %d,p pid=%d \n",getpid(),getppid());
    }else if(pid > 0){
        printf("parent, child's pid= %d, pid= %d,parent-pid=%d\n",pid,getpid(),getppid());
    }

    printf("finish\n");
    return 0;
}
