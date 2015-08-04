#include<iostream>
#include<string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int memory_address;
struct variable
{
	char type[100];
	char name[100];
	int length;
	int starting_address;
};

struct variable hash_table[100];
struct variable variable_table[100];

void insert_hash_table(struct variable x)
{
	int index=0,key=0,i=0;
	
	while(x.name[index]!='\0')
	{
		key+=x.name[index++];
	}
	while(strcmp(hash_table[(key+i)%100].name,"\0")!=0 && strcmp(hash_table[(key+i)%100].name,"deleted")!=0 )
	{
		i++;
	}
	key=key+i;
	strcpy(hash_table[key%100].name,x.name);
	strcpy(hash_table[key%100].type,x.type);
	if(strcmp(x.type,"int")==0)
	{
		hash_table[key%100].starting_address=memory_address;
		//cout<<x.length<<endl;
		memory_address +=2*x.length;
		//cout<<memory_address<<endl;
	}
	if(strcmp(x.type,"char")==0)
	{
		hash_table[key%100].starting_address=memory_address;
		memory_address +=1*x.length;
	}
	if(strcmp(x.type,"float")==0)
	{
		hash_table[key%100].starting_address=memory_address;
		memory_address +=4*x.length;
	}
	if(strcmp(x.type,"long")==0)
	{
		hash_table[key%100].starting_address=memory_address;
		memory_address +=4*x.length;
	}
}
	
	
int search_hash_table(char x[100])
{
	int index=0,key=0,i=0;
	
	while(x[index]!='\n')
	{
		key+=x[index];
		//cout<<x<<" "<<key<<endl;
		index++;
		
	}
	x[index]='\0';
	while(strcmp(hash_table[(key+i)%100].name,"\0")!=0 && strcmp(hash_table[(key+i)%100].name,"deleted")!=0 )
	{
		
		if(strcmp(hash_table[(key+i)%100].name,x)==0)
		return (key+i);
		i++;
	}
	return -1;
}	

int delete_hash_table(char x[100])
{
	int index=0,key=0,i=0;
	
	while(x[index]!='\n')
	{
		key+=x[index++];
	}
	x[index]='\0';
	while(strcmp(hash_table[(key+i)%100].name,"\0")!=0 && strcmp(hash_table[(key+i)%100].name,"deleted")!=0 )
	{
		if(strcmp(hash_table[(key+i)%100].name,x)==0)
		{
			strcpy(hash_table[(key+i)%100].name,"deleted");
			strcpy(hash_table[(key+i)%100].type,"");
			hash_table[(key+i)%100].starting_address=-1;
			return (key+i);
		}
		i++;
	}
	return -1;
}	
	
void read_variables()
{
	FILE *f=fopen("varlist.c","r");
	char line[100],*word;
	
	
	struct variable temp;
	do
	{
		//cout<<"here1"<<endl;
		fgets(line, 100, f);
		//cout<<"here2"<<line<<endl;
		if(strcmp(line,"END\n")==0) break;
		temp.length=1;
		word=strtok(line," ");
		//cout<<word<<endl;
		strcpy(temp.type,word);
		word=strtok(NULL," ");
		//cout<<word<<endl;
          	strcpy(temp.name,word);
          	cout<<"********************INSERT VARIABLE "<<word<<endl;;
		word=strtok(NULL," ");
		//cout<<word<<endl;
		if(strcmp(word,";\n")!=0)
		{
			temp.length=word[1]-45;
		}
		else temp.length=1;
		insert_hash_table(temp);
       }while(!feof(f));
       //cout<<"lala"<<endl;
       fclose(f);
}

void print_hash_table()
{
	cout<<"\t\t\tVARIABLE TABLE\nTYPE   NAME   STARTING ADDRESS"<<endl;
	for(int i=0;i<100;i++)
	{
		if(strcmp(hash_table[i].name,"\0")!=0)
		cout<<hash_table[i].type<<"\t"<<hash_table[i].name<<"\t"<<hash_table[i].starting_address<<"\n\n\n"<<endl;
	}
}
	
int main()
{
memory_address=0;
char *word,line[100];
FILE *f=fopen("instructions","r");
for(int i=0;i<100;i++)
strcpy(hash_table[i].name,"\0");
read_variables();
//cout<<"here"<<endl;
int exit=0,choice;
while(!feof(f))
{
fgets(line, 100, f);
	
		
		word=strtok(line," ");
		//cout<<word<<endl;
		if(strcmp(line,"END\n")==0) break;
		if(strcmp(word,"search")==0)
		{
			word=strtok(NULL," ");
			int index=search_hash_table(word);
			cout<<"**********************SEARCH FOR VARIABLE "<<word<<endl;
			if(index==-1)
			{
				cout<<"variable not found \n\n\n\n"<<endl;
			}
			else
			{
				cout<<"element found at index "<<index<<"\n\n\n";
			}
		}
		if(strcmp(word,"delete")==0)
		{
			word=strtok(NULL," ");
			int index=delete_hash_table(word);
			cout<<"******************DELETE VARIABLE "<<word<<endl;;
			if(index==-1)
			{
				cout<<"variable not found \n\n\n\n"<<endl;
			}
			else
			{
				cout<<"element deleted from index "<<index<<"\n\n\n";
			}
		}
          	if(strcmp(word,"print")==0)
		{
			cout<<"*********PRINT VARIABLE TABLE*********"<<endl;
			print_hash_table();
		}
		
       }
fclose(f);

		
}


