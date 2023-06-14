
#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#define MAXCAPACITY 2
using namespace std;
int buff[MAXCAPACITY];
sem_t pmutex,cmutex,empty, full;
int in=0, out=0;
int item=0;
void *produce(void *);
void *consume(void *);

void *produce(void *arg)
{
    sem_wait(&empty);
    sem_wait(&mutex);
    item++;
    buff[in] = item;
    printf("Produced data %d\n",buff[in]);
    in= (in + 1) % MAXCAPACITY ;
    sem_post(&mutex);
    sem_post(&mayconsume);
    const char *test= "hello";
    return (void*)test;
}

void *consume(void * arg)
{
    int citem=0;
    sem_wait(&mayconsume);
    sem_wait(&mutex);
    citem = buff[out];
    printf(" Consumed Data = %d\n",buff[out]);
    out= (out + 1) % MAXCAPACITY ;
    sem_post(&mutex);
    sem_post(&empty);
    const char *test= "hello";
    return (void*)test;
}

int main(int argc, const char * argv[])
{
    in=0, out=0;
    int i, NumThreads;

    sem_init(&mutex, 0, 1);
//    sem_init(&mutex, 0, 1);
    sem_init(&mayconsume, 0, 0);
    sem_init(&mayproduce, 0, MAXCAPACITY);
    pthread_t * producers, *consumers;
    NumThreads = abs(atoi(argv[1]));
    producers = (pthread_t *) malloc(sizeof(pthread_t) * NumThreads);
    consumers = (pthread_t *) malloc(sizeof(pthread_t) * NumThreads);
    
      for (i = 0; i < NumThreads; i++)
    {
        pthread_create(&producers[i], NULL, &produce, NULL);
        pthread_create(&consumers[i], NULL, &consume, NULL);
   }
    for (i = 0; i < NumThreads; i++)
    {
        void *p=NULL;
        pthread_join(producers[i], &p);
        cout<<(char*)p<<endl;
        pthread_join(consumers[i], &p);
        cout<<(char*)p<<endl;
    }

    return 0;
}

