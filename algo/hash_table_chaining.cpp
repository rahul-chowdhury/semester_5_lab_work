#include<iostream>
#include<list>
using namespace std;
list<int> hash_table[100];
list<int>::iterator it;
void insert_hash_table(int value)
{
	int key=value%100;
	hash_table[key].remove(-1);
	hash_table[key].push_front(value);
}
void search_hash_table(int value)
{
	int key=value%100;
	int size=hash_table[key].size();
	for(it=hash_table[key].begin();it!=hash_table[key].end();it++)
	{
		if(value==*it)
		{
			cout<<"element found"<<endl;
			return;
		}
		
	}
	cout<<"element not found"<<endl;
}

void delete_hash_table(int value)
{
	int key=value%100;
	int size=hash_table[key].size();
	for(it=hash_table[key].begin();it!=hash_table[key].end();it++)
	{
		if(value==*it)
		{
			hash_table[key].remove(value);
			cout<<"element removed"<<endl;
			return;
		}
		
	}
	cout<<"element not found"<<endl;
}


int main(){


for(int i=0;i<100;i++)
{
	hash_table[i].push_front(-1);
}
int exit=0,choice;

while(exit==0)
{
	cout<<"0.exit\n1.insert element\n2.delete element\n3.search element\n4.print hash table"<<endl;
	cin>>choice;
	if(choice==0) exit=1;
	if(choice==1)
	{
		cout<<"enter element to be inserted : ";
		int element;
		cin>>element;
		insert_hash_table(element);
	}
	if(choice==2)
	{
		cout<<"enter element to be deleted : ";
		int element;
		cin>>element;
		delete_hash_table(element);
	}
	if(choice==3)
	{
		cout<<"enter element to be searched : ";
		int element;
		cin>>element;
		search_hash_table(element);
	}
	if(choice==4)
	{
		for(int i=0;i<100;i++)
		{
			if(hash_table[i].front()>=0)
			{
				cout<<"index "<<i<<" : ";
				for(it=hash_table[i].begin();it!=hash_table[i].end();it++)
				{
					cout<<*it<<" ";
				}
				cout<<"\n\n"<<endl;
			}
		}
	}
}























return 0;
}
