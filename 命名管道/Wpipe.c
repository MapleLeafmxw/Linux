#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#define path "/home/mxw/bit/namedpipe/test.txt"
#define size 100

int main()
{
    int rec = mkfifo(path, 0666|S_IFIFO);
    if(rec == -1)
    {
        printf("mkfifo error!\n");
        return 1;
    }
    int fd = open(path, O_WRONLY);
    if(fd < 0)
        printf("open error!\n");
    char buf[size];
    while(1)
    {
        scanf("%s", buf);
        int ret = write(fd, buf, strlen(buf)+1);
        if( ret < 0)
        {
            printf("write error!|n");
            break;
        }
    }
    close(fd);
    return 0;
}
