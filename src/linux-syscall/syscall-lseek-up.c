#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

//拓展文件大小
//原来文件大小777->888
// ./test f.c
int main(int argc, char *argv[])
{
    int fd = open(argv[1],O_RDWR);
    if(fd<0){
        perror("open error");
        exit(1);        
    }
    
    //111 文件偏移量
    // SEEK_SET /SEEK_CUR  SEEK_END
    int length = lseek(fd,111,SEEK_END);
    printf("file size:%d\n",length);

    //lseek 拓展文件
    // write(fd,"a",1);
    // 必须引起io操作
    write(fd,"\0",1);

    //od -tcx filename 查看文件16进制标识形式
    //od -tcd filename 10进制
    close(fd);
    return 0;
}