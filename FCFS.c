
#include<stdio.h>
#include<stdlib.h>

void sort(int processId[], int arrival[], int burstTime[], int n) {
    
    int temp;
    
    for(int i=0;i<n;i++) {
        
        for(int j=0;j<n-i-1;j++) {
            
            if(arrival[j] > arrival[j+1]) {
                
                temp = arrival[j];
                arrival[j] = arrival[j+1];
                arrival[j+1] = temp;
                
                temp = processId[j];
                processId[j] = processId[j+1];
                processId[j+1] = temp;
                
                temp = burstTime[j];
                burstTime[j] = burstTime[j+1];
                burstTime[j+1] = temp;
            }
        }
    }
}

void waiting(int wait[], int arrival[], int burstTime[], int n) {
    
    int burst = 0;
    
    for(int i=0;i<n;i++) {
        
        if(i==0) {
            
            wait[i] = 0;
            burst = burst+burstTime[i];
        }
        else {
            
       wait[i] = burst - arrival[i];
       burst = burst+burstTime[i];
    }
    }
}

void turnAround(int tat[], int arrival[], int burstTime[], int n) {
    
    int burst = 0;
    
    for(int i=0;i<n;i++) {
        
        burst = burst + burstTime[i];
        
        tat[i] = burst - arrival[i];
    }
}

int main() {
    
    int n;
    
    printf("\nInput the Number of Processes: ");
    scanf("%d", &n);
    
    int burstTime[n];
    int arrival[n];
    int processId[n];
    int wait[n];
    int tat[n];
    float averageWait;
    float averageTAT;
    float totalTAT = 0;
    float totalWait = 0;
    
    printf("\nInput the Process Id,Burst Time and Arrival Time of processes\n\n");
    
    for(int i=0;i<n;i++) {
        
        printf("\nInput Process Id for Process %d: ", i+1);
        scanf("%d",&processId[i]);
        
        printf("\nInput Burst Time for Process %d: ", i+1);
        scanf("%d",&burstTime[i]);
        
        printf("\nInput Arrival Time for Process %d: ", i+1);
        
        scanf("%d",&arrival[i]);
        
    }
    
    printf("\n\n");
    
    printf("\nCurrent Processes");
    
    printf("\n\nPID    Arrival Time    Burst Time");
    
    for(int i=0;i<n;i++) {
        
        printf("\n%d            %d              %d", processId[i], arrival[i], burstTime[i]);
    }
    
    sort(processId, arrival, burstTime, n);
    
    waiting(wait, arrival, burstTime, n);
    
    turnAround(tat, arrival, burstTime, n);
    
    for(int i=0;i<n;i++) {
        
    totalWait = totalWait + wait[i];
    totalTAT = totalTAT + tat[i];
    
    }
    
    averageWait = totalWait/n;
    averageTAT = totalTAT/n;
    
    printf("\n\nPID    Arrival Time    Burst Time     Waiting Time     Turn Around Time");
    
    for(int i=0;i<n;i++) {
        
        printf("\n%d            %d              %d               %d              %d", processId[i], arrival[i], burstTime[i], wait[i], tat[i]);
    }
    
    printf("\n\nAverage Waiting Time is: %f", averageWait);
    printf("\n\nAverage TurnAround Time is: %f", averageTAT);
    
    return 0;
    
}
