/*

IO FORMAT

   
For example if the input values are this:

	cylinder_size = 200
	current_head_position=50
	previous_head_position=90

	request_array = {95,180,34,11,119,123,64,62}



Command is executed as:
./exe_file cylinder_size current_head_position previous_head_position request_array

which in this case is,
./cscan 200 50 90 95 180 34 11 119 123 64 62
Output:
Sequence of movement is: 50 --> 34 --> 11 --> 180 --> 123 --> 119 --> 95 --> 64 --> 62 --> 
Total seek time = 187
Average Seek time = 23.375000
*/




#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

main(int argc, char **argv)
{
	int dir,n,r,totseek=0,prev,cur,ct=0,size,jr,posr,jl,posl;
	int req[10],seq[10];

	size = atoi(argv[1]);
	n = argc-4;
	int temp,i,j;
	
	for(i=4;i<argc;i++)
	req[ct++] = atoi(argv[i]);
	
	ct=0;
	
	cur = atoi(argv[2]);
	prev = atoi(argv[3]);
	
	if(cur>prev)
	dir = 1;
	else
	dir=0;
	
	for(i=0;i<n-1;i++)
	for(j=0;j<n-1-i;j++)
	if(req[j]>req[j+1])
	{
		temp = req[j];
		req[j]=req[j+1];
		req[j+1] = temp;
	}
	i=0;
	while(req[i]<cur)
	i++;
	jr = req[i];
	posr=i;
	i=n-1;
	while(req[i]>cur)
	i--;
	jl = req[i];
	posl=i;
	if(dir)
	{
		totseek = (jl)  + (size-1-cur);
		for(i=0;i<n;i++)
		{
			if(req[i]<cur)
			continue;
			else
			{
				seq[ct++] = req[i];
			}
		}
		for(i=0;i<n;i++)
		{
			if(req[i]>cur)
			continue;
			else
			{
				seq[ct++] = req[i];
			}
		}
		
	}
	else
	{
		totseek = (cur) + (size-1-jr);
		
		for(i=n-1;i>=0;i--)
		{
			if(req[i]>cur)
			continue;
			else
			{
				seq[ct++] = req[i];
			}
		}
		for(i=n-1;i>=0;i--)
		{
			if(req[i]<cur)
			continue;
			else
			{
				seq[ct++] = req[i];
			}
		}
		
		
	}
	
	
	//printf("Sequence of movement is: ");
	printf("%d ",cur);
	for(i=0;i<n;i++)
	printf("%d ",seq[i]);
	printf("\n%d\n%f\n",totseek,(float)totseek/n);
	
	
	
}
