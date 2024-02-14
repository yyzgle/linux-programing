#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char buf[10];
    int fd,n;
    // /dev/tty终端文件
    // 设置非阻塞状态
    fd = open("/dev/tty",O_RDONLY|O_NONBLOCK);
    if(fd < 0){
        perror("open /dev/tty");
        exit(1);        
    }
tryagain:
    n = read(fd,buf,10);
    if(n < 0){
        if(errno != EAGAIN){ //if(errno != EWOULDBLOCK)
            perror("read /dev/tty");
            exit(1);            
        }else{
            write(STDOUT_FILENO,"try again\n",strlen("try again\n"));
            sleep(2);
            goto tryagain;
        }
    }
    write(STDOUT_FILENO,buf,n);
    close(fd);

    return 0;
}
