#include<stdio.h>
int main()
{
	int i,j,count=0;
	int c[10000];
	FILE *f=fopen("counting_sort.csv","w");
	for(i=10;i<=10000;i=i+10)
	{ 		
		int a[i],b[i];
		for(j=0;j<i;j++)
		{
			a[j]=rand()%10000;
		}
		for(j=0;j<10000;j++)
		{
			c[j]=0;
		}
		for(j=0;j<i;j++)
		{
			c[a[j]]++;
		}
		for(j=1;j<10000;j++)
		{
			c[j]+=c[j-1];
		}
		for(j=i-1;j>=0;j--)
		{
			count++;
			b[c[a[j]]]=a[j];
			c[a[j]]--;
		}
		for(j=0;j<i;j++)
		{
			printf("%d "
		}
		fprintf(f,"%d\n",count);
	}
}
		
