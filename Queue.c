#include<stdio.h>
#include<conio.h>
#define Length 20


void initalize();
void enqueue();
void dequeue();
void display();

void (*ptr)();

struct queue{
    
    int arr[Length];
    
}q;

int rear = -1, front = -1;

int main()
{
    
    ptr = initalize;
    ptr();    
    return 0;
}

void initalize()
{
    
    int ch;
    
    do {
        printf("\n  *****Queue*****");
        
        printf("\n 1. Enqueue Operation");
        printf("\n 2. Dequeue Operation");
        printf("\n 3. Display");
        printf("\n 4. Exit");
        printf("\n Enter your choice : ");
        scanf("%d", &ch);
        
        switch(ch){
            
            case 1 : ptr = enqueue;
                ptr();
                break;
            case 2 : ptr = dequeue;
                ptr();
                break;
            case 3 : ptr = display;
                ptr();
                break;
            case 4 : printf("Thank You");
                break;
            default : printf("Invalid Option : ");
                break;
        }
    }while(ch != 4);
    
}

void enqueue()
{
    
    int value;
    
    if (rear == Length-1)
    {
        printf("Queue Overflow");
    }
    else {
        
        if (front == -1){
            front = 0;
        }
        
        printf("\n Enter the number to be inserted : ");
        scanf("%d", &value);
        
        rear++;
        q.arr[rear] = value;
    }
}

void dequeue()
{
    
    if (front == -1)
    {
        printf("\n Queue Underflow");
    }
    else{
        
        printf("\n Element deleted from the queue is %d ", q.arr[front]);
        front++;
    }
}

void display()
{
    
    if (front == -1){
        printf("\n Queue is Empty");
    }
    else
    {
        
        printf("\n Queue : \n");
        for(int i = front; i <= rear; i++){
            printf("-| %d |", q.arr[i]);
        }
    }
    
}
