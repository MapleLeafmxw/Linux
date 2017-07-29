#include "comm.h"

static int commShm(int size, int flag)
{
    key_t _key = ftok(pathname, PROJ_ID);
    if(_key < 0)
    {
        perror("ftok");
        return -1;
    }
    int shmid = shmget(_key, size, flag);
    if(shmid < 0)
    {
        perror("shmid");
        return -2;
    }
    return shmid;
}

int createShm()
{
    return commShm(SIZE, IPC_CREAT|IPC_EXCL|0666);
}
int getShm()
{
    return commShm(SIZE, IPC_CREAT);
}

int destroyShm(int shmid)
{
    if(shmctl(shmid, IPC_RMID, NULL) < 0)
    {
        perror("shmctl");
        return -1;
    }
    return 0;
}
