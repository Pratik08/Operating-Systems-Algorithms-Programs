/**
*SJF.c
*
*Pratik Dubal
*
*pratik.dubal08@gmail.com
*
**/

#include<stdio.h>

struct pro
{
	int pid;
	int at;
	int bt;
};

void main()
{
	struct pro p[10], temp;
	int i, j, n, pos;
	int wt[10], tat[10], et[10];
	float wtavg = 0, tatavg = 0;
	printf("\nEnter the number of processes: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		p[i].pid = i;		
		printf("\nEnter the arrival time of process %d: ",i);
		scanf("%d", &p[i].at);
		printf("\nEnter the burst time of process %d: ",i);
		scanf("%d", &p[i].bt);	
	}
	printf("\nP[i]\tAT[i]\tBT[i]\n");
	for(i = 0; i < n; i++)
	{
		printf("\n%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt);
	}
	for(i = 0; i < (n - 1); i++)
	{
		pos = i;		
		for(j = i + 1; j < n; j++)
		{
			if(p[j].bt < p[pos].bt)
			{
				pos = j;
			}
		}
		if (pos != i)
		{
			temp.pid = p[i].pid;
			temp.at = p[i].at;
			temp.bt = p[i].bt;
			p[i].pid = p[pos].pid;
			p[i].at = p[pos].at;
			p[i].bt = p[pos].bt;
			p[pos].pid = temp.pid;
			p[pos].at = temp.at;
			p[pos].bt = temp.bt;	
		}
	}
	printf("\nP[i]\tAT[i]\tBT[i]\n");
	for(i = 0; i < n; i++)
	{
		printf("\n%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt);
	}
	for (i = 0; i < n; i++)
	{
		if (i == 0)
		{
			et[i] = p[i].bt;
		}
		else
		{
			et[i] = p[i].bt + et[i - 1];
		}
	}
	for (i = 0; i < n; i++)
	{
		if (i == 0)
		{
			wt[i] = 0;
		}
		else
		{
			wt[i] = et[i - 1] - p[i].at;
		}
	}
	for (i = 0; i < n; i++)
	{
		tat[i] = wt[i] + p[i].bt;
	}
	printf("\nP[i]\tAT[i]\tBT[i]\tWT[i]\tTAT[i]\n");
	for (i = 0; i < n; i++)
	{
		printf("\n%d\t%d\t%d\t%d\t%d\n",p[i].pid, p[i].at, p[i].bt, wt[i], tat[i]);
	}
	for (i = 0; i < n; i++)
	{
		wtavg += wt[i];
		tatavg += tat[i];
	}
	printf("\nAverage waiting time: %f", wtavg/n);
	printf("\nAverage turnaround time: %f\n", tatavg/n);
}
