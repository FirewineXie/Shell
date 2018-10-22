#include "mod.h"

base::eval(char *cmdstring)
{
	//Unix分内置和外置命令，内置不需要开进程，
	char *argv[MAX_CMD];
	char buf[MAX_CMD];

	strcpy(buf,cmdstring);
	parseline(buf,argv);
	if(argv[0] == NULL){
	 	return;
	}
	if(buildin_command(argv)) return;
	int pid = fork();
	if(pid == 0){
		if(execvp(argv[0],argv)<0){
			printf("%s:command not found.\n",argv[0]);
			exit(0);
		}
	}
	wait(pid);
}
base::parseline(char *buf,char **argv)
{
	while(*buf == ' ')
	{
		buf++;
	}
	int delim = 0;
	
	int argc = 0;
	while(*buf != '\n')
	{
		while(buf(delim != '\n' && buf[delim] != ' '))
		{
			delim++;
		}
		if(buf[delim] == '\n')
		{
			buf[delim] = '\n';
			argv[argc++] = buf;
			break;
		}
		buf[delim] = '\0';
		argv[argc++] = buf;

		buf += delim +1;
		
		delim = 0;
		while(*buf == ' ')
		{
			buf++;
		}
	}
	argv[argc]= NULL;
	return 0;
}
base::buildin_command(char **argv)
{
	if(strcmp(argv[0],"exit")==0)
	{
		exit(0);
	}
	if(strcmp(argv[0],"cd")==0)
	{
		if(chdir(argv[1]))
		{
			printf("myselous:cd:%s:no such directory\n",argv[1]);
		}
		return 1;
	}
	if(strcmp(argv[0],"pwd")==0)
	{
		char buf[MAX_DIR_NAME];
		printf("%s\n",getcwd(buf,sizeof(buf)));
		return 1;
	}
	return 0;
}
