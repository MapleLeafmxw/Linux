#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define path "/home/mxw/bit/namedpipe/test.txt"
#define size 100

int main()
{
    int fd = open(path, O_RDONLY);
    if(fd < 0)
    {
        printf("open file error!\n");
        return 1;
    }
    char buf[size] = {0};
    while(1)
    {
        int rec = read(fd, buf, sizeof(buf));
        if(rec <= 0)
        {
            printf("read end or error!\n");
            break;
        }
        printf("%s\n", buf);
        sleep(1);
    }
    close(fd);
    return 0;
}
