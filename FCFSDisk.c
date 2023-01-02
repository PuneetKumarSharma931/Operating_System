
//Program to implement FCFS Disk Scheduling Algorithm

#include<stdio.h>
#include<stdlib.h>

int main()
{

    system("clear");

    int RQ[100],i,n,TotalHeadMoment=0,initial;

    printf("\nEnter the number of Requests: ");
    scanf("%d",&n);

    printf("\n\nEnter the Requests sequence: ");

    for(i=0;i<n;i++)
     scanf("%d",&RQ[i]);

    printf("\n\nEnter initial head position: ");
    scanf("%d",&initial);
    
    for(i=0;i<n;i++)
    {
        TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
        initial=RQ[i];
    }
    
    printf("\n\nTotal head moment is %d Cylinders",TotalHeadMoment);
    return 0;
}