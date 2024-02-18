#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>

//测试步骤
//mkdir tmp
//ls -s tmp tmp.soft
//cat tmp.soft 是一个目录
//ls -l tmp.soft
//./test tmp.soft

#define N 100

//读取连接所指向的文件
int main(int argc, char *argv[])
{
    char buf[N];
    readlink(argv[1],&buf,N);
	printf("%s ",buf);
    return 0;
}
