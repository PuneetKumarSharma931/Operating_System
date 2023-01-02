
//Program to implement Optimal Page Replacement Policy

#include<stdio.h>
#include<stdlib.h>

int n = 1;
int m = 1;

void displayArray(int arr[], int size) {
    
    for(int i=0;i<size;i++) {
        
        if(arr[i]==-1)
            return;
            
        printf("%d ", arr[i]);
    }
}

int main() {
    
    int hits = 0, misses = 0;
    int flag, rflag;
    int maxPos, currPos, pageReplaceIndex;
    
    system("clear");
    
    printf("\nHow many pages are there in the reference string?: ");
    scanf("%d", &n);
    
    printf("\nHow many frames do you want in the main memory?: ");
    scanf("%d", &m);
    
    int pages[n], frames[m];
    
    printf("\n\nPlease input the reference string: ");
    
    for(int i=0;i<n;i++) 
        scanf("%d", &pages[i]);
        
    for(int i=0;i<m;i++)
        frames[i] = -1;
        
    for(int i=0;i<n;i++) {
        
        flag = 0;
        maxPos = -1;
        
        for(int j=0;j<m;j++) {
            
            if(frames[j]==-1) {
                
                frames[j] = pages[i];
                misses++;
                printf("\n");
                displayArray(frames, m);
                flag = 1;
                break;
            }
            else {
                
                if(frames[j]==pages[i]) {
                    
                    hits++;
                    printf("\n");
                    displayArray(frames, m);
                    flag = 1;
                    break;
                }
            }
        }
        
        if(!flag) {
            
            for(int k=0;k<m;k++) {
                
                rflag = 0;
                
                for(int l=i;l<n;l++) {
                    
                    if(frames[k]==pages[l]) {
                        
                        currPos = l;
                        
                        if(maxPos<currPos) {
                            
                            maxPos = currPos;
                            pageReplaceIndex = k;
                        }
                        
                        rflag = 1;
                    }
                }
                
                if(!rflag) {
                    
                    pageReplaceIndex = k;
                    break;
                
                }
            }
            
            frames[pageReplaceIndex] = pages[i];
            misses++;
            printf("\n");
            displayArray(frames, m);
        }
    }
    
    printf("\n\nTotal Page Hits: %d", hits);
    printf("\nTotal Page Faults: %d", misses);
    
    return 0;
}
