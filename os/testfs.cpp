#include <string>
#include<iostream>
#include<stdlib.h>
using namespace std;

int min(int a,int b)
{
	if(a<b) return a;
	return b;
}

int main()
{
	string filesystem[100][100],filesystem_name[100][3],os[100];
	string input,command,arg1,arg2,arg3;
	bool flag=true;
	int space_index,find,length,filesystem_name_index=0,number_of_files[100],number_of_os_files=0,filesystem_size_of_files[100][100],os_size_of_files[100];
	for(int i=0;i<100;i++)
	{
		number_of_files[i]=0;
		os_size_of_files[i]=0;
	
	}
	while(flag)
	{
		cout<<"$myfs> ";
		command=arg1=arg2=arg3="";
		getline(cin,input);
		//for(int i=0;input[i]!='\0';i++)
		//cout<<input[i]<<endl;
		space_index=min(input.find(" "),input.length());
		
		command=input.substr(0,space_index);
		cout<<command;
		//cout<<input.find(" ",space_index+1)<<endl;
		if(space_index==input.length())space_index--;
		find=min(input.find(" ",space_index+1),input.length());
		//cout<<"fin="<<input.find(" ",space_index+1)<<"end"<<input.find("\0",space_index+1)<<endl;
		length=find-space_index;
		cout<<length<<space_index;;		
		arg1=input.substr(space_index+1,length-1);
		if(find==input.length())
		space_index=find-1;
		else
		space_index=find;
		
		find=min(input.find(" ",space_index+1),input.length());
		//cout<<"fin="<<find<<endl;
		//cout<<"arg2"<<endl;
		length=find-space_index;		
		arg2=input.substr(space_index+1,length-1);
		if(find==input.length())
		space_index=find-1;
		else
		space_index=find;
		//cout<<arg2;
		find=min(input.find(" ",space_index+1),input.length());
		//cout<<"fin="<<find<<endl;
		//cout<<find<<endl;
		length=find-space_index;		
		arg3=input.substr(space_index+1,length);
		
		cout<<"arg1="<<arg1;
		cout<<"arg2="<<arg2;
		cout<<"arg3="<<arg3;
		
		//cout<<arg3;
		if(command=="mkfs")
		{
			filesystem_name[filesystem_name_index][0]=arg1;
			filesystem_name[filesystem_name_index][1]=arg2;
			filesystem_name[filesystem_name_index++][2]=arg3;
			for(int i=0;i<filesystem_name_index;i++)
			cout<<filesystem_name[i][0]<<endl;	
		}
		else if(command=="use")
		{
			for(int i=0;i<filesystem_name_index;i++)
			{
				if(arg1==filesystem_name[i][0])
				{
					filesystem[i][0]=arg3;
					break;
				}
			}
			for(int i=0;i<filesystem_name_index;i++)
			cout<<filesystem[i][0]<<endl;	
		}
		else if(command=="cp")
		{
			string before_colon1,after_colon1,before_colon2,after_colon2;
			int findcolon=arg1.find(":"),size;
			if(findcolon>arg1.length())
			{
				findcolon=0;
			
				before_colon1="";
				after_colon1=arg1;
			}
			else
			{
			
		
				before_colon1=arg1.substr(0,findcolon);
				after_colon1=arg1.substr(findcolon+1,arg1.length()-findcolon-1);
			}
			findcolon=arg2.find(":");
			if(findcolon>arg2.length())
			{
				findcolon=0;
			
				before_colon2="";
				after_colon2=arg2;
			}
			else
			{
			
		
				before_colon2=arg2.substr(0,findcolon);
				after_colon2=arg2.substr(findcolon+1,arg2.length()-findcolon-1);
			}
			//before_colon2=arg2.substr(0,findcolon);
			//after_colon2=arg2.substr(findcolon+1,arg2.length()-findcolon-1);
			cout<<"beforecolon1="<<before_colon1<<endl;
			cout<<"aftercolon1="<<after_colon1<<endl;
			cout<<"beforecolon2="<<before_colon2<<endl;
			cout<<"aftercolon2="<<after_colon2<<endl;
			if(before_colon1!="" && before_colon2!="")
			{
				if(before_colon1==before_colon2)
				{
					for(int i=0;i<filesystem_name_index;i++)
					{
						if(before_colon1==filesystem[i][0])
						{
							for(int j=1;j<=number_of_files[i];j++)
							{
								if(after_colon1==filesystem[i][j])
								{
									size=filesystem_size_of_files[i][j];
									filesystem[i][number_of_files[i]+1]=after_colon2;
									filesystem_size_of_files[i][number_of_files[i]+1]=size;
									number_of_files[i]++;						
									break;
								}
							}
							break;
						}
					}
				}
				else
				{	
					for(int i=0;i<filesystem_name_index;i++)
					{
						if(before_colon1==filesystem[i][0])
						{
							for(int j=1;j<=number_of_files[i];j++)
							{
								if(after_colon1==filesystem[i][j])
								{
									size=filesystem_size_of_files[i][j];
									//filesystem_size_of_files[i][j]=0;
									//filesystem[i][j]="";
									//number_of_files[i]--;
									break;
								}
							}
							break;
						}
					}
					for(int i=0;i<filesystem_name_index;i++)
					{
						if(before_colon2==filesystem[i][0])
						{
							filesystem[i][1+number_of_files[i]]=after_colon2;
					
							filesystem_size_of_files[i][1+number_of_files[i]]=size;
							number_of_files[i]++;
							break;
						}
					}
				}
			}
			else if(before_colon1=="")//if file to be moved from os
			{
				for(int i=0;i<number_of_os_files;i++)
				{
					if(after_colon1==os[i])
					{
						
						size=os_size_of_files[i];
						//os_size_of_files[i]=0;
						//os[i]="";
						//number_of_os_files[i]--;
								
						
						break;
					}
				}
				for(int i=0;i<filesystem_name_index;i++)
				{
					if(before_colon2==filesystem[i][0])
					{
						filesystem[i][1+number_of_files[i]]=after_colon2;
			
						filesystem_size_of_files[i][1+number_of_files[i]]=size;
						number_of_files[i]++;
						break;
					}
				}
			}
			else//if file to be moved to os
			{
				for(int i=0;i<filesystem_name_index;i++)
				{
					if(before_colon1==filesystem[i][0])
					{
						for(int j=1;j<=number_of_files[i];j++)
						{
							if(after_colon1==filesystem[i][j])
							{
								size=filesystem_size_of_files[i][j];
								//filesystem_size_of_files[i][j]=0;
								//filesystem[i][j]="";
								//number_of_files[i]--;
								break;
							}
						}
						break;
					}
				}
				os[number_of_os_files]=after_colon2;
				os_size_of_files[number_of_os_files]=size;
				number_of_os_files++;
				
			}
				
			
					
		}
		else if(command=="ls")//for ls command
		{
			if(arg1=="")//to know contents of os
			{
				for(int i=0;i<number_of_os_files;i++)
				{
					cout<<os[i]<<"....."<<os_size_of_files[i]<<"MB"<<endl;
					
				}
			}
			else//to know contents of filesystems
			{
				for(int i=0;i<filesystem_name_index;i++)
				{
					if(filesystem[i][0]==arg1)
					{
						for(int j=1;j<=number_of_files[i];j++)
						{
							cout<<filesystem[i][j]<<"....."<<filesystem_size_of_files[i][j]<<"MB"<<endl;
						}
						break;
					}
				}
			}
		}
		else if(command=="create")//creates files:create file1 of 10mb
		{
			int find_m=arg3.find("m");
			os[number_of_os_files]=arg1;
			os_size_of_files[number_of_os_files]=atoi(arg3.substr(0,find_m).c_str());
			number_of_os_files++;
			for(int i=0;i<number_of_os_files;i++)
			{
				cout<<os[i]<<" "<<os_size_of_files[i]<<endl;
			}
		}
		else if(command=="mv")
		{
			string before_colon1,after_colon1,before_colon2,after_colon2;
			int findcolon=arg1.find(":"),size;
			if(findcolon>arg1.length())
			{
				findcolon=0;
			
				before_colon1="";
				after_colon1=arg1;
			}
			else
			{
			
		
				before_colon1=arg1.substr(0,findcolon);
				after_colon1=arg1.substr(findcolon+1,arg1.length()-findcolon-1);
			}
			findcolon=arg2.find(":");
			if(findcolon>arg2.length())
			{
				findcolon=0;
			
				before_colon2="";
				after_colon2=arg2;
			}
			else
			{
			
		
				before_colon2=arg2.substr(0,findcolon);
				after_colon2=arg2.substr(findcolon+1,arg2.length()-findcolon-1);
			}
			//before_colon2=arg2.substr(0,findcolon);
			//after_colon2=arg2.substr(findcolon+1,arg2.length()-findcolon-1);
			cout<<"beforecolon1="<<before_colon1<<endl;
			cout<<"aftercolon1="<<after_colon1;
			cout<<"beforecolon2="<<before_colon2<<endl;
			cout<<"aftercolon2="<<after_colon2<<endl;
			if(before_colon1!="" && before_colon2!="")//if both operands have a filesystem name
			{
				if(before_colon1==before_colon2)//eg:mv c:file1 c:file2
				{
					
					for(int i=0;i<filesystem_name_index;i++)
					{
						cout<<"asd"<<endl;
						if(before_colon1==filesystem[i][0])
						{
							cout<<"ss";
							for(int j=1;j<=number_of_files[i];j++)
							{
								cout<<"pp"<<endl;
								if(after_colon1==filesystem[i][j])
								{
									cout<<"kk"<<endl;
									filesystem[i][j]=after_colon2;
									break;
								}
							}
							break;
						}
					}
				}
				else//eg:mv c:file1 d:file2
				{	
					for(int i=0;i<filesystem_name_index;i++)//cutting
					{
						if(before_colon1==filesystem[i][0])
						{
							for(int j=1;j<=number_of_files[i];j++)
							{
								if(after_colon1==filesystem[i][j])
								{
									size=filesystem_size_of_files[i][j];
									filesystem_size_of_files[i][j]=0;
									filesystem[i][j]="";
									number_of_files[i]--;
									break;
								}
							}
							break;
						}
					}
					for(int i=0;i<filesystem_name_index;i++)//pasting
					{
						if(before_colon2==filesystem[i][0])
						{
							filesystem[i][1+number_of_files[i]]=after_colon2;
					
							filesystem_size_of_files[i][1+number_of_files[i]]=size;
							number_of_files[i]++;
							break;
						}
					}
				}
			}
			else if(before_colon1=="")//if file to be moved from os
			{
				for(int i=0;i<number_of_os_files;i++)//cutting
				{
					if(after_colon1==os[i])
					{
						
						size=os_size_of_files[i];
						os_size_of_files[i]=0;
						os[i]="";
						number_of_os_files--;
								
						
						break;
					}
				}
				for(int i=0;i<filesystem_name_index;i++)
				{
					if(before_colon2==filesystem[i][0])
					{
						filesystem[i][1+number_of_files[i]]=after_colon2;
			
						filesystem_size_of_files[i][1+number_of_files[i]]=size;
						number_of_files[i]++;
						break;
					}
				}
			}
			else//if file to be moved to os
			{
				for(int i=0;i<filesystem_name_index;i++)
				{
					if(before_colon1==filesystem[i][0])
					{
						for(int j=1;j<=number_of_files[i];j++)
						{
							if(after_colon1==filesystem[i][j])
							{
								size=filesystem_size_of_files[i][j];
								filesystem_size_of_files[i][j]=0;
								filesystem[i][j]="";
								number_of_files[i]--;
								break;
							}
						}
						break;
					}
				}
				os[number_of_os_files]=after_colon2;
				os_size_of_files[number_of_os_files]=size;
				number_of_os_files++;
				
			}
				
			
					
		}
		else if(command=="rm")
		{
			string before_colon,after_colon;
			int findcolon=arg1.find(":"),size;
			before_colon=arg1.substr(0,findcolon);
			after_colon=arg1.substr(findcolon+1,arg1.length()-findcolon-1);
			if(before_colon=="")
			{
				for(int i=0;i<number_of_os_files;i++)
				{
					if(after_colon==os[i])
					{
						
						//size=os_size_of_files[i];
						os_size_of_files[i]=0;
						os[i]="";
						number_of_os_files--;
						break;
					}
				}
			}
			else
			{
				for(int i=0;i<filesystem_name_index;i++)
				{
					if(before_colon==filesystem[i][0])
					{
						for(int j=1;j<=number_of_files[i];j++)
						{
							if(after_colon==filesystem[i][j])
							{
								size=filesystem_size_of_files[i][j];
								filesystem_size_of_files[i][j]=0;
								filesystem[i][j]="";
								number_of_files[i]--;
								break;
							}
						}
						break;
					}
				}
			}
		}
			
				
		else if(command=="exit")
		{
			flag=false;
		}
		else 
		{
		
		cout<<"Command does not exist"<<endl;
		}			
			
	
	
	
	
	
	
	
	
	
	
	
	
	
	}
	
	
	/*for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		{
			cout<<filesystem[i][j]<<endl;
		}
	}*/
	return 0;
}
	
