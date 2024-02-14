#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
// 测试fgetc库函数与系统调用的区别
int main(int argc, char *argv[])
{
    FILE *fp,*fp_out;
    int n;
    fp = fopen("dict.txt","r");
    if(fp == NULL){
        perror("fopen error");
        exit(1);
    }
    fp_out = fopen("dict.cp","w");
    if(fp_out == NULL){
        perror("fopen error");
        exit(1);
	}
	//使用n来接收
    while((n=fgetc(fp)) != EOF){
        fputc(n,fp_out);
    }
    fclose(fp);
    fclose(fp_out);
    return 0;
}
