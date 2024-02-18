#include <unistd.h>

int main(int argc, char *argv[])
{
    //创建目录项 硬链接
    link(argv[1],argv[2]);

    // 删除一个文件的目录项
    // unlink(argv[1]);
    return 0;
}