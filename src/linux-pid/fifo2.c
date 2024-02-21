#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    int fd,i;
    char buf[4096];

    if(argc < 2){
        printf("Enter like this: ./a.out fifoname\n");
        return -1;
    }

    fd = open(argv[1],O_WRONLY);
    if(fd == -1){
        perror("fork error");
        exit(1);
    }

    i = 0;
    while(1){
        sprintf(buf,"hello %d\n",i++);
        write(fd,buf,strlen(buf));
        sleep(1);
    }
    close(fd);
    return 0;
}
