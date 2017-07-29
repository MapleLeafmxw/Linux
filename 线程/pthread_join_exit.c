#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread1(void* _val)
{
    printf("thread 1 returning ...\n");
    return (void*)1;
}
void* thread2(void* _val)
{
    printf("thread 2 exiting....\n");
    pthread_exit((void*)2);
}
void* thread3(void* _val)
{
    while(1)
    {
        printf("pthread 3 is runninng, wait for be cancal..\n");
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t tid;
    void* tret;
    //pthread 1 return 
    pthread_create(&tid, NULL, thread1, NULL);
    pthread_join(tid, &tret);
    printf("thread return, thread id is : %u, return code is: %d\n",\
            (unsigned long long)tid, (int)tret);
    //pthread 2 exit
    pthread_create(&tid, NULL, thread2, NULL);
    pthread_join(tid, &tret);
    printf("thread return, thread id is : %u, return code is: %d\n",\
            (unsigned long long)tid, (int)tret);
    //pthread 3 cancel by other 
    pthread_create(&tid, NULL, thread3, NULL);
    sleep(3);
    pthread_cancel(tid);
    pthread_join(tid, &tret);
    printf("thread return, thread id is : %u, return code is: %d\n",\
            (unsigned long long)tid, (int)tret);
    return 0;
}
