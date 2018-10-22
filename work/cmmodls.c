#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
	while(1)
	{
		printf("[myshell@my hostname test]# ");
		fflush(stdout);
		char buf[1024];
		ssize_t s=read(0,buf,sizeof(buf)-1);
		if(s>0)
		{
			buf[s-1]='\0';
		}
		char* temp[32];
		char * start=buf;
		temp[0]=start;
		int i=1;
		while(*start)
		{
			if(*start ==' ')
			{
				*start='\0';
				start++;
				temp[i]=start;
				i++;
			}else
			{
				start++;
			}
		}
		temp[i]=NULL;
		pid_t id= fork();
		if(id==0)
		{
			execvp(temp[0],temp);
			exit(1);
		}
		else if(id > 0)
		{
		pid_t ret=0;
		ret=waitpid(id,NULL,0);
		}	
		else
		{
		}
	}	
	return 0;
}
			
