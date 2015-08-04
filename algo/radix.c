#include<stdio.h>
#include<math.h>
void count_sort(int *a,int *b,int n)
{
	int j,i,k;
	int c[10];
	int temp[n];
	//FILE *f=fopen("counting_sort.csv","w");
		//int a[i],b[i];
		
		for(j=0;j<10;j++)
		{
			c[j]=0;
		}
		for(j=0;j<10;j++)
		{
			c[b[j]]++;
		}
		for(j=1;j<10;j++)
		{
			c[j]+=c[j-1];
		}
		for(k=0;k<10;k++)
	printf("%d ",c[k]);
	printf("\n");
		for(j=n-1;j>=0;j--)
		{
			temp[c[b[j]]]=a[j];
			c[b[j]]--;
		}
		for(j=0;j<n;j++)
		{
			a[j]=temp[j];
		}
		for(i=0;i<10;i++)
	printf("%d ",a[i]);
	printf("\n");
	
}
int main()
{
int a[]={387,532,657,876,333,446,789,235,127,981};
int b[10];
int i,k;
int d=3;
for(i=1;i<=d;i++)
{
	for(k=0;k<10;k++)
	{
		b[k]=a[k]/(int)(pow(10,i-1));
	}
	for(k=0;k<10;k++)
	{
		b[k]=b[k]%10;
	}
	for(k=0;k<10;k++)
	printf("%d ",b[k]);
	printf("\n");
	count_sort(a,b,10);
}
for(i=0;i<10;i++)
	printf("%d ",a[i]);
}
			
