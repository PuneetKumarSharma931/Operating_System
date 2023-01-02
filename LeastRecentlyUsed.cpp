
//Program to implement Least Recently Used Page Replacement Policy

#include<iostream>
#include<stack>

using namespace std;

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
    int flag, recent;
    stack<int> st1, st2;
    
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
        
        for(int j=0;j<m;j++) {
            
            if(frames[j]==-1) {
                
                frames[j] = pages[i];
                misses++;
                printf("\n");
                displayArray(frames, m);
                flag = 1;
                st1.push(j);
                break;
            }
            else {
                
                if(frames[j]==pages[i]) {
                    
                    hits++;
                    printf("\n");
                    displayArray(frames, m);
                    flag = 1;
                    
                    while(!st1.empty()) {
                        
                        if(frames[st1.top()]==frames[j]) {
                            
                            recent = st1.top();
                            st1.pop();
                        }
                        else {
                            
                            st2.push(st1.top());
                            st1.pop();
                        }
                        
                    }
                    
                    while(!st2.empty()) {
                        
                        st1.push(st2.top());
                        st2.pop();
                    }
                    
                    st1.push(recent);
                    
                    break;
                }
            }
        }
        
        if(!flag) {
            
                
                while(!st1.empty()) {
                    
                    st2.push(st1.top());
                    st1.pop();
                }
                
                frames[st2.top()] = pages[i];
                recent = st2.top();
                st2.pop();
                
                while(!st2.empty()) {
                    
                    st1.push(st2.top());
                    st2.pop();
                }
                
                st1.push(recent);
                misses++;
                printf("\n");
                displayArray(frames, m);
                }
                
            }
    
    printf("\n\nTotal Page Hits: %d", hits);
    printf("\nTotal Page Faults: %d", misses);
    
    return 0;
}


