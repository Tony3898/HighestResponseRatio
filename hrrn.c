#include<stdio.h>
#include<stdlib.h> 
#include<unistd.h>
// Defining process details
struct process 
{
    int p,at, bt, ct, wt, tat,rt,comp;
} p1[100],temp1;

int main()
{
	int i, j, t, sumbt = 0,n,loc;
    	float avgwt = 0, avgtat = 0,temp,hrrn=-99;
	char t1='%';
	p1[-1].ct=0;
	printf("\nEnter the No. of processes :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\tEnter the arrival time of %d process :",i+1);
		scanf(" %d",&p1[i].at);	
		printf("\tEnter the burst time of %d process :",i+1);
		scanf(" %d",&p1[i].bt);
		p1[i].p=i;
		p1[i].comp = 0; 
		sumbt += p1[i].bt;
	}
	system("clear");
  
	for(i=0;i<=100;i++) 
	{
        printf("Loading: %d%c",i,t1);
        printf("\r");
        fflush(stdout);
        usleep(59000);
        }
	system("clear");
	// sorting according to Arrival Time
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p1[i].at>p1[j].at)
			{
				temp1=p1[i];
				p1[i]=p1[j];
				p1[j] = temp1;

			}
		}
		
	}

	for (t = p1[0].at; t < sumbt;)
	{	hrrn=-9999;
        	for (i = 0; i < n; i++) 
		{
            		if (p1[i].at <= t && p1[i].comp != 1) 
			{
				temp = (p1[i].bt + (t - p1[i].at)) / p1[i].bt;
	                	if (hrrn < temp) 
				{ 
	                    		hrrn = temp;
	                    		loc = i;
					p1[loc].rt=hrrn;
				}
            		}
        	}
		//printf("\n%d %d\n",loc,t);
	        t += p1[loc].bt;
		p1[loc].ct=t;
		p1[loc].tat = p1[loc].ct - p1[loc].at;
                p1[loc].wt = p1[loc].tat - p1[loc].bt;
		avgwt+=p1[loc].wt;
	        avgtat += p1[loc].tat;
		p1[loc].comp = 1;
	}

// sorting according to complettion time Time
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p1[i].ct>p1[j].ct)
			{
				temp1=p1[i];
				p1[i]=p1[j];
				p1[j] = temp1;

			}
		}
		
	}
// result
printf("\n+--------------------------------------------------------------------------------------+" );
printf("\n|                                                                                      |" );
printf("\n| Process Arrival Burst\t Completion Turn-around-time Waiting  Highest Response Ratio   | " );

for(i=0;i<n;i++)
	{	
		printf("\n|                                                                                      |" );
		printf("\n|   p%d\t     %d\t    %d\t     %d\t\t  %d\t\t%d \t\t%d              |",p1[i].p,p1[i].at,p1[i].bt,p1[i].ct,p1[i].tat,p1[i].wt,p1[i].rt);
	}
printf("\n|                                                                                      |" );
printf("\n+--------------------------------------------------------------------------------------+" );

printf("\n+-----------------------------------------------------------------------+" );
printf("\n|                                                                       |" );
printf("\n|\t\tAverage Waiting Time : %f\t\t\t\t|",avgwt/n);
printf("\n|\t\tAverage Turn Around Time : %f\t\t\t|",avgtat/n);
printf("\n|                                                                       |" );
printf("\n+-----------------------------------------------------------------------+" );
printf("\n");
return 0;
}
