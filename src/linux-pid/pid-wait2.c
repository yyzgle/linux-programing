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
    int status;
    pid_t pid,wpid;
    pid = fork();
    if(pid == -1){
        perror("fork error");
        exit(1);
    }else if(pid == 0){
        printf("child : %d\n",getpid());
        sleep(3);
        printf("--child die--\n");
        return 10;
    }else if(pid > 0){
        wpid = wait(&status);
        while(wpid == -1){
            perror("fork error");
            exit(1);
        }
        if(WIFEXITED(status)){//为真，说明子进程正常终止
            printf("child exit with %d\n",WEXITSTATUS(status));
        }
        if(WIFSIGNALED(status)){//为真，说明子进程被信号终止
            printf("child exit with signal %d\n",WTERMSIG(status));
        }       
        printf("--parent wait finish\n");
    }
    return 0;
}
