#include<stdio.h>

struct node
{
	int key;
	int value;
};

int maximum(struct node *a)
{
	return a[0].value;
}


void heapify(struct node *a,int i,int n)
{
	//counter++;
	int largest=i;
	int left=2*i,right=2*i+1;
	if(i==0){
	left++;right++;}
	if(right>=n || left>=n)
		return;
	if(a[left].key>a[i].key)
		{largest=left;}
	if(a[right].key>a[largest].key)
		{largest=right;}
	if(i!=largest)
	{
	struct node temp;
	temp.value=a[i].value;
	a[i].value=a[largest].value;
	a[largest].value=temp.value;
	temp.key=a[i].key;
	a[i].key=a[largest].key;
	a[largest].key=temp.key;
	heapify(a,largest,n);
	}
}

struct node extract_max(struct node *a,int n)
{
	//if(n==0)
	
	struct node temp;
	temp.value=a[0].value;
	a[0].value=a[n-1].value;
	a[n-1].value=temp.value;
	temp.key=a[0].key;
	a[0].key=a[n-1].key;
	a[n-1].key=temp.key;
	n=n-1;
	struct node max=a[n];
	heapify(a,0,n);
	return(max);
}

void insert_element(struct node *a,int n,struct node x)
{
	//n++;
int i=n;
//int parent=i/2;
	while(i>0 && a[i/2].key<x.key)
	{
		a[i].key =a[i/2].key;
		a[i].value =a[i/2].value;
		i=i/2;
	}
	a[i].value=x.value;
	a[i].key=x.key;
}

void increase_key(struct node *a,int n,int i,int new_key)
{
	
	if( new_key<a[i].key)
	{
		printf("wrong key.\n");
		return;
	}
	else
	{
		a[i].key=new_key;
		struct node x=a[i];
		while(i>0 && a[i/2].key<new_key)
		{
			a[i].key =a[i/2].key;
			a[i].value =a[i/2].value;
			i=i/2;
		}
		a[i].value=x.value;
		a[i].key=x.key;
	}
}

int main()
{
	int exit=0,size=0,choice,i,key;
	struct node a[1000],element;
	while(exit==0)
	{
		printf("\n\n0.exit \n1.insert element\n 2.find maximum element \n3.extract maximum element \n4.increase key\n5.display queue\nenter choice: ");
		scanf("%d",&choice);
		if(choice==0)
			break;
		else if(choice==1)
		{
			printf("enter value of element to be inserted: ");
			scanf("%d",&element.value);
			printf("enter key of element to be inserted: ");
			scanf("%d",&element.key);
			insert_element(a,size,element);
			size++;
		}
		else if(choice==2)
		{
		printf("maximum element = %d\n",maximum(a));
		}
		else if(choice==3)
		{
			printf("maximum element = %d\n",(extract_max(a,size)).value);
			size--;
		}
		else if(choice==4)
		{
			printf("enter position at which key to be increased(starting from 1): ");
			scanf("%d",&i);
			printf("enter new key: ");
			scanf("%d",&key);
			increase_key(a,size,i-1,key);
		}
		else if(choice==5)
		{
			printf("queue: ");
			if(size==0)
			{
				printf("no element in the queue!!");
			}
			else
			{
				for(i=0;i<size;i++)
					printf("%d\t",a[i].value);
			}
		}
		else
			continue;
	}
}
		
			
			
		
		
		
		















	
