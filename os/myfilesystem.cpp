#include <string>
#include<iostream>
#include<stdlib.h>
#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
       #include <stdio.h>
       #include <unistd.h>
#include <stdlib.h>
using namespace std;

struct file
{
	string name;
	int blocksize;
	FILE *fspointer;
};

int min(int a,int b)
{
	if(a<b) return a;
	return b;
}

int main()
{
	char input_buffer[10000];
	string filesystem[100][100],filesystem_name[100],os[100];
	struct file filesystem_pointer[100];
	string input,command,arg1,arg2,arg3;
	bool flag=true;
	int space_index,find,length,filesystem_name_index=0,number_of_files[100],number_of_os_files=0,filesystem_size_of_files[100][100],os_size_of_files[100],length_of_file;
	for(int i=0;i<100;i++)
	{number_of_files[i]=0;
	os_size_of_files[i]=0;
	
	}
	while(flag)
	{
		cout<<"$myfs> ";
		command=arg1=arg2=arg3="";
		getline(cin,input);
		//for(int i=0;input[i]!='\0';i++)
		//cout<<input[i]<<endl;
		space_index=input.find(" ");
		command=input.substr(0,space_index);
		//cout<<command;
		//cout<<input.find(" ",space_index+1)<<endl;
		find=min(input.find(" ",space_index+1)-1,input.length()-1);
		//cout<<"fin="<<input.find(" ",space_index+1)<<"end"<<input.find("\0",space_index+1)<<endl;
		length=find-space_index;		
		arg1=input.substr(space_index+1,length);
		if(find!=input.length()-1)
		{
				space_index=find+1;
		
			find=min(input.find(" ",space_index+1)-1,input.length()-1);
			//cout<<"fin="<<find<<endl;
			//cout<<"arg2"<<endl;
			length=find-space_index;		
			arg2=input.substr(space_index+1,length);
			if(find!=input.length()-1)
			{
				//cout<<arg2;
				space_index=find+1;
				find=min(input.find(" ",space_index+1)-1,input.length()-1);
				//cout<<"fin="<<find<<endl;
				//cout<<find<<endl;
				length=find-space_index;		
				arg3=input.substr(space_index+1,length);
				space_index=find;
				
			}
		}
		//cout<<"arg1="<<arg1;
		//		cout<<"arg2="<<arg2;
		//		cout<<"arg3="<<arg3<<endl;
		
		//cout<<arg3;
		if(command=="mkfs")
		{
			filesystem_name[filesystem_name_index]=arg1;
			//filesystem_name[filesystem_name_index][1]=arg2;
			//filesystem_name[filesystem_name_index][2]=arg3;
			filesystem_pointer[filesystem_name_index].name=arg1;
			filesystem_pointer[filesystem_name_index++].blocksize=atoi(arg2.c_str());
			int find_m=arg3.find("m");
			int size=atoi(arg3.substr(0,find_m).c_str());
			//int fd=creat(arg1.c_str(), O_CREAT);
			FILE* fp = fopen(arg1.c_str(), "w");
			fseek(fp, 1024*1024*size, SEEK_SET);
			fclose(fp);
			//close(fd);
			//for(int i=0;i<filesystem_name_index;i++)
			//cout<<filesystem_name[i][0]<<endl;	
		}
		else if(command=="use")
		{
			for(int i=0;i<filesystem_name_index;i++)
			{
				if(arg1==filesystem_name[i])
				{
					filesystem[i][0]=arg3;
					filesystem_name[i]=arg3;
					filesystem_pointer[i].name=arg3;
					break;
				}
			}
			rename(arg1.c_str(),arg3.c_str());
			//for(int i=0;i<filesystem_name_index;i++)
			//cout<<filesystem[i][0]<<endl;	
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
			//cout<<"beforecolon1="<<before_colon1;
			//cout<<"aftercolon1="<<after_colon1;
			//cout<<"beforecolon2="<<before_colon2;
			//cout<<"aftercolon2="<<after_colon2;
			if(before_colon1=="")
			{
			
				
						//cout<<"ke here"<<endl;
						int fd = open(after_colon1.c_str(), O_RDONLY);
						read(fd,input_buffer,10000);
						//cout<<input_buffer<<endl;
						int k;
						for(k=0;input_buffer[k]!='\n';k++);
						length_of_file=k+1;
						//size=os_size_of_files[i];
						//cout<<input_buffer<<endl;
						
			}
			else
			{
				for(int i=0;i<filesystem_name_index;i++)
				{
					if(before_colon1==filesystem[i][0])
					{
					
						for(int j=1;j<=number_of_files[i];j++)
						{	//cout<<"se here"<<endl;
							if(filesystem[i][j]==after_colon1)
							{
								//cout<<"me here"<<endl;
								FILE* fp = fopen(before_colon1.c_str(), "r");
								//cout<<"pe here"<<endl;
								int offset=400+(j-1)*1024;
								fseek(fp,offset,SEEK_SET);
								//cout<<"pe here"<<endl;
								//char length_in_string[10];
								//snprintf(length_in_string, sizeof(length_in_string), "%d", length_of_file);
								fread(&length_of_file,4,1,fp);
								//cout<<"pe here"<<endl;
								fseek(fp,offset+4,SEEK_SET);
								fread(input_buffer,length_of_file,1,fp);
								fclose(fp);
								//cout<<input_buffer<<endl;
								size=filesystem_size_of_files[i][j];
								break;
							}
						}
						break;
					}
				}
			}
			if(before_colon2=="")
			{
			//cout<<"le here"<<endl;
			//cout<<input_buffer<<endl;
			//cout<<length_of_file<<endl;
			FILE* fp = fopen(after_colon2.c_str(), "w+");
			fwrite(input_buffer,length_of_file,1,fp);
			fclose(fp);
			}
			else
			{
			
				for(int i=0;i<filesystem_name_index;i++)
				{
					if(before_colon2==filesystem[i][0])
					{
					
						
						//int fd = open(before_colon2.c_str(), O_WRONLY);
						//close(fd);
						FILE* fp = fopen(before_colon2.c_str(), "r+");
						//cout<<"pe here"<<endl;
						int offset=400+number_of_files[i]*1024;
						//cout<<offset<<endl;
						fseek(fp,offset,SEEK_SET);
						//cout<<"pe here"<<endl;
						//char length_in_string[10];
						//snprintf(length_in_string, sizeof(length_in_string), "%d", length_of_file);
						fwrite(&length_of_file,4,1,fp);
						//cout<<"pe here"<<endl;
						fseek(fp,offset+4,SEEK_SET);
						fwrite(input_buffer,length_of_file,1,fp);
						fclose(fp);
						filesystem[i][1+number_of_files[i]]=after_colon2;
					
						filesystem_size_of_files[i][1+number_of_files[i]]=length_of_file;
						number_of_files[i]++;
						break;
					}
				}
			}
			
		}
		else if(command=="ls")
		{
			for(int i=0;i<filesystem_name_index;i++)
			{
				if(filesystem[i][0]==arg1)
				{
					int k=number_of_files[i],j=1;
					while(k!=0)
					{
						if(filesystem[i][j]!="")
						{	
							cout<<filesystem[i][j]<<"....."<<filesystem_size_of_files[i][j]<<"MB"<<endl;
							
							k--;
							
						}
						j++;
					}
					break;
				}
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
									filesystem[i][j]=after_colon2;
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
									filesystem_size_of_files[i][j]=0;
									filesystem[i][j]="";
									number_of_files[i]--;
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
			for(int i=0;i<filesystem_name_index;i++)
			{
				if(before_colon==filesystem[i][0])
				{
					for(int j=1;j<=number_of_files[i];j++)
					{
						if(after_colon==filesystem[i][j])
						{
							
							FILE* fp = fopen(before_colon.c_str(), "r+");
							//cout<<"pe here"<<endl;
							int offset=400+(j-1)*1024;
							//cout<<offset<<endl;
							fseek(fp,offset,SEEK_SET);
							//cout<<"pe here"<<endl;
							
							//char length_in_string[10];
							//snprintf(length_in_string, sizeof(length_in_string), "%d", length_of_file);
							
							fwrite("",length_of_file+4,1,fp);
							fclose(fp);
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
	
