#include<stdio.h>
#define Length 10

void initalize();
int avgtime(int arr[], int n, int busarr[]);
int wait_time(int arr[], int n, int busarr[], int waittime[]);
int turn_around(int arr[], int n, int busarr[], int waittime[], int tunardt[]);

int main()
{
    
    initalize();
    
    return 0;
}
void initalize(){
    
    int n, arr[Length];
    printf("\n Enter the number of Process : ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++){
        arr[i] = i+1;    
    }
    
    int busarr[n];
    printf("\n Enter the %d process's Burst Time : ", n);
    
    for(int i = 0;i < n; i++)
    {
        scanf("%d", &busarr[i]);
    }
    
    avgtime(arr, n, busarr);   
}

int avgtime(int arr[], int n, int busarr[])
{
  
    int waittime[n], tunardt[n], total_wt = 0, total_tunard = 0;
  
    wait_time(arr, n, busarr, waittime);
    
    turn_around(arr, n, busarr, waittime, tunardt);
    
    printf("Processes  Burst   Waiting Turn around \n");
    
    for(int i = 0; i < n; i++)
    {
        
        total_wt = total_wt + waittime[i];
        total_tunard = total_tunard + tunardt[i];
        printf("%d\t %d\t\t %d \t%d\n", i+1, busarr[i], waittime[i], tunardt[i]);
        
        
    }
    
    printf("Average waiting time = %.2f\n", (float)total_wt / (float)n);
    
    printf("Average turn around time = %.2f\n", (float)total_tunard / (float)n);
    
    return 0;
    
}


int wait_time(int arr[], int n, int busarr[], int waittime[])
{
    waittime[0] = 0;
    
    for (int  i = 1; i < n; i++)
    {
        
        waittime[i] = busarr[i-1] + waittime[i-1];
    }
    
    return 0;       
}
int turn_around(int arr[], int n, int busarr[], int waittime[], int tunardt[])
{   
    for (int i = 0; i < n ; i++)
    {
        
        tunardt[i] = busarr[i] + waittime[i];
    }
    return 0;    
}
