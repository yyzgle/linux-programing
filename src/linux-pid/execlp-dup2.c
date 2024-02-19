#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

//重定向日志到文件中
int main(int argc, char *argv[])
{

    int fd;
    fd = open("ps.out",O_WRONLY|O_CREAT|O_TRUNC,0644);
    if(fd < 0){
        perror("open ps.out error");
        exit(1);
    }

    dup2(fd,STDOUT_FILENO);
    execlp("ps","ps","ax",NULL);

    return 0;
} 