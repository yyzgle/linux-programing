#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>

// 给定文件名 判定文件类型
// stat 会穿透
// lstat 不会
int main(int argc, char *argv[])
{
    struct stat sbuf;
    int ret = lstat(argv[1],&sbuf);
    if(ret == -1){
        perror("stat error");
        exit(1);
    }

    if(S_ISREG(sbuf.st_mode)){
        printf("it's a regular\n");
    }else if(S_ISDIR(sbuf.st_mode)){
        printf("it's a dir\n");
    }else if(S_ISFIFO(sbuf.st_mode)){
        printf("it's a fifo\n");
    }else if(S_ISLNK(sbuf.st_mode)){
        printf("it's a link\n");
    }
    return 0;
}
