#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void bubble_sort(int *a,int length, int *count)
{
int i,j;
for(i=0;i<length-1;i++)
{
	for(j=i+1;j<length;j++)
	{
		(*count)++;
		if(a[j]<a[j-1])
		{
			int temp=a[j];
			a[j]=a[j-1];
			a[j-1]=temp;
		}
	}
}
}




void quicksort(int *x,int first,int last,int *count)
{
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
         (*count)++;
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1,count);
         quicksort(x,j+1,last,count);

    }
}


void partition(int arr[],int low,int high,int *count){

    int mid;

    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid,count);
         partition(arr,mid+1,high,count);
         mergeSort(arr,low,mid,high,count);
    }
}

void mergeSort(int arr[],int low,int mid,int high,int *count){

    int i,m,k,l,temp[high+1];

    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high)){
    (*count)++;

         if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;
         }
         else{
             temp[i]=arr[m];
             m++;
         }
         i++;
    }

    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }
   
    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
} 


void insertion_sort(int *a,int length,int *count)
{
	int i,j;
	for(i=1;i<length;i++)
	{
		int key=a[i];
		j=i-1;
		while((*count)++ && j>=0 &&  a[j]>key)
		{
			
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}

void selection_sort(int *a,int length,int *count)
{
	int i,j;
	for(i=0;i<length-1;i++)
	{
		int smallest=a[i];
		int index=i;
		for(j=i+1;j<length;j++)
		{
			(*count)++;
			if(a[j]<a[index])
				index=j;
		}
		int temp=a[index];
		a[index]=a[i];
		a[i]=temp;
	}
}










int main()
{
	int i,j,count_quick=0,count_merge=0,count_bubble=0,count_selection=0,count_insertion=0;
	
	FILE *f=fopen("quick_sort.csv","w");
	srand(time(NULL));
	for(i=10;i<=1000;i=i+10)
	{
		//count_quick=0;count_merge=0;count_bubble=0;count_selection=0;count_insertion=0;
		int a[i];
		for(j=0;j<i;j++)
		{
			a[j]=rand()%i;
		}
		quicksort(a,0,i-1,&count_quick);
		partition(a,0,i-1,&count_merge);
		bubble_sort(a,i,&count_bubble);
		insertion_sort(a,i,&count_insertion);
		selection_sort(a,i,&count_selection);
		fprintf(f,"%d %d   %d\n",count_quick,count_merge,count_insertion);
	}
	
	return 0;
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
