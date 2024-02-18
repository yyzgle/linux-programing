#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd1 = open(argv[1],O_RDWR);
    printf("fd1= %d\n", fd1);
    //0 被占用，fcntl使用文件描述符表种可用的最小文件描述符返回
    int newfd = fcntl(fd1,F_DUPFD,0);
	printf("newfd= %d\n", newfd);

    // 7,未被占用，返回>=7 的文件描述符
    int newfd2 = fcntl(fd1,F_DUPFD,7);
	printf("newfd2= %d\n", newfd2);
    return 0;
}
