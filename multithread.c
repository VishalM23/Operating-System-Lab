#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>
int count[3],a[100][100];
int isprime(int);
void *primemat(void *param)
{
	int n=(int)param;
	int i,j;
	for(i=0;i<3;i++)
		if(isprime(a[n][i]))
				count[n]++;
	pthread_exit(0);
	
}




int isprime(int n)
{
	int i;
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
			return 0;
		exit(0);
	}
	return 1;
}


void main(int argc,char * argv[])
{
	int n,i,j;
	pthread_t tid[3];
	pthread_attr_t attr[3];
	printf("Enter 3*3 matrix:");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<3;i++)
			count[i]=0;
	for(i=0;i<3;i++)
	{
		pthread_attr_init(&attr[i]);
	}
	for(i=0;i<3;i++)
		pthread_create(&tid[i],&attr[i],primemat,(void *)i);
	for(i=0;i<3;i++)
		pthread_join(tid[i],NULL);
	printf("shjd");
	for(i=0;i<3;i++)
		printf("%d",count[i]);
	
}

