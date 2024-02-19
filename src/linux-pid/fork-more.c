#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

//循环创建5个进程
//效果
//I'm 1th child
//I'm 2th child
//I'm 3th child
//I'm 4th child
//I'm 5th child
//I'm parent
int main(int argc, char *argv[])
{

    int i;
    pid_t pid;
    for(i=0;i<5;i++){
        pid = fork();
        if(pid == 0){
            break;
        }
    }

    if(5 == i){
        sleep(5);
        printf("I'm parent\n");
    }else{
        printf("I'm %dth child\n", i+1);
    }
    return 0;
}
