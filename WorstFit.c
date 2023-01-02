
//Program to implement Worst Fit Memory Management Algorithm

#include<stdio.h>
#include<stdlib.h>

int n = 2;
int m = 2;

int main() {
    
    int wastage=0;
    int count = -1;
    int pos;
    
    system("clear");
    
    printf("\nHow many Processes are there?: ");
    scanf("%d", &n);
    
    printf("\n\nHow many Memory Partitions do you want?: ");
    scanf("%d", &m);
    
    int processes[n], processMemory[n], processAlloc[n], Memory[m], MemoryAlloc[m];
    int notAllocated[n];
    
    for(int i=0;i<n;i++)
    processAlloc[i] = 0;
    
    for(int i=0;i<m;i++)
    MemoryAlloc[i] = -1;
    
    printf("\n\nInput Processes ID and their Memory Requirements");
    
    for(int i=0;i<n;i++) {
        
        printf("\nInput Process ID %d: ", i+1);
        scanf("%d", &processes[i]);
        
        printf("\nInput Process's Memory Requirement: ");
        scanf("%d", &processMemory[i]);
    }
    
    printf("\n\nInput Size of Memory Partitions");
    
    for(int i=0;i<m;i++) {
        
        printf("\nInput Size of Partition %d: ", i+1);
        scanf("%d", &Memory[i]);
    }
    
    for(int i=0;i<n;i++) {
        
        pos = -1;
        
        for(int j=0;j<m;j++) {
            
            if((processMemory[i]<=Memory[j]) && processAlloc[i]==0 && MemoryAlloc[j]==-1) {
                
                if(pos==-1) {
                    
                    pos = j;
                }
                else {
                    
                    if(Memory[pos]<Memory[j])
                    pos = j;
                }
            }
        }
        
        if(pos!=-1) {
            
                MemoryAlloc[pos] = processes[i];
                Memory[pos] = Memory[pos] - processMemory[i];
                processAlloc[i] = 1;
        }
        
    }
    
    for(int i=0;i<m;i++) {
        
        if(MemoryAlloc[i]!=-1)
        wastage+=Memory[i];
    }
    
    for(int i=0;i<n;i++) {
        
        if(!processAlloc[i]) {
            
            count++;
            notAllocated[count] = processes[i];
        }
    }
    
    if(count==-1) {
        
        printf("\n\nAll the processes are successfully allocated in the memory!");
        printf("\nThe total memory wastage is: %d", wastage);
        
        printf("\n\nCurrent Memory State (-1 represent partition is not allocated)\n");
        
        for(int i=0;i<m;i++)
            printf("%d ", MemoryAlloc[i]);
    }
    else {
        
        printf("\nThe following processes are not able to get allocated!\n");
        
        for(int i=0;i<=count;i++) 
            printf("%d ", notAllocated[i]);
            
        printf("\nThe total memory wastage is: %d", wastage);
        
        printf("\n\nCurrent Memory State (-1 represent partition is not allocated)\n");
        
        for(int i=0;i<m;i++)
            printf("%d ", MemoryAlloc[i]);
            
    }
    
    return 0;
}



