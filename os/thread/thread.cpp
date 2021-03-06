#include<iostream>
#include<unistd.h>
#include<pthread.h>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;
int number_of_arguments;
char arglist[100][100];
pthread_barrier_t barrier;
int counter;
pthread_mutex_t lock;

void * file_write(void * filename)
{
	pthread_mutex_lock(&lock);
	int x=rand()%100;
	FILE *f=fopen((*(string *)filename).c_str(),"w+");
	fprintf(f,"%d\n",x);
	fclose(f);
	pthread_mutex_unlock(&lock);
	pthread_barrier_wait (&barrier);
}

void * perform_operation(void * operation)
{
	pthread_barrier_wait (&barrier);
	string s=*(string *)operation;
	char filename[100];
	int num,result;
	FILE *f;
	if(s=="+")
	{
		result=0;
		for(int i=0;i<(number_of_arguments-2);i++)
		{
		 	strcpy(filename,arglist[i+1]);
			f=fopen(filename,"r");
			fscanf(f,"%d\n",&num);
			fclose(f);
			result=result+num;
		}
		cout<<"result of addition is "<<result<<endl;
	}
	else if(s=="*")
	{
		result=1;
		for(int i=0;i<(number_of_arguments-2);i++)
		{
		 	strcpy(filename,arglist[i+1]);
			f=fopen(filename,"r");
			fscanf(f,"%d\n",&num);
			fclose(f);
			result=result*num;
		}
		cout<<"result of multiplication is "<<result<<endl;
	}
	else if(s=="-")
	{	
		result=0;
		strcpy(filename,arglist[1]);
			f=fopen(filename,"r");
			fscanf(f,"%d\n",&num);
			fclose(f);
			result=result+num;
		for(int i=1;i<(number_of_arguments-2);i++)
		{
		 	strcpy(filename,arglist[i+1]);
			f=fopen(filename,"r");
			fscanf(f,"%d\n",&num);
			fclose(f);
			result=result-num;
		}
		cout<<"result of subtraction is "<<result<<endl;
	}
	else if(s=="/")
	{
		result=0;
		strcpy(filename,arglist[1]);
		f=fopen(filename,"r");
		fscanf(f,"%d\n",&num);
		fclose(f);
		result=result+num;
		for(int i=0;i<(number_of_arguments-2);i++)
		{
		 	strcpy(filename,arglist[i+1]);
			f=fopen(filename,"r");
			fscanf(f,"%d\n",&num);
			fclose(f);
			result=result/num;
		}
		cout<<"result of division is "<<result<<endl;
	}
	else
	{
		cout<<"invalid opration"<<endl;
	}
}
		
	
	
	
	
	
int main(int argc,char *argv[])
{
	string s;
	FILE *f;
	number_of_arguments=argc;
	pthread_mutex_init(&lock, NULL);
	pthread_barrier_init(&barrier,NULL,argc-1);
	for(int i=0;i<argc-1;i++)
	{
		strcpy(arglist[i],argv[i]);
	}
	pthread_t thread_array[argc-1];
	for(int i=0;i<argc-1;i++)
	{
		s=argv[i+1];
		if(i==argc-2)
			pthread_create(&thread_array[i],NULL,perform_operation,(void *)&s);
		else
			pthread_create(&thread_array[i],NULL,file_write,(void *)&s);
		sleep(1);
	}
	pthread_mutex_destroy(&lock);
	
	
	return 0;
}
