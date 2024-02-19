#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
int main(int argc, char *argv[])
{
    pid_t pid = fork();
    if(pid == -1){
        perror("fork error");
        exit(1);
    }else if(pid == 0){
        //execlp("ls","-l","-d","-h",NULL); 错误写法

        // execlp("ls",ls","-l","-d","-h",NULL);
        // execlp("date","date",NULL);

        // execl("/bin/ls","ls","-l",NULL);

        char *argv[] = {"ls","-l","-h",NULL};
        execvp("ls",argv);
        
        perror("exec error");
        exit(1);
    }else if(pid > 0){
        printf("I'm parent : %d\n",getpid());
        sleep(2);
    }

    return 0;
}