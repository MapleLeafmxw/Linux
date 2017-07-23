#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


int main()
{
    int _pipe[2];
    int ret = pipe(_pipe);
    if(ret == -1)
    {
        printf("create pipe eror!");
        return 1;
    }
    pid_t id = fork();
    if(id < 0)
    {
        perror("fork");
        return 2;
    }
    else if(id == 0)
    {
        close(_pipe[0]);
        int i = 0;
        char *msg = "My dream is you!";
        while(i < 20)
        {
            if(i < 20)
            {
                write(_pipe[1], msg, strlen(msg)+1);
                //printf("%s\n", msg);
            }
                sleep(1);
                i++;
        }
        //close(_pipe[1]);
    }
    else
    {
        close(_pipe[1]);
        char msg[100];
        memset(msg, '\0', sizeof(msg));
        int j = 0;
        while(j < 3)
        {
            ssize_t rec = read(_pipe[0], msg, sizeof(msg));
            //printf("%s\n", msg);
            printf("%s: code is %d\n", msg, rec);
            j++;
        }
        close(_pipe[0]);
        sleep(10);
        if(waitpid(id, NULL, 0)<0)
            return 3;
    }
    return 0;
}
