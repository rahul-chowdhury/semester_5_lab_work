#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	int i,sys=0;
	//printf("args=%d\n",argc);
	pid_t pid;
	for(i=1;i<=argc-3;i=i+3)
	{
		pid=fork();
		if(pid==-1)
		{
			printf("error");
			exit(0);
		}
		else if(pid==0)
		{		
			dup2(open(argv[i+1],O_RDONLY),0);
			dup2(open(argv[i+2],O_WRONLY),1);
			execl(argv[i],argv[i+2],0);
			exit(0);
		}
		else
		{
			wait(&sys);
		}
		
		
	}
	return 0;
}
	
	
