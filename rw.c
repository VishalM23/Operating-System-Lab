#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<sys/types.h>
int readcount=0,data=0;
sem_t mutex,wrt;
void *reader(void * param);
void *writer(void * param);
int main()
{
	sem_init(&mutex,0,1);
	sem_init(&wrt,0,1);
	pthread_t rid[10];
	pthread_t wid[10];
	int i;
	for(i=0;i<10;i++)
	{
		pthread_create(&rid[i],NULL,reader,(void *)i);
		pthread_create(&wid[i],NULL,writer,(void *)i);
	}
	for(i=0;i<10;i++)
	{
		pthread_join(rid[i],NULL);
		pthread_join(wid[i],NULL);
	}
	sem_destroy(&wrt);
	sem_destroy(&mutex);
}
void * reader(void * a)
{
	int k=(int)k;
	sem_wait(&mutex);
	readcount++;
	if(readcount==1)
		sem_wait(&wrt);
	sem_post(&mutex);
	printf("Reader %d is reading data as %d\n",k,data);
	sem_wait(&mutex);
	readcount--;
	if(readcount==0)
		sem_post(&wrt);
	sem_post(&mutex);
}
void * writer(void * param)
{
	int w=(int)param;
	sem_wait(&wrt);
	data++;
	printf("Writer %d has increased data to %d", w,data);
	sem_post(&wrt);
}


