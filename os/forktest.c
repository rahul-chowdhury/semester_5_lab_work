#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>
int main()
{
int i=1,pid=50;
printf(" %d\n",pid);
pid=fork();
printf(" %d\n",pid);
if(pid==0){
printf("in child %d i=%d pid=%d\n",getpid(),i,pid);
}
else
{
i=2;
//sleep(1);
printf("in parent %d pid=%d\n",getpid(),pid);
}
return 0;
}
