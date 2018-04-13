#include<stdio.h>

//struct
struct process
{
	int p,bt,at,wt,tat,ct,pri;
};

int main()
{
// variable Declaration

struct process p1[10],temp;
int i,n,min,k=1,btime=0,j;
float wtavg=0,tatavg=0,tatsum=0,wtsum=0;

printf("\nEnter the No. of processes :");

scanf("%d",&n);
 
for(i=0;i<n;i++)
{
	printf("\tEnter the arrival time of %d process :",i+1);
	scanf(" %d",&p1[i].at);	
	printf("\tEnter the burst time of %d process :",i+1);
	scanf(" %d",&p1[i].bt);
	p1[i].p=i+1;
}
 
/*Sorting According to Arrival Time*/

for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		if(p1[i].at<p1[j].at)
		{
			temp=p1[j];
			p1[j]=p1[i];
			p1[i] = temp;

		}
	}
}


/*Sorting according to Burst time*/
 
for(j=0;j<n;j++)
{
	btime=btime+p1[j].bt;
	min=p1[k].bt;
	for(i=k;i<n;i++)
	{
		if (btime>=p1[i].at && p1[i].bt<min)
		{	
			//printf("\nTrue at %d %d %d %d",i,at[i],bt[i],k);

			temp=p1[k];
			p1[k]=p1[i];
			p1[i] = temp;
		}
	}
k++;
}
p1[-1].ct=p1[0].at;

// calculating ct, tat,wt and priority
for(i=0;i<n;i++)
{
	p1[i].ct=p1[i-1].ct+p1[i].bt;   		// ct
	p1[i].tat=p1[i].ct-p1[i].at;		// tat
	tatsum+=p1[i].tat;			// tat sum
	p1[i].wt=p1[i].tat-p1[i].bt;		// wt
	wtsum+=p1[i].wt;			// wt sum
	p1[i].pri=1+(p1[i].wt/p1[i].bt);		// priority
}

tatavg=(tatsum/n); 	//tat avg
wtavg=(wtsum/n);	// wt avg


// result
printf("\n+----------------------------------------------------------------------+" );
printf("\n|                                                                      |" );
printf("\n| Process Arrival Burst\t Completion Turn-around-time Waiting Priority  | " );

for(i=0;i<n;i++)
	{	
		printf("\n|                                                                      |" );
		printf("\n|   p%d\t     %d\t    %d\t     %d\t\t  %d\t\t%d \t%d      |",p1[i].p,p1[i].at,p1[i].bt,p1[i].ct,p1[i].tat,p1[i].wt,p1[i].pri);
	}
printf("\n|                                                                      |" );
printf("\n+----------------------------------------------------------------------+" );

printf("\n+-----------------------------------------------------------------------+" );
printf("\n|                                                                       |" );
printf("\n|\t\tAverage Waiting Time : %f\t\t\t\t|",wtavg);
printf("\n|\t\tAverage Turn Around Time : %f\t\t\t|",tatavg);
printf("\n|                                                                       |" );
printf("\n+-----------------------------------------------------------------------+" );


return 0;
}
