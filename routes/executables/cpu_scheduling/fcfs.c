#include <stdio.h>
#include <stdlib.h>
struct process
{
	int process_id;
	int arrival_time;
	int burst_time;
	int waiting_time;
	int turn_around_time;
	int completion_time;
};
int main(int argc, char const *argv[])
{
	int i,j;
	int n = atoi(argv[1]);
	
	struct process p[n],temp;
	
	int  k = 0;
	for(i = 2; i <= argc-2; i += 3) {
		p[k].process_id = atoi(argv[i]);
		p[k].arrival_time = atoi(argv[i+1]);
		p[k].burst_time = atoi(argv[i+2]);
		k++;
	}
	p[0].completion_time=p[0].arrival_time+p[0].burst_time;
	p[0].waiting_time=0;

	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].arrival_time>p[j+1].arrival_time)
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}	

	for(i=1;i<n;i++)
	{
		p[i].completion_time=p[i-1].completion_time+p[i].burst_time;
		p[i].waiting_time = p[i].completion_time-p[i].arrival_time;

		if(p[i].waiting_time<0)
			p[i].waiting_time=0;
	}

	for(i=0;i<n;i++)
	{
		p[i].turn_around_time = p[i].burst_time + p[i].waiting_time;
	}

	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].process_id>p[j+1].process_id)
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	int total_waiting_time=0,total_turn_around_time=0;
	for(i=0;i<n;i++)
	{
		total_waiting_time+=p[i].waiting_time;
		total_turn_around_time+=p[i].turn_around_time;
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].process_id,p[i].burst_time, p[i].arrival_time, p[i].waiting_time,p[i].turn_around_time,p[i].completion_time);
	}
	printf("%f\n", (float)total_waiting_time/n);
	printf("%f",(float)total_turn_around_time/n);
}
