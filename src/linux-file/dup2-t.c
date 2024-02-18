#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int fd1 = open(argv[1],O_RDWR);
	int fd2 = open(argv[2],O_RDWR);

    int fdret = dup2(fd1,fd2);
    printf("fdret= %d\n", fdret);

    int ret = write(fd2,"1234567",7);
    printf("ret= %d\n", ret);

    dup2(fd1,STDOUT_FILENO);
    printf("-----------\n");

    close(fd1);
    close(fd2);
    return 0;
}
