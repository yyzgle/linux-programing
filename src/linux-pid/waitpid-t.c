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
    pid_t pid,wpid;
    for(i = 0; i< 5; i++){
        pid = fork();
        if(pid == 0){
            break;
        }
    }

    if(5 == i){
        // wpid = waitpid(-1,NULL,WNOHANG);回收任意子进程，没有结束的子进程，父进程直接返回0

        //指定一个进程回收
        // wpid = waitpid(pid,NULL,0) 阻塞等待
        wpid = waitpid(pid,NULL,WNOHANG);//不阻塞
        if(wpid == -1){
            perror("waitpid error");
            exit(1);
        }

        printf("I'm parent ,wait a child finish: %d\n",wpid);
    }else{
        sleep(i);
        printf("I'm %dth child\n",i+1);
    }

    return 0;
}