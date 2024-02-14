#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define N 1024
int main(int argc, char *argv[])
{
    int fd,fd_out;

    int n = 0;
    char buf[N];
    fd = open("dict.txt",O_RDONLY);
    if(fd == -1){
        perror("open argv1 error");
        exit(1);
    }
    fd_out = open("dict.cp", O_WRONLY | O_CREAT | O_TRUNC,0664);
    if(fd_out == -1){
        perror("open argv2 error");
        exit(1);
    }
    while((n=read(fd,buf,N)) != 0){
        if(n < 0){
            perror("read error");
            break;
        }
        int r = write(fd_out,buf,n);
        if(r == -1){
            perror("write error");
        }
    }
    close(fd);
    close(fd_out);
    return 0;
}
