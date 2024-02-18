#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/sysmacros.h>

#define PATH_LEN 256

void fetchdir(const char *dir, void (*func)(char *)){
    char name[PATH_LEN];
    struct dirent *sdp; 
    struct DIR *dp;
    dp = opendir(dir);
    if(dp == NULL){
        perror("open t error");
        exit(1);        
    }

    while((sdp = readdir(dp)) != NULL){
        //防止出现无线递归
        if(strcmp(sdp->d_name,".") == 0 || strcmp(sdp->d_name,"..") == 0){
            continue;
        }
        printf("%s \n", sdp->d_name);

        // isFile(path);
        // 判断文件类型，目录递归进入，文件显示名字/大小
        sprintf(name,"%s/%s", dir,sdp->d_name);
        (*func)(name);
    }

    closedir(dp);   
}

//处理文件/目录
void isFile(char *name){
    struct stat sbuf;
    if(stat(name,&sbuf) == -1){//文件名无效
        fprintf(stderr,"isFile: can't access %s\n",name);
        exit(1);
    }
    if((sbuf.st_mode & S_IFMT) == S_IFDIR){//判定是否为目录
        fetchdir(name,isFile);
    }

    //不是目录，则是普通文件，直接打印文件名
    printf("%8ld %s\n", sbuf.st_size,name);
}

//while循环递归
int main(int argc, char *argv[])
{

    //判断命令行参数
    if(argc == 1){
        isFile(".");
    }else{
        while(--argc > 0){//可一次查询多个目录
            isFile(*++argv);//循环调用该函数处理各个命令行传入的目录
        }
    }
    return 0;
}