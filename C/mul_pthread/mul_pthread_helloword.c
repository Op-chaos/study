#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <pthread.h>
#include <stdlib.h>


#define NUMBER_OF_THREADS 10


int static count = 0;

void *print_hello_world(void *tid)
{
    printf ("Hello world. Greetings from thread %lu \n",pthread_self()); 
    count++;
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
       
        pthread_t threads[NUMBER_OF_THREADS];
        int status, i;
        for(i = 0; i < NUMBER_OF_THREADS; i++)
        {
            printf ("Main here. Creating thread %d\n",i);
            status = pthread_create(&threads[i], NULL, print_hello_world,(void*)(long)i); //64λ���� intתָ�����ͻ�澯������תΪlong��64λ����ָ��λ�����

            if(status != 0)
            {
                printf ("Oops. pthread_create returned error code %d\n",status);
                exit(-1);
            }
        }
        printf("\n");
        for(i = 0; i < NUMBER_OF_THREADS; i++)
        {
            pthread_join(threads[i], NULL);
            printf ("Thread %d ended!\n",i);
        }
        printf ("count=%d\n",count);
        return 0;
}