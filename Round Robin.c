/**
*RoundRobin.c
*
*Pratik Dubal
*
*pratik.dubal08@gmail.com
*
**/

#include<stdio.h>

struct proc
{
	int pid;
	int at;
	int bt;
	int wt;
	int tat;
	int rem;
	int et;
};

void main()
{
	int i, n, j, pos, quant, tot_burst = 0, tot_time = 0;
	float wtavg = 0, tatavg = 0;
	struct proc p[10], temp;
	printf("\nNumber of processes: ");
	scanf("%d", &n);
	printf("Enter process details as: PID AT BT\n");
	for(i = 0; i < n; i++)
	{
		printf("\nEnter details for process %d:\n", i + 1);
		scanf("%d %d %d", &p[i].pid, &p[i].at, &p[i].bt);
		p[i].wt = 0;
		p[i].tat = 0;
		p[i].rem = p[i].bt;
		p[i].et = 0;
	}
	printf("\nEnter the size of the time quantum: ");
	scanf("%d", &quant);
	printf("\nProcess Details\n");
	printf("P[i]\tAT[i]\tBT[i]\n");
	for(i = 0; i < n; i++)
	{
		printf("%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt);
	}
	/*for(i = 0; i < (n - 1); i++)
	{
		pos = i;		
		for(j = i + 1; j < n; j++)
		{
			if(p[j].at < p[pos].at)
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
	printf("\nProcess Details\n");
	printf("P[i]\tAT[i]\tBT[i]\n");
	for(i = 0; i < n; i++)
	{
		printf("%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt);
	}*/
	for(i = 0; i < n; i++)
	{
		tot_burst += p[i].bt;
	}
	while(tot_time < tot_burst)
	{
		for(i = 0; i < n; i++)
		{
			if(p[i].rem != 0)			
			{			
				if(quant < p[i].rem)
				{
					tot_time += quant;
					p[i].rem -= quant;
				}
				else
				{
					tot_time += p[i].rem;
					p[i].et = tot_time;				
					p[i].rem = 0;
				}
			}
		}
		
	}
	for(i = 0; i < n; i++)
	{
		p[i].tat = p[i].et - p[i].at;
		p[i].wt = p[i].tat - p[i].bt;
	}
	printf("\nProcess Details\n");
	printf("P[i]\tAT[i]\tBT[i]\tWT[i]\tTAT[i]\n");	
	for(i = 0; i < n; i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat);
	}
	for (i = 0; i < n; i++)
	{
		wtavg += p[i].wt;
		tatavg += p[i].tat;
	}
	printf("\nAverage waiting time: %f", wtavg/n);
	printf("\nAverage turnaround time: %f\n", tatavg/n);
}
