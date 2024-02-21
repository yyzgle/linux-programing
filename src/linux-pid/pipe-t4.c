#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <sys/wait.h>
void sys_err(const char *str){
    perror(str);
    exit(1);
}
int main(int argc, char *argv[])
{
    int ret,i;
    int fd[2];
    pid_t pid;

    ret = pipe(fd);
    if(ret == -1){
        sys_err("pipe error");
    }
    
    for(i = 0; i< 2; i++){
        pid = fork();
        if(pid == -1){
            sys_err("fork error");
        }
        if(pid == 0){
            break;
        }
    }

    int n;
    char buf[1024];
    if(i == 2){
        close(fd[1]);
        sleep(1);
        n = read(fd[0],buf,1024);
        write(STDOUT_FILENO,buf,n);

        wait(NULL);
        wait(NULL);
    }else if(i == 0){
        close(fd[0]);
        write(fd[1],"1.hello\n",strlen("1.hello\n"));
    }else if(i == 1){
        close(fd[0]);
        write(fd[1],"2.hello\n",strlen("2.hello\n"));
    }

    return 0;
}