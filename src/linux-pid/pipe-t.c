#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

void sys_err(const char *str){
    perror(str);
    exit(1);
}

int main(int argc, char *argv[])
{
    int ret;
    int fd[2];
    pid_t pid;

    char *str = "hello pipe\n";
    char buf[1024];

    ret = pipe(fd);
    if(ret == -1){
        sys_err("pipe error");
    }
    
    pid = fork();
    //fd[1] - > fd[0]
    if(pid > 0){
        close(fd[0]);//父进程 关闭读端
        write(fd[1],str,strlen(str));
        sleep(1);
        close(fd[1]);
    }else if(pid == 0){
        close(fd[1]);//子进程关闭写端
        ret = read(fd[0],buf,sizeof(buf));
        write(STDOUT_FILENO,buf,ret);
        close(fd[0]);
    }
    return 0;
}