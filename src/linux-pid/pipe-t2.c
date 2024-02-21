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

    ret = pipe(fd);
    if(ret == -1){
        sys_err("pipe error");
    }
    
    pid = fork();
    //fd[1] - > fd[0]
    if(pid > 0){
        close(fd[1]);
        dup2(fd[0],STDIN_FILENO);
        execlp("wc","wc","-l",NULL);

        sys_err("execlp wc error");
    }else if(pid == 0){
        close(fd[0]);
        dup2(fd[1],STDOUT_FILENO);
        execlp("ls","ls",NULL);

        sys_err("execlp LS error");
    }else{
        sys_err("fork error");
    }
    return 0;
}
