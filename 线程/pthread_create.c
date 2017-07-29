#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* thread_run(void *_val)
{
    printf("%s: pid is %d, tid is %s : %u\n", (char*)_val, (int)getpid()\
            ,(unsigned long long)pthread_self());
    return NULL;
}

int main()
{
    pthread_t tid;
    int err = pthread_create(&tid, NULL, thread_run, "other thread run");
    if(err != 0)
    {
        printf("create thread error!: info is %s\n", strerror(err));
    }
    printf("main thread run : pid is %d, tid is %s : %u\n", (int)getpid()\
            ,(unsigned long long)pthread_self());
    sleep(1);
    return 0;
}
