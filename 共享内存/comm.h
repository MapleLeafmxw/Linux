#ifndef _COMM_H_
#define _COMM_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#define pathname "."
#define PROJ_ID 0x6666
#define SIZE 4095 

int createShm();
int getShm();
int destroytshm(int shmid);

#endif
