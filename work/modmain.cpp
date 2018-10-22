#include <stdlib.h>
#include "mod_compile.cpp"
#include "mod.h"
#include <unistd.h>
int main(int argc,char *argv[])
{
	char cmdstring[MAX_CMD];
	int n;
	while(1)
	{
		printf("myshell>###");
		fflush(stdout);

		if((n==read(0,cmdstring,MAX_CMD))< 0)
		{
			printf("read error");
		}
		
		eval(cmdstring);
	}
	return 0;
}
