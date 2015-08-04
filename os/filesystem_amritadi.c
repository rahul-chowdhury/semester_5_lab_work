#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
	
	FILE * fp;
	FILE * fs;
	FILE * fo;
	FILE * fg;
	FILE * fr;
	FILE * fd;
	char  opcode[20];
	char  arg1[20];
	char  arg2[20];
	char  arg3[20];
	char  ins[100];
	char tempo1[20];
	char tempo2[20];
	char tempo3[20];
	char tempo4[20];
	char tempo5[20];
	char drivename[10];
	char drivename2[10];
	char  oldn[10];
	char  newn[10];
	int status,f1=0,f2=0;	
	int no_of_file[20];
	char ch='g',c;
	int d,count=0,count_of_drive=0,number_of_block=0,t,r=0,v=0,jerry1=1,jerry2=1;
	d=0;int xc;
	int b=0,a1,a2,m,n,z=0,w;
	int i,j,k,l,temp,par,e,ft;
	int  freelist[4][100];
	char tempo6[100];
	typedef char (tom)[10];
	tom name[100][100];
	char *  filename1[100];
	char *  filename2[100];
	char * name_of_drive[100];
	char ref[100];
	int size[100][100];
	int block[100];
	int length;
	long cnt;char c1;
	int no_of_block[100];int spc;
	int flag=1;
	char rt[100];rt[0]='k';rt[1]=0;
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
		drivename[0]=arg1[0];
		drivename[1]=0;
		strcat(drivename,".txt");
		//puts(name[0][1]);
		for(i=0;i<=count_of_drive;i++)
		{
			if(strcmp(drivename,name[i][0])==0)
			{
			for(j=0;j<no_of_file[i];j++)
				{
					printf("%s	%d\n",name[i][j+1],size[i][j+1]);
				}
				break;
			}

		}
	}
	else if(strcmp(opcode,"mv")==0)
	{
		int flag=0;
		drivename[0]=arg1[0];
		drivename[1]=0;
		strcat(drivename,".txt");
		for(i=2;arg1[i]!=0;i++)
		{
			tempo2[i-2]=arg1[i];
		}
		tempo2[i-2]=0;
		strcat(tempo2,".txt");
		for(i=2;arg2[i]!=0;i++)
		{
			tempo3[i-2]=arg2[i];
		}
		tempo3[i-2]=0;
		strcat(tempo3,".txt");
		
		for(i=0;i<=count_of_drive;i++)
		{
			if(strcmp(name[i][0],drivename)==0)
			{
				for(j=0;j<no_of_file[i];j++)
				{
					if(strcmp(name[i][j+1],tempo2)==0)
					{
					b=rename(tempo2,tempo3);strcpy(name[i][j+1],tempo3);
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
	else if(strcmp(opcode,"exit")==0)
		{
			exit(0);
		}

	else if(strcmp(opcode,"rm")==0)
		{
			drivename[0]=arg1[0];
			drivename[1]=0;
			strcat(drivename,".txt");
			for(i=2;arg1[i]!=0;i++)
			{
				tempo2[i-2]=arg1[i];
				
			}
			tempo2[i-2]=0;
			strcat(tempo2,".txt");
			for(i=0;i<=count_of_drive;i++)
			{
				if(strcmp(name[i][0],drivename)==0)
				{
					for(j=0;j<no_of_file[i];j++)
					{
						if(strcmp(name[i][j+1],tempo2)==0)
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
			status = remove(tempo2);
			
 
   			if( status == 0 )
      				printf("%s file deleted successfully.\n",arg1);
  	 		else
   			{
     	 			printf("Unable to delete the file\n");
      				perror("Error");
   			}	
		}
	else if(strcmp(opcode,"mkfs")==0)
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
			//name[count_of_drive][0]=rt;
			strcpy(name[count_of_drive][0],arg1);
			size[count_of_drive][0]=xc;
			block[count_of_drive]=d;
			no_of_file[count_of_drive]=0;
			count_of_drive++;
			fclose(fp);
		
		}
	else if(strcmp(opcode,"use")==0 && strcmp(arg2,"as")==0)
	{
		strcat(arg1,".txt");
		strcpy(oldn,arg1);
		
		
		for(j=0;arg3[j]!=':';j++)
			{
				newn[j]=arg3[j];
			}
		newn[j]=0;
		strcat(newn,".txt");
		for(i=0;i<count_of_drive;i++)
		{
			if(strcmp(name[i][0],arg1)==0)
			{
				
				b=rename(oldn,newn);
				strcpy(name[i][0],newn);
				break;
			}
		}	
		
		//printf("%d",b);
		
		
	}
	else if(strcmp(opcode,"cp")==0)
	{
		number_of_block=0;
		f1=0;
		f2=0;
		if(arg1[1]==':')
		{
			drivename2[0]=tempo3[0]=arg1[0];
			drivename2[1]=tempo3[1]=0;
			strcat(drivename2,".txt");
			f2=1;
						
		for(i=2;arg1[i]!=0;i++)
			{
				tempo1[i-2]=arg1[i];
			}
			tempo1[i-2]=0;
			strcat(tempo1,".txt");
			for(i=0;i<=count_of_drive;i++)
				{
				if(strcmp(drivename2,name[i][0])==0)
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

			tempo1[i]=arg1[i];
			}
			tempo1[i]=0;
			strcat(tempo1,".txt");
			
		}
		
		if(arg2[1]==':')
		{
			drivename[0]=tempo4[0]=arg2[0];
			drivename[1]=tempo4[1]=0;
			strcat(drivename,".txt");
			
			for(i=2;arg2[i]!=0;i++)
			{
				tempo2[i-2]=arg2[i];
			}
			tempo2[i-2]=0;
			strcat(tempo2,".txt");
			
			for(i=0;i<count_of_drive;i++)
				{//printf("HELLO");
					if(strcmp(drivename,name[i][0])==0)
						{//printf("HI");
						f1=1;
						a1=i;
						//name[i][no_of_file[i]+1]=rt;
						strcpy(name[i][no_of_file[i]+1],tempo2);
						size[i][no_of_file[i]+1]=cnt;spc=i;
						no_of_file[i]++;
						break;
					}
				
			}//printf("%d %d",f2,f1);
		}
		else
		{
			for(i =0;arg2[i]!=0;i++)
			{
				tempo2[i]=arg2[i];
			}
			tempo2[i]=0;
			strcat(tempo2,".txt");
			
		}	
		
		if(f2==1 && f1==1)
		{
			fo=fopen(tempo2,"w");
			strcat(tempo3,"dir.txt");	
			fs=fopen(tempo3,"r");
			fp=fopen(drivename2,"r");
			fg=fopen(drivename,"w");
			strcat(tempo4,"dir.txt");
			fr=fopen(tempo4,"a+");
			fseek(fr,0,SEEK_END);
			fprintf(fr,"#%s#",tempo2);
			//puts(tempo4);
			m=block[a2];
			w=block[a1];
			n=size[a2][0];jerry1=1;
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
				if(strcmp(ref,tempo1)==0)
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
					if(jerry1==1)
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
				if(jerry1==1){while(t<=w && !feof(fp))
				{
					fscanf(fp,"%c",&c);
					fprintf(fo,"%c",c);
					fprintf(fg,"%c",c);
					t++;
				}}jerry1=jerry1*(-1);if(feof(fp)){break;}
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
				if(jerry1==1)
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
				}}jerry1=jerry1*(-1);if(feof(fp)){break;}
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
			fp=fopen(tempo1,"r");
			fseek(fp,0,SEEK_END);
			cnt=ftell(fp);
			fseek(fp,0,SEEK_SET);
			fclose(fp);
			fp=fopen(tempo1,"r");
			m=block[a1];
			number_of_block=cnt/m;
			if(cnt%m !=0)
			{
				number_of_block=number_of_block+1;
			}size[spc][no_of_file[spc]]=cnt/m+cnt%m;
			fo=fopen(tempo2,"w");
			fs=fopen(name[a1][0],"w");
			strcat(tempo4,"dir.txt");
			fg=fopen(tempo4,"a+");
			n=(size[a1][0]*1024*1024)/m;
			fprintf(fg,"#%s#",tempo2);
			while(number_of_block)
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
				number_of_block--;
				
			}
			fprintf(fg,"%d?",0);
			
			fclose(fg);
			fclose(fo);
			fclose(fp);
			fclose(fs);
		}
		else if(f2==1 && f1==0)
		{
			fo=fopen(tempo2,"w");
			strcat(tempo3,"dir.txt");	
			 fs=fopen(tempo3,"r");
			fp=fopen(drivename2,"r");
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
				
				if(strcmp(ref,tempo1)==0)
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
	else 
	{
		
		printf("Command does not exist");
	}
	}
	
	
}
