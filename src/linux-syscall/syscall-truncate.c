#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

//int fd = open(argv[1],O_RDWR);
//int length = lseek(fd,111,SEEK_END);
//write(fd,"\0",1);
int main(int argc, char *argv[])
{
    
    int ret = truncate("dict.cp",250);
    return 0;
}
