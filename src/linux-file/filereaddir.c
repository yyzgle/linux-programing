#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

//读取目录
int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *sdp;
    dp = opendir(argv[1]);
    if(dp == NULL){
        perror("open t error");
        exit(1);        
    }

    while((sdp = readdir(dp)) != NULL){
        if(strcmp(sdp->d_name,".") == 0){
            continue;
        }
        printf("%s\n", sdp->d_name);
    }
    closedir(dp);
    return 0;
}
