#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int fd = open(argv[1],O_RDONLY);
    int newfd = dup(fd);//4
    printf("newfd= %d\n", newfd);
    write(newfd,"1234567",7);
    close(fd);
    return 0;
}
