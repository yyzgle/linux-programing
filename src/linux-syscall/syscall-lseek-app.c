#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

// lseek用来修改文件偏量(读写位置)
// 普通的打开文件： 打开文件读写位置为0，读写多上个字节就会将读写位置往后移动多少个字节
// O_APPEND方式打开，每次写操作会在文件末尾追加数据，然后将读写位置移动到文件的末尾。
// lseek和标准库I/O的fseek函数类似，可以移动当前读写位置
int main(int argc, char *argv[])
{
    int n;
	char ch;
    char msg[] = "it's a test for lseek \n";

    int fd = open("lseek.txt",O_RDWR|O_CREAT,0644);
    if(fd<0){
        perror("open lseek.txt error");
        exit(1);        
    }
    
    //读写位置位于文件结尾
    write(fd,msg,strlen(msg));

    //修改文件读写指针位置，位于文件开头。
    lseek(fd,0,SEEK_SET);

    while((n=read(fd,&ch,1)) != 0){
        if(n < 0){
            perror("read error");
            break;
        }
        //将文件内容读出，写到屏幕
        write(STDOUT_FILENO,&ch,n);
    }

    close(fd);
    return 0;
}