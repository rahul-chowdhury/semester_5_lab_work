#include<stdio.h>

int counter=0;
void max_heapify(int *a,int n,int i)
{
	counter++;
	int largest=i;
	int left=2*i,right=2*i+1;
	if(i==0){
	left++;right++;}
	if(right>=n || left>=n)
		return;
	if(a[left]>a[i])
		{largest=left;}
	if(a[right]>a[largest])
		{largest=right;}
	if(i!=largest)
	{
	int temp=a[largest];
	a[largest]=a[i];
	a[i]=temp;
	max_heapify(a,n,largest);
	}
}

void build_heap(int *a,int n)
{
	int i;
	for(i=n/2;i>=0;i--)
		max_heapify(a,n,i);
}
void heapsort(int *a,int n)
{
	int i,j;
	build_heap(a,n);
	
	for(i=n-1;i>1;i--)
	{
	
		int temp=a[0];
		a[0]=a[n-1];
		a[n-1]=temp;
		n=n-1;
		max_heapify(a,n,0);
	}
}

int main()
{
	FILE *f=fopen("heapsort.csv","w");
	int i,n;
	for(n=10;n<=1000;n=n+10)
	{
	int a[n];
	for(i=0;i<n;i++)
	{
		a[i]=rand()%10000;
	}
	
	
	heapsort(a,n);
	fprintf(f,"%d\n",counter);
	/*for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}*/
	}
	//printf("%d\n",a[0]);
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
