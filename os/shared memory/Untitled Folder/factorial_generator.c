
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#define SHMSZ     27
int fact(int n)
{
	int i,fact=1;
	for(i=1;i<=n;i++)
	fact *=i;
	return fact;
}
main()
{
    int shmid;
    key_t key;
    char *shm;int *n1,*n2;

    key = 5680;

    if ((shmid = shmget(key,2*sizeof(int),IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }
   n1 =(int *) shm;
   
     n2 =(int *) (shm+sizeof(int));
    
    *n1=1,*n2=1;

    while(1){
        *n2 = fact(*n1);
    sleep(1);
    
    }
   
    return 0;
}
