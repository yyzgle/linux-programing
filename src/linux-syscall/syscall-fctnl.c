#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char buf[10];
    int flags,n;

    //获取文件状态
    flags = fcntl(STDIN_FILENO,F_GETFL);//获取stdin属性信息
    if(flags == -1){
        perror("fcntl error");
        exit(1);        
    }
    
    flags |= O_NONBLOCK;
    //设置文件状态
    int ret = fcntl(STDIN_FILENO,F_SETFL,flags);
    if(ret == -1){
        perror("fcntl error");
        exit(1);        
    }   

    return 0;
}
