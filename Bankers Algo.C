/**
*
*Bankers Algorithm
*
*Pratik Dubal
*
*pratik.dubal08@gmail.com
*
**/

#include<stdio.h>
#include<conio.h>

void disp(int res[][5], int np, int nr)
{
	int i, j;
	printf("\nPID\t");
	for (i = 0; i < nr; i++)
	{
		printf("R%d\t", i + 1);
	}
	for(i = 0; i < np; i++)
	{
		printf("\n%d\t", i + 1);
		for(j = 0; j < nr; j++)
		{
			printf("%d\t", res[i][j]);
		}
	}
}

void main()
{
	int max[5][5], alloc[5][5], need[5][5], avail[5], pexec[5];
	int i, j, np, nr, temp, break_flag = 0, notavail_flag = 0, exec_flag = 0, safe_flag = 0;
	clrscr();
	printf("\nEnter the number of processes: ");
	scanf("%d", &np);
	printf("\nEnter the number of resources: ");
	scanf("%d", &nr);
	for(i = 0; i < np; i++)
	{
		for(j = 0; j < nr; j++)
		{
			printf("\nEnter the allocated resource %d for process %d: ", j + 1, i + 1);
			scanf("%d", &alloc[i][j]);
			printf("\nEnter the maximum resource %d for process %d: ", j + 1, i + 1);
			scanf("%d", &max[i][j]);
		}
	}
	for(i = 0; i < np; i++)
	{
		for(j = 0; j < nr; j++)
		{
			temp = max[i][j] - alloc[i][j];
			if(temp < 0)
			{
				temp = 0;
			}
			need[i][j] = temp;
		}
	}
	printf("\nAllocated matrix\n");
	disp(alloc, np, nr);
	printf("\nMaximum matrix\n");
	disp(max, np, nr);
	printf("\nNeed matrix\n");
	disp(need, np, nr);
	for(i = 0; i < nr; i++)
	{
		printf("\nEnter the Available resource for resource %d: ", i + 1);
		scanf("%d", &avail[i]);
	}
	printf("\nAvailable resources\n");

	for (i = 0; i < nr; i++)
	{
		printf("R%d\t%d\n", i + 1, avail[i]);
	}
	for (i = 0; i < np; i++)
	{
		pexec[i] = 0;
	}
	while(break_flag == 0)
	{
		exec_flag = 0;
		for(i = 0; i < np; i++)
		{
			notavail_flag = 0;
			for(j = 0; j < nr; j++)
			{
				if((need[i][j] > avail[j]) && (pexec[i] == 0))
				{
					notavail_flag = 1;
					break;
				}
			}
			if((!notavail_flag) && (pexec[i] == 0))
			{
				exec_flag = 1;
				printf("\nProcess %d has been executed.", i + 1);
				pexec[i] = 1;
				for(j = 0; j < nr; j++)
				{
					avail[j] -= need[i][j];
					avail[j] += need[i][j] + alloc[i][j];
					alloc[i][j] = 0;
					need[i][j] = -1;
				}
			}
		}
		if(!(exec_flag))
		{
			break_flag = 1;
		}
		else
		{
			break_flag = 0;
		}
	}
	safe_flag = 1;
	for(i = 0; i < np; i++)
	{
		if(pexec[i] == 0)
		{
			printf("\n\nProcess %d could not be executed.", i + 1);
			safe_flag = 0;
		}
	}
	if(safe_flag)
	{
		printf("\nSafe state.\n");
	}
	else
	{
		printf("\nUnsafe state.\n");
	}
	getch();
}
