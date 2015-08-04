#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sem.h> 
#include <semaphore.h>

#define SHMSZ     27


union semun
{
int val; // value for SETVAL
struct semid_ds* buf; // buffer for IPC_STAT, IPC_SET
unsigned short* array; // array for GETALL, SETALL
struct seminfo* __buf; // buffer for IPC_INFO
};
int fact(int n)
{
	int i,fact=1;
	for(i=1;i<=n;i++)
	fact *=i;
	return fact;
}

/*
void up(int semid)
{
    int i;
    struct sembuf sembuf;

    sembuf.sem_num = 0;
    sembuf.sem_op = 1;
    sembuf.sem_flg = 0;
    i = semop(semid,&sembuf, 1);
    if (i == -1) perror("Up semop");
}

void down(int semid)
{
    int i;
    struct sembuf sembuf;

    sembuf.sem_num = 0;
    sembuf.sem_op = -1;
    sembuf.sem_flg = 0;
    i = semop(semid,&sembuf, 1);
    if (i == -1) perror("Down semop");
}*/
int main()
{


int semid; /* semid of semaphore set */
  key_t key ; /* key to pass to semget() */
  int semflg = SHM_R | SHM_W; /* semflg to pass to semget() */
  int nsems =2; /* nsems to pass to semget() */
  int nsops; /* number of operations to do */
  struct sembuf *sops = (struct sembuf *) malloc(2*sizeof(struct sembuf)); 
  /* ptr to operations to perform */

  /* set up semaphore */
  
 key = 5680;
   if ((semid = semget(key, nsems, semflg)) == -1) {
	perror("semget: semget failed");
	exit(1);
      } else 
	(void) fprintf(stderr, "semget: semget succeeded: semid =\
%d\n", semid);

    char c;
    int shmid;
    union semun arg;
   //key_t key;
    char *shm;int *n1,*n2;
    
    if ((shmid = shmget(key, 2*sizeof(int), IPC_CREAT | 0666)) < 0) 
    {
        perror("shmget");
        exit(1);
    }

    if ((shm =shmat(shmid, NULL, 0)) == (char *) -1) 
    {
        perror("shmat");
        exit(1);
    }
    n1 =(int *) shm;
    n2 =(int *) (shm+sizeof(int));
   // n3 =(int *) (shm+2*sizeof(int));
    *n1=1,*n2=1;
//semop(semid, 1, 1);
short vals[]={0,0};
arg.array[0] = 0;
arg.array[1] = 0;
semctl(semid, 0, SETALL,  arg);
semctl(semid, 1, SETALL,  arg);
    while(1)
    {
   	*n1=rand()%13;   
    sops[1].sem_num = 0;
    sops[1].sem_op = -1;
    sops[1].sem_flg = 0;
    semop(semid,&sops[0], 1);  
    
    sops[0].sem_num = 1;
    sops[0].sem_op = 1;
    sops[0].sem_flg = 0;
    semop(semid,&sops[1], 1);
     
	
	printf("factorial of %d is %d\n",*n1,*n2);
	

    }
    return 0;
}
