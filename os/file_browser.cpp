#include <dirent.h> 
#include <stdio.h> 
#include<string.h>
#include <pwd.h>
#include <grp.h>
#include<iostream>
#include <sys/stat.h> 
#include <errno.h>


using namespace std;
int exit=0;
void current_directory(const char *pwd)
{
  DIR *d,*d1;
  
  
  struct dirent *dir;
  
  int count,choice,i;
  char *pwd1=new char[100];
  while(exit==0)
  {
  strcpy(pwd1,pwd);
  strcat(pwd1,"/");
  
  //cout<<"here1"<<endl;
  count=0;
 char name[1000][100];
  
  d = opendir(pwd);
 
//readdir(d);
  if (d)//loading contents into array
  {
    while ((dir = readdir(d)) != NULL)
    {
    	//cout<<dir->d_name<<endl;
    if(strcmp(dir->d_name,".")==0)
  	{
  		//cout<<"here"<<endl;
  		continue;
  	}
  	
  	strcpy(name[count],dir->d_name);
    	count++;
    	//cout<<count<<dir->d_name<<endl;    	
    }
    
  }
      
  else
  {
  	//cout<<"THIS IS NOT A DIRECTORY!!ENTER INPUT AGAIN"<<endl;
	//char filename[100],path[100];
  	//cout<<"select file/folder name from the list"<<endl;
  	//cin>>filename;
  	//strcpy(path,pwd1);
  	//strcat(path,filename);
  	struct stat buf; 
    	stat (pwd, &buf);
    	struct group *grp;
	struct passwd *kwd;

	kwd = getpwuid(buf.st_uid);
	printf("OWNER NAME: %s\n", kwd->pw_name);
	grp = getgrgid(buf.st_gid);
	printf("GROUP NAME: %s\n", grp->gr_name);



    	cout<<"OWNER PERMISSIONS: ";
    	if( buf.st_mode & S_IRUSR)
    		printf("read ");
    	else printf(" ");
    	if( buf.st_mode & S_IWUSR)
    		printf("write ");
    	else printf(" ");
    	if( buf.st_mode & S_IXUSR)
    		printf("execute\n");
    	else printf("\n");
    	cout<<"GROUP PERMISSIONS: ";
    	if( buf.st_mode & S_IRGRP)
    		printf("read ");
    	else printf(" ");
    	if( buf.st_mode & S_IWGRP)
    		printf("write ");
    	else printf(" ");
    	if( buf.st_mode & S_IXGRP)
    		printf("execute	   \n");
    	else printf("\n");
    	cout<<"OTHERS PERMISSIONS: ";
    	if( buf.st_mode & S_IROTH)
    		printf("read ");
    	else printf(" ");
    	if( buf.st_mode & S_IWOTH)
    		printf("write ");
    	else printf(" ");
    	if( buf.st_mode & S_IXOTH)
    		printf("execute");
    	else printf(" ");
    	printf("\n");
  	return;
  }
  //for(i=0;i<count;i++)
  //cout<<name[i]<<endl;
  for (i = 0; i < count-1; i++) { 
            for (int k = i+1; k < count; k++) { 
                if (strcmp(name[i], name[k])>0) { 



















                     char tmp[100];
                    strcpy(tmp,name[i]); 
                    strcpy(name[i] ,name[k]); 
                    strcpy(name[k],tmp); 
                } 
            } 
        } 
  closedir(d);
  
  //count=0;
 // d = opendir(pwd);
 
 if (d)//printing contents
  {
  	cout<<"****FILE LIST****"<<endl;
  	cout<<"0.	EXIT"<<endl;
	//readdir(d);

    	for(i=0;i<count;i++)
    	{
    		
    		
    			printf("%d.\t%s",i+1, name[i]);
    			
  	if(strcmp(name[i],"..")==0)
  		cout<<"(Parent directory)"<<endl;
  	else
  	{
  		char temp[100];
  		strcpy(temp,pwd1);
  		strcat(temp,name[i]);
    		d1=opendir(temp);
    		if(d1)
    			cout<<"(folder)"<<endl;
    		else
    			cout<<"(file)"<<endl;
    			closedir(d1);
    			
    	}
    		
    	}	
    //cout<<count+1<<".\tSEE FILE/FOLDER PERMISSIONS\n\n";
   
  } 
 // closedir(d);
 // for(i=0;i<count;i++)
  //cout<<name[i]<<endl;
  //cout<<"ENTER 0 TO EXIT"<<endl;
  cout<<"enter your choice: ";
 cin>>choice;
  if(choice==0)
  {
  	exit=1;
  	return;
  }
  /*else if(choice==count)
  {
  	return;
  }*/
  else if(choice==count-1)
  {
  	continue;
  }
  
  else if(choice<=count)
  {
  	strcat(pwd1,name[choice-1]);
  	cout<<"relative address of current directory: "<<pwd1<<endl;
  	current_directory(pwd1);
  }
  else
  {
  continue;
  }
  }
  
}

int main()
{
	
	current_directory(".");
		return 0;
}
