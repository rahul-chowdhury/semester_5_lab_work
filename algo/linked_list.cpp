#include<iostream>
#include<list>
using namespace std;
list<int> l;
int main()
{

l.push_back(0);
l.push_back(5);
l.push_back(0);
l.push_back(3);
l.push_back(2);
int size=l.size();
for(int i=1;i<=size;i++)
{
cout<<l.front()<<endl;
l.pop_front();
}
}

