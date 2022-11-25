#include<stdio.h>
int main()
{
int i,j,n,bt[20],wt[20],tat[20],temp;
float avgtat,avgwt;
printf("enter the no of process:");
	scanf("%d",&n);
printf("enter the burst time of the process\n");
	{
		for(i=0;i<n;i++ )
		scanf("%d",&bt[i]);
	}
	
	//modification for sjf
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(bt[i]>bt[j])
			{
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
			}
		}
	}
	
	//modification for sjf
	
	wt[0]=0;
	for(i=0;i<n;i++)
		{
			wt[i]=0;
			for(j=0;j<i;j++)
			{
			wt[i]=wt[i]+bt[j];
			}
		}
printf("process\t\tburst\t\twaiting\t\tturn around time\t\t\n");
	for(i=0;i<n;i++)
		{
			tat[i]=bt[i]+wt[i];
			avgtat+=tat[i];
			avgwt+=wt[i];
			printf("P[%d]\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
		}	
		printf("Average waiting time =%f\n",avgwt/n);
		printf("Average turn around time =%f\n",avgtat/n);

}

