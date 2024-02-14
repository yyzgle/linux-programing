#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

//hello world   d\n
int main(int argc, char *argv[])
{
    char buf[10];
    int n;
    //STDIN_FILENO 0
    //STDOUT_FILENO 1
    //STDERR_FILENO 2
    n = read(STDIN_FILENO,buf,10);

    if(n < 0){
        perror("read STDIN_FILENO");
        exit(1);        
    }
    write(STDOUT_FILENO,buf,n);
    return 0;
}
