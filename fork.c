/**
*fork.c
*
*Pratik Dubal
*
*pratik.dubal08@gmail.com
*
**/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int d, i;
	d = fork();
	wait(50);
	if(!d)
	{
		printf("\nIn child process %d belonging to parent process %d\n", getpid(), getppid());
		for(i = 0; i <= 20; i += 5 )
		{
			printf("%d\n", i);
		}
	}
	else
	{
		printf("\nIn parent proces %d\n", getpid());
		for(i = 0; i <= 20; i += 10 )
		{
			printf("%d\n", i);
		}		
	}
	return 0;
}
