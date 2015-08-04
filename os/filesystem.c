#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char arg1[20],name_of_drive[20];
typedef char (master)[10];
	master name[100][100];
	int no_of_file[20],drive_count=0,size[100][100];
	
	
	
	int  d,count=0,no_of_blocks=0,t,r=0,v=0,slave1=1,slave2=1,xc,b=0,a1,a2,m,n,z=0,w,i,j,k,l,temp,par,e,ft,freelist[4][100],block[100],length,no_of_block[100],spc,flag=1;
	long cnt;
	FILE *fp,*fs,*fo,*fg,*fd,*fr;
	
	char  opcode[20],arg2[20],arg3[20],ins[20],temp1[20],temp2[20],temp3[20],temp4[20],temp5[20],drive2[20],oldn[20],temp6[100],new_number[10],ch='g',c,*file1[100],*file2[100],* name_of_drive[100],ref[100],rt[100],c1;
	int status,f1=0,f2=0;
void ls()
{
	
		name_of_drive[0]=arg1[0];
		name_of_drive[1]=0;
		strcat(name_of_drive,".txt");
		//puts(name[0][1]);
		for(i=0;i<=drive_count;i++)
		{
			if(strcmp(name_of_drive,name[i][0])==0)
			{
			for(j=0;j<no_of_file[i];j++)
				{
					printf("%s	%d\n",name[i][j+1],size[i][j+1]);
				}
				break;
			}

		}
}

void mv()
{
int flag=0;
		name_of_drive[0]=arg1[0];
		name_of_drive[1]=0;
		strcat(name_of_drive,".txt");
		for(i=2;arg1[i]!=0;i++)
		{
			temp2[i-2]=arg1[i];
		}
		temp2[i-2]=0;
		strcat(temp2,".txt");
		for(i=2;arg2[i]!=0;i++)
		{
			temp3[i-2]=arg2[i];
		}
		temp3[i-2]=0;
		strcat(temp3,".txt");
		
		for(i=0;i<=drive_count;i++)
		{
			if(strcmp(name[i][0],name_of_drive)==0)
			{
				for(j=0;j<no_of_file[i];j++)
				{
					if(strcmp(name[i][j+1],temp2)==0)
					{
					b=rename(temp2,temp3);strcpy(name[i][j+1],temp3);
					flag=1;
					break;
					}
				}
			}
		}
		if(!flag)
		{
			printf("File not found.");
		}
}


void rm()
{
name_of_drive[0]=arg1[0];
			name_of_drive[1]=0;
			strcat(name_of_drive,".txt");
			for(i=2;arg1[i]!=0;i++)
			{
				temp2[i-2]=arg1[i];
				
			}
			temp2[i-2]=0;
			strcat(temp2,".txt");
			for(i=0;i<=drive_count;i++)
			{
				if(strcmp(name[i][0],name_of_drive)==0)
				{
					for(j=0;j<no_of_file[i];j++)
					{
						if(strcmp(name[i][j+1],temp2)==0)
						{
					
							for(k=j+1;k<no_of_file[i]-1;k++)
							{
								strcpy(name[i][k],name[i][k+1]);
								size[i][k]=size[i][k+1];
							}
							no_of_file[i]--;
						}
					}
				}
			}
			status = remove(temp2);
			
 
   			if( status == 0 )
      				printf("%s file deleted successfully.\n",arg1);
  	 		else
   			{
     	 			printf("Unable to delete the file\n");
      				perror("Error");
   			}
}



void mkfs()
{
strcat(arg1,".txt");
			
			fp=fopen(arg1,"w");
			d=atoi(arg2);
			xc=atoi(arg3);
			
			if(fp!=NULL)
			{
		
				for(i=0;i<xc*1048576;i++)
				{
					fprintf(fp,"%c",ch);
				}
		
			}
			//name[drive_count][0]=rt;
			strcpy(name[drive_count][0],arg1);
			size[drive_count][0]=xc;
			block[drive_count]=d;
			no_of_file[drive_count]=0;
			drive_count++;
			fclose(fp);
}

void use_as()
{
strcat(arg1,".txt");
		strcpy(oldn,arg1);
		
		
		for(j=0;arg3[j]!=':';j++)
			{
				new_number[j]=arg3[j];
			}
		new_number[j]=0;
		strcat(new_number,".txt");
		for(i=0;i<drive_count;i++)
		{
			if(strcmp(name[i][0],arg1)==0)
			{
				
				b=rename(oldn,new_number);
				strcpy(name[i][0],new_number);
				break;
			}
		}
}
void cp()
{
no_of_blocks=0;
		f1=0;
		f2=0;
		if(arg1[1]==':')
		{
			drive2[0]=temp3[0]=arg1[0];
			drive2[1]=temp3[1]=0;
			strcat(drive2,".txt");
			f2=1;
						
		for(i=2;arg1[i]!=0;i++)
			{
				temp1[i-2]=arg1[i];
			}
			temp1[i-2]=0;
			strcat(temp1,".txt");
			for(i=0;i<=drive_count;i++)
				{
				if(strcmp(drive2,name[i][0])==0)
					{
						a2=i;
						break;
					}
				
			}
		}
		else
		{
			for(i =0;arg1[i]!=0;i++)
			{

			temp1[i]=arg1[i];
			}
			temp1[i]=0;
			strcat(temp1,".txt");
			
		}
		
		if(arg2[1]==':')
		{
			name_of_drive[0]=temp4[0]=arg2[0];
			name_of_drive[1]=temp4[1]=0;
			strcat(name_of_drive,".txt");
			
			for(i=2;arg2[i]!=0;i++)
			{
				temp2[i-2]=arg2[i];
			}
			temp2[i-2]=0;
			strcat(temp2,".txt");
			
			for(i=0;i<drive_count;i++)
				{//printf("HELLO");
					if(strcmp(name_of_drive,name[i][0])==0)
						{//printf("HI");
						f1=1;
						a1=i;
						//name[i][no_of_file[i]+1]=rt;
						strcpy(name[i][no_of_file[i]+1],temp2);
						size[i][no_of_file[i]+1]=cnt;spc=i;
						no_of_file[i]++;
						break;
					}
				
			}
			}
		else
		{
			for(i =0;arg2[i]!=0;i++)
			{
				temp2[i]=arg2[i];
			}
			temp2[i]=0;
			strcat(temp2,".txt");
			
		}	
		
		if(f2==1 && f1==1)
		{
			fo=fopen(temp2,"w");
			strcat(temp3,"dir.txt");	
			fs=fopen(temp3,"r");
			fp=fopen(drive2,"r");
			fg=fopen(name_of_drive,"w");
			strcat(temp4,"dir.txt");
			fr=fopen(temp4,"a+");
			fseek(fr,0,SEEK_END);
			fprintf(fr,"#%s#",temp2);
			//puts(temp4);
			m=block[a2];
			w=block[a1];
			n=size[a2][0];slave1=1;
			e=size[a1][0];	
			while(!feof(fs))
			{jack2:
				i=0;flag=0;
				fscanf(fs,"%c",&c);
				fscanf(fs,"%c",&c);
				while(c!='#')
				{
					if(c!='#')
					{
						ref[i]=c;
						i++;
					}
					fscanf(fs,"%c",&c);
				}
				ref[i]=0;
				if(strcmp(ref,temp1)==0)
				{	
					flag=6;			
					break;
				}
				if(flag!=6)
				{
					while(c!='?')
					{
						fscanf(fs,"%c",&c);
					}goto jack2;
				}
			}
			c='k';v=0;
			if(m==w)
			{
				ft=10;
			}
			else if(w<m)
			{	
				ft=9;
			}
			else
			{
				ft=8;
			}
			if(ft==10)
			{c1='k';    
			while(!feof(fs) && c1!='?')
			{	t=0;
				fscanf(fs,"%d%c",&r,&c1);if( c1=='?')
					{break;}
				fseek(fp,r*m,SEEK_SET);
				while(freelist[a1][v]!=1)
				{
					v++;
							
				}
				freelist[a1][v]=1;
				fprintf(fr,"%d-",v);
				fseek(fs,v*w,SEEK_SET);c='k';
				while(t<=m && !feof(fp))
				{
					fscanf(fp,"%c",&c);
					fprintf(fo,"%c",c);
					fprintf(fg,"%c",c);
					t++;
				}if(feof(fp)){break;}
			}
			fprintf(fr,"0?");
			}
			else if(ft==9)
			{c1='k';
				while(!feof(fs))
				{	t=0;
					if(slave1==1)
					{
						fscanf(fs,"%d%c",&r,&c1);
						if( c1=='?')
						{
							break;
						}
						fseek(fp,r*m,SEEK_SET);
					}
				while(freelist[a1][v]!=0)
				{
					v++;
								
				}
				freelist[a1][v]=1;
				fprintf(fr,"%d-",v);//printf("%d",v);
				fseek(fs,v*w,SEEK_SET);
				if(slave1==1){while(t<=w && !feof(fp))
				{
					fscanf(fp,"%c",&c);
					fprintf(fo,"%c",c);
					fprintf(fg,"%c",c);
					t++;
				}}slave1=slave1*(-1);if(feof(fp)){break;}
			}
			fprintf(fr,"0?");	
			}
			else if(ft==8)
			{c1='k';
				while(!feof(fs)&& c1!='?')
				{	t=0;
				fscanf(fs,"%d%c",&r,&c1);//printf("%c",c1);
				if( c1=='?')
					{break;}
				fseek(fp,r*m,SEEK_SET);
				if(slave1==1)
				{while(freelist[a1][v]!=0)
				{
					v++;
								
				}
				freelist[a1][v]=1;
				fprintf(fr,"%d%c",v,c1);//printf("%d",v);
				fseek(fs,v*w,SEEK_SET);
				while(t<=m && !feof(fp))
				{
					fscanf(fp,"%c",&c);
					fprintf(fo,"%c",c);
					fprintf(fg,"%c",c);
					t++;
				}}slave1=slave1*(-1);if(feof(fp)){break;}
			}
				fprintf(fr,"0?");
			}
			fclose(fo);
			fclose(fs);
			fclose(fp);
			fclose(fg);
			fclose(fr);
		}
		
		else if(f2==0 && f1==1)
		{r=0;
			fp=fopen(temp1,"r");
			fseek(fp,0,SEEK_END);
			cnt=ftell(fp);
			fseek(fp,0,SEEK_SET);
			fclose(fp);
			fp=fopen(temp1,"r");
			m=block[a1];
			no_of_blocks=cnt/m;
			if(cnt%m !=0)
			{
				no_of_blocks=no_of_blocks+1;
			}size[spc][no_of_file[spc]]=cnt/m+cnt%m;
			fo=fopen(temp2,"w");
			fs=fopen(name[a1][0],"w");
			strcat(temp4,"dir.txt");
			fg=fopen(temp4,"a+");
			n=(size[a1][0]*1024*1024)/m;
			fprintf(fg,"#%s#",temp2);
			while(no_of_blocks)
			{
				while(freelist[a1][r]!=0)
				{
					r++;
				}
				freelist[a1][r]=1;
				fprintf(fg,"%d-",r);
				fseek(fs,r*m,SEEK_SET);
				t=0;
				
				while(!feof(fp) && t<=block[a1] )
				{
					fscanf(fp,"%c",&c);
					fprintf(fo,"%c",c);
					fprintf(fs,"%c",c);
					t++;

					
				}
				no_of_blocks--;
				
			}
			fprintf(fg,"%d?",0);
			
			fclose(fg);
			fclose(fo);
			fclose(fp);
			fclose(fs);
		}
		else if(f2==1 && f1==0)
		{
			fo=fopen(temp2,"w");
			strcat(temp3,"dir.txt");	
			 fs=fopen(temp3,"r");
			fp=fopen(drive2,"r");
			m=block[a2];
			n=size[a2][0];	i=0;
			while(!feof(fs))
			{jack:
				i=0;flag=0;
				fscanf(fs,"%c",&c);
				fscanf(fs,"%c",&c);
				while(c!='#')
				{	
					if(c!='#')
					{
						ref[i]=c;
						i++;
					}
					fscanf(fs,"%c",&c);
					
				}
				ref[i]=0;
				
				if(strcmp(ref,temp1)==0)
				{	
					flag=6;			
					break;
				}


				if(flag!=6)
				{
					while(c!='?')
					{
						fscanf(fs,"%c",&c);
					}goto jack;
				}
			}
			c='k';c1='k';
			
			while(c1!='?')
			{	t=0;
				fscanf(fs,"%d%c",&r,&c1);//printf("%d%c",r,c1);
				if( c1=='?')
					{break;}
				fseek(fp,r*m,SEEK_SET);
				while(!feof(fp) && t<=m)
				{
					fscanf(fp,"%c",&c);
					fprintf(fo,"%c",c);
					t++;
				}
			}
			
			fclose(fo);
			fclose(fs);
			fclose(fp);
		}

		
		
	
}







int main()
{
	
		
	
	
	
	d=0;
	rt[0]='k';
	rt[1]=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<100;j++)
		{
			freelist[i][j]=0;
		}
	}
	while(flag)
	{
		printf("MYFILE:>");
		gets(ins);
		strcat(ins," ");
		length=strlen(ins);
		j=0;
		b=0;
		for(i=0;i<length;i++)
		{
			if(ins[i]==' ')
			{	
				b++;
				
				if(b==1)
				{
					for(k=j;k<i;k++)
					{
						opcode[k-j]=ins[k];
					}
					opcode[k-j]=0;
					
				}
				else if(b==2)
				{
					
					for(k=j;k<i;k++)
					{
						arg1[k-j]=ins[k];
					}
					arg1[k-j]=0;
				}
				else if(b==3)
				{
					for(k=j;k<i;k++)
					{
						arg2[k-j]=ins[k];
					}
					arg2[k-j]=0;
				}
				else if(b==4)
				{
					for(k=j;k<i;k++)
					{
						arg3[k-j]=ins[k];
					}
					arg3[k-j]=0;
					
				}
				j=i+1;
			}	
		}
	//printf("%sa%sb%sc	%s",opcode,arg1,arg2,ins);
	if(strcmp(opcode,"ls")==0)
	{
		ls();
	}
	else if(strcmp(opcode,"mv")==0)
	{
		mv();
		
		
	} 
	else if(strcmp(opcode,"exit")==0)
		{
			exit(0);
		}

	else if(strcmp(opcode,"rm")==0)
		{
			rm();	
		}
	else if(strcmp(opcode,"mkfs")==0)
		{
			
			mkfs();
		
		}
	else if(strcmp(opcode,"use")==0 && strcmp(arg2,"as")==0)
	{
			
		
		use_as();
		
		
	}
	else if(strcmp(opcode,"cp")==0)
	{
		cp();
			
		
	}
	else 
	{
		
		printf("Command does not exist");
	}
	}
	return 0;
	
}
