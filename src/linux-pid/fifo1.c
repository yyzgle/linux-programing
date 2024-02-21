#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <stdio.h>

//mkfifo 管道名
int main(int argc, char *argv[])
{
    int fd,len;
    char buf[4096];

    if(argc < 2){
        printf("Enter like this: ./a.out fifoname\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);
    if(fd == -1){
        perror("fork error");
        exit(1);
    }

    int i = 0;
    while(1){
        len = read(fd,buf,sizeof(buf));
        write(STDOUT_FILENO,buf,len);

        //多个读端要增加睡眠秒数，放大效果
        sleep(3);
    }
    close(fd);
    return 0;
}
