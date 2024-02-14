#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
//make copy
int main(int argc, char *argv[])
{
	if(argc >= 2){
		printf("%d argv1:%s,argv2:%s \n",argc,argv[1],argv[2]);
	}
    char buf[1024];
    int n = 0;
    int fd1 = open(argv[1],O_RDONLY);
    if(fd1 == -1){
        perror("open argv1 error");
        exit(1);
    }
    int fd2 = open(argv[2],O_RDWR|O_CREAT|O_TRUNC,0664);
    if(fd2 == -1){
        perror("open argv2 error");
        exit(1);
    }
    while((n=read(fd1,buf,1024)) != 0){
        if(n < 0){
            perror("read error");
            break;
        }
        //一定要对结果进行判断，否则还不知道哪里出现了错误
        int r = write(fd2,buf,n);
        if(r == -1){
            perror("open argv2 error");
        }
    }
    close(fd1);
    close(fd2);
    return 0;
}
