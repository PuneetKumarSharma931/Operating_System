
//Program to implement Banker's Algorithm

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int n = 2;
int m = 2;

void displayMatrix(int arr[n][m]) {
    
    for(int i=0;i<n;i++) {
        
        for(int j=0;j<m;j++) {
            
            printf("%d ", arr[i][j]);
        }
        
        printf("\n");
    }
}

bool canExecute(int need[n][m], int available[n+1][m], int i, int availableCount) {
    
    bool isExecutable = true;
    
    for(int j = 0;j<m;j++) {
        
        if(need[i][j]>available[availableCount][j])
        isExecutable = false;
    }
    
    return isExecutable;
}

bool isAllDone(int Finish[n]) {
    
    bool isDone = true;
    
    for(int i=0;i<n;i++) {
        
        if(Finish[i] == 0)
        isDone = false;
    }
    
    return isDone;
}

void safeSequence(int alloc[n][m], int max[n][m], int available[n+1][m], int need[n][m]) {
    
    int Finish[n];
    int i= 0;
    int availableCount = 0;
    int change = 0;
    
    for(int i=0;i<n;i++) {
        
        Finish[i] = 0;
    }
    
    while(!isAllDone(Finish)) {
        
        if(Finish[i] == 0) {
            
            if(canExecute(need, available, i, availableCount)) {
                
                Finish[i] = 1;
                change++;
                
                for(int j=0;j<m;j++) 
                available[availableCount+1][j] = available[availableCount][j] + alloc[i][j];
                
                availableCount++;
                
                printf("%d ", i+1);
            }
            
        }
        
        i++;
        
        if(i>=n) {
            
            i=0;
            if(change==0) {
                
                printf("\n\nThe System is not in a safe state: Hence, Safe Sequence is not Obtainable!");
                return;
            }
            else {
                
                change = 0;
            }
            
        }
    }
}

int main() {
    
    system("clear");

    printf("\nPlease Input The Number of Processes: ");
    scanf("%d",&n);
    printf("\nPlease Input the Number of Resources: ");
    scanf("%d",&m);
    
    int alloc[n][m];
    int max[n][m];
    int available[n+1][m];
    int need[n][m];
    
    printf("\n\nPlease Input the Allocation Matrix\n\n");
    
    for(int i=0;i<n;i++) {
        
        printf("\nInput Resources Allocated for Process %d: ", i+1);
        
        for(int j=0;j<m;j++) {
            
            scanf("%d",&alloc[i][j]);
        }
    }
    
    printf("\n\nPlease Input the Max Matrix\n\n");
    
    for(int i=0;i<n;i++) {
        
        printf("\nInput Max Resources Required for Process %d: ", i+1);
        
        for(int j=0;j<m;j++) {
            
            scanf("%d",&max[i][j]);
        }
    }
    
    printf("\n\nPlease Input Available Resources: ");
    
    for(int i=0;i<m;i++) {
        
        scanf("%d",&available[0][i]);
    }
    
    for(int i=1;i<n;i++) {
        
        for(int j=0;j<m;j++)
        available[i][j] = 0;
    }
    
    for(int i=0;i<n;i++) {
        
        for(int j=0;j<m;j++) {
            
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    
    printf("\nAllocation Matrix is\n");
    displayMatrix(alloc);
    
    printf("\n\nMax Matrix is\n");
    displayMatrix(max);
    
    printf("\n\nAvailable Resources are\n");
    
    for(int j=0;j<m;j++) {
        
        printf("%d ", available[0][j]);
    }
    
    printf("\n\nNeed Matrix is\n");
    displayMatrix(need);
    
    printf("\n\nSafe Sequence is\n\n");
    
    safeSequence(alloc, max, available, need);
    
    return 0;
}



