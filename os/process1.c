//this program will create n number of processes 
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
void info(char *);	 
int main()
{
	int n,i=0,status=0;
	printf("please enter the number of processes you want to create\n");
	scanf("%d",&n);
	printf("Creating %d children.\n",n);
	info("parent");
	for(i=0;i<n;i++)
	{
		
		pid_t pid=fork();
		 if (pid == -1) 
		 {

     			perror("fork failed"); // When fork() returns -1, an error happened.
     		 	exit(0);
  		 }
		else if(pid==0)
		{
		 info("child");	// When fork() returns 0, we are in the child process.
		 exit(0);
		}
		else
		wait(&status);  /* The wait() function suspends execution of its calling process until
    				 status information is available for a terminated child process*/
		
	}
return 0;
}
void info(char *name)
{
	printf("I am %s process.\nMy pid is %d.\nMy ppid is %d.\nMy user id is %d.\nMy effective user id is %d.\n.My group id is %d.\nMy effective group id is %d.\n",name,getpid(),getppid(),getuid(),geteuid(),getgid(),getegid()); 
	//printf("My current working direcory: %s\n",get_current_dir_name()); (throwing warning statement)
	char cwd[1000];
       if (getcwd(cwd, sizeof(cwd)) != NULL)
           printf("Current working directory: %s\n", cwd);
       else
           perror("getcwd() error");
}	
