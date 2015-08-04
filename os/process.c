#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t process_id;
	int i,n,status;
	char current_working_directory[1000];
	printf("ENTER THE NUMBER OF CHILD PROCESSES YOU WANT TO CREATE : ");
	scanf("%d",&n);
	printf("\t\t\t\t****************************CHILD PROCESS LIST**************************\n");
	printf("Child number   Process id.   Parent process id.   User id.   Effective user id.   Group id.   Effective group id.    Current working directory\n");
	for (i = 0; i < n; i++) 
	{
		 process_id= fork();
 	 	if (process_id ==-1) 
 	 	{
    			printf("THERE WAS AN ERROR DURING CREATING A CHILD PROCESS\n");
    			exit(0);
  		} 
  		else if (process_id == 0) 
  		{
  			getcwd(current_working_directory,1000);
    			printf("%d\t\t%d\t\t%d\t\t  %d\t\t%d\t\t   %d\t\t%d\t\t  %s\n",i+1,getpid(),getppid(),getuid(),geteuid(),getgid(),getegid(),current_working_directory);
   			exit(0);
  		}
  		else
  		{
  			wait(&status);
  		}
  	}

}	
