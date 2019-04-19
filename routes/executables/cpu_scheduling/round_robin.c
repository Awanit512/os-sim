#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct process
{
	int process_id;
	int arrival_time;
	int burst_time;
	int waiting_time;
	int turn_around_time;
	int remaining_time;
	int completion_time;
};

int main(int argc,char const*argv[])
{
	int i,j,min,l;
	float wait_time_total = 0.0, tat = 0.0;
	int n=atoi(argv[1]);
	int k=0;
	struct process proc[n],temp;
	for(int i=2; i<=argc-2; i+=3)
	{
		proc[k].process_id =atoi(argv[i]);
		proc[k].arrival_time=atoi(argv[i+1]);
		proc[k].burst_time=atoi(argv[i+2]);
		proc[k].remaining_time = proc[k].burst_time;
		k++;
	}
	int t=atoi(argv[3*n+1]);

	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(proc[i].arrival_time>proc[j].arrival_time)
			{
				temp=proc[i];
				proc[i]=proc[j];
				proc[j]=temp;
			}
		}
	}
	min=proc[0].arrival_time;
	int queue[10000];
	queue[0]=0;
	j=0;
	i=0;
	k=0;
	while(k<=j)
	{
		if(proc[queue[k]].remaining_time>t)
		{
			for(l=0;l<t;l++)
			{
				if(proc[i+1].arrival_time==min)
				{
					queue[j+1]=i+1;
					i=i+1;
					j=j+1;
				}
				min=min+1;
			}
			proc[queue[k]].remaining_time=proc[queue[k]].remaining_time-t;
			queue[j+1]=queue[k];
			j=j+1;
		}
		else
		{
			for(l=0;l<proc[queue[k]].remaining_time;l++)
			{
				if(proc[i+1].arrival_time==min)
				{
					queue[j+1]=i+1;
					i=i+1;
					j=j+1;
				}
				min=min+1;
			}
			proc[queue[k]].completion_time=min;
		}
		k++;
	}
	for(int i=0; i<n; i++)
	{
		proc[i].turn_around_time=proc[i].completion_time-proc[i].arrival_time;
		proc[i].waiting_time=proc[i].turn_around_time-proc[i].burst_time;
		printf("%d\t%d\t", proc[i].process_id, proc[i].burst_time);
		printf("%d\t%d\t%d\t%d\n", proc[i].arrival_time, proc[i].waiting_time, proc[i].turn_around_time,proc[i].completion_time);

		tat += proc[i].turn_around_time;
		wait_time_total += proc[i].waiting_time;
	}

	tat = tat/(1.0*n);
	wait_time_total = wait_time_total/(1.0*n);

	printf("%f",wait_time_total);
	printf("\n%f", tat);
}
