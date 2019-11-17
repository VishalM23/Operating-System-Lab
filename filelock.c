#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
int main(int argc,char * argv[])
{
	int fd;
	char buffer[255];
	struct flock fvar;
	if(argc==1)
	{
		printf("Usage %s filename\n",argv[0]);
		return -1;
	}
	if((fd=open(argv[1],O_RDWR))==-1)
	{
		perror("open");
		exit(1);
	}
	fvar.l_type=F_WRLCK;
	fvar.l_whence=20;
	fvar.l_start=0;
	fvar.l_len=100;
	if((fcntl(fd,F_SETLK,&fvar))==0)
	{
		sleep(20);
	}
	else
	
	{ 
		

	
			fcntl(fd,F_GETLK,&fvar);
			printf("\nFile already locked by process:",fvar.l_pid);
			return -1;
		}
		printf("Press enter to release lock");
		getchar();
		fvar.l_type=F_UNLCK;
		fvar.l_whence=SEEK_SET;
		fvar.l_start=0;
		fvar.l_len=100;
		if((fcntl(fd,F_UNLCK,&fvar))==-1)
		{
			perror("fcntl");
			exit(0);
		}
		printf("Unblocked\n");
		close(fd);
		
	
	return 0;
}
