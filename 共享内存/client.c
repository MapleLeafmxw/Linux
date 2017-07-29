#include "comm.h"

int main()
{
    int shmid = getShm();
    char* buf;
    buf = shmat(shmid, NULL, 0);
    int count = 0;
    while(count++ < 15)
    {
        printf("clinet#  %s\n", buf);
        sleep(1);
    }
    shmdt(buf);
    return 0;
}
