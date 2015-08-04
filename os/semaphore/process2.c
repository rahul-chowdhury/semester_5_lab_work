#include  <stdio.h>
#include  <stdlib.h>
#include <string.h>
#include  <sys/types.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include  <sys/sem.h>
union semun
{
int val; 
struct semid_ds* buf; 
unsigned short* array; 
struct seminfo* __buf; 
};
int facto(int);
void sem_signal(int,int);
void sem_wait(int,int);
int main() {
int shmid,semid;
   char *shm;
   int *s,*s1,*s2;
   union semun arg,arg1;
   arg.val=1;
   arg1.val=0;
   key_t key;
   key=2000;
   semid=semget(2000,2,IPC_CREAT | 0666);
   
   	
   semctl(semid,0,SETVAL,arg);
    semctl(semid,1,SETVAL,arg1);
   shmid = shmget(2009,3*sizeof(int),0666);
        if (shmid < 0) {
                printf("cannot create shared memory\n");exit(-1);
        }
        else 
        {
         printf("shared memory has been created with id %d\n",shmid);
         }
        shm = shmat(shmid, NULL, 0);
        s =(int *) shm;
   
     s1 =(int *) (shm+sizeof(int));
      s2 =(int *) (shm+2*sizeof(int));
    
    *s=1,*s1=1,*s2=0;
       
        	while(1)
        	{
        	sem_wait(semid,1);
        	/*while(*s2!=0)
		{
        	}*/
		*s1=facto(*s);
		sem_signal(semid,0);
        	//*s2=1;
        	}
		shmdt(shm);
        	return 0;
        	}
        	       int facto(int x)
{
	 int c,fact = 1;
	 for (c = 1; c <= x; c++)
    fact = fact * c;
 
  
 
  return fact;
  }
        	
void sem_signal(int semid,int x)
{
    int i;
    struct sembuf sembuf;

    sembuf.sem_num = x;
    sembuf.sem_op = 1;
    sembuf.sem_flg = 0;
    i = semop(semid,&sembuf, 1);
    if (i == -1) perror("signal semop");
}
void sem_wait(int semid,int x)
{
    int i;
    struct sembuf sembuf;

    sembuf.sem_num = x;
    sembuf.sem_op = -1;
    sembuf.sem_flg = 0;
    i = semop(semid,&sembuf, 1);
    if (i == -1) perror("wait semop");
}

