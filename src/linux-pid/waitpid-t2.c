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

        //阻塞方式等待
        // while((wpid = waitpid(pid,NULL,0) != -1){
        //  printf("wait chld %d \n",wpid);
        // }

        //非阻塞方式
        while((wpid = waitpid(-1,NULL,WNOHANG)) != -1){
            if(wpid > 0){
                printf("wait child wpid=%d pid=%d \n",wpid,pid);
            }else if(wpid == 0){
                sleep(1);
                continue;
            }
        }
    }else{
        sleep(i);
        printf("I'm %dth child pid=%d\n",i+1,getpid());
    }

    return 0;
}
