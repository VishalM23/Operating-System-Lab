#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
int main(int argc,char * argv[])
{
	int fd1,fd2;
	ssize_t ret_in,ret_out;
	char buf[200];
	if(fd1=open(argv[1],O_RDONLY)==-1)
	{
		perror("open");
		return 2;
	}
	if(fd2=open(argv[2],O_WRONLY|O_CREAT)==-1)
	{
		perror("error");
		return 3;
	}

	while((ret_in=read(fd1,buf,2))>0)	
	{
		ret_out=write(fd2,&buf,(ssize_t)ret_in);
	}

	close(fd1);
	close(fd2);
	printf("COPIED SUCCESSFULLY");
	return 0;
}

