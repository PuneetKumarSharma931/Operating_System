
//Program to implement SSTF Disk Scheduling Algorithm

#include<stdio.h>
#include<stdlib.h>

int main()
{
    system("clear");

    int RQ[100],i,n,TotalHeadMoment=0,initial,count=0;
    int min=10000,d,index;

    printf("\nEnter the number of Requests: ");
    scanf("%d",&n);

    printf("\n\nEnter the Requests sequence: ");
    for(i=0;i<n;i++)
     scanf("%d",&RQ[i]);

    printf("\n\nEnter initial head position: ");
    scanf("%d",&initial);
    
    while(count!=n)
    {
        min = 10000;

        for(i=0;i<n;i++)
        {
           d=abs(RQ[i]-initial);
           if(min>d)
           {
               min=d;
               index=i;
           }
           
        }

        TotalHeadMoment=TotalHeadMoment+min;
        initial=RQ[index];

        RQ[index]=10000;
        count++;
    }
    
    printf("\n\nTotal head movement is: %d Cylinders",TotalHeadMoment);
    return 0;
}