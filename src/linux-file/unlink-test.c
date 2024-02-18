#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>
//测试步骤
int main(int argc, char *argv[])
{
    int fd;
    char *p = "test of unlink\n";
    char *p2 = "after write something.\n";
    fd = open("temp.txt",O_RDWR|O_CREAT|O_TRUNC,0644);
    if(fd<0){
        perror("open error");
        exit(1);        
    }       
    int ret = unlink("temp.txt");//具备了被释放的条件
    if(ret < 0){
        perror("unlin error");
        exit(1);        
    }   

    ret = write(fd,p,strlen(p));
    if(ret == -1){
        perror("--write error");
        exit(1);        
    }   
    //制造错误条件
    // p[0] = 'H';

    printf("hi,I'm printf\n");
    ret = write(fd,p2,strlen(p2));
    if(ret == -1){
        perror("--write error");
        exit(1);        
    }   
    printf("enter anykey continue\n");
    getchar();

    close(fd);
    ret = unlink("temp.txt");
    if(ret<0){
        perror("unlin error");
        exit(1);        
    }
    return 0;
}
