#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

// 测试打开文件
int main(int argc, char *argv[])
{
    int fd;
	//rw-r--r--
    fd = open("dict.txt",O_RDONLY|O_CREAT,0644);
    // 结果为 -1
    printf("fd = %d, errno=%d,:%s\n", fd,errno,strerror(errno));
    close(fd);
    return 0;
}