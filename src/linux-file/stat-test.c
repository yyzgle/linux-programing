#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>
int main(int argc, char *argv[])
{
    struct stat sbuf;
    int ret = stat(argv[1],&sbuf);
    if(ret == -1){
        perror("stat error");
        exit(1);
    }
    printf("file size %ld\n",sbuf.st_size);
    return 0;
}
