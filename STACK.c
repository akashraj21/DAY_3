#include<stdio.h>
#include<conio.h>
#define N 10

void initialize();
void push();
void display();
void pop();
void peep();
void (*ptr)();

int Array_Val[N], Top = -1;

int main()
{
    ptr = initialize;
    ptr();
    
    return 0;
}

void initialize()
{
    int ch;
    
    do 
    {
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEP");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n *******************");
        printf("\n\n Enter the Option : ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                ptr = push;
                ptr();
                break;
            case 2:
                ptr = pop;
                ptr();
                break;
            case 3:
                ptr = peep;
                ptr();
                break;
            case 4:
                ptr = display;
                ptr();
                break;
            default :
                printf("\n Invalid Choose Correct One");
            
        }
    }while(ch != 5);    
}
void display()
{
    if (Top == -1)
    {
        printf("\n The Stack is Empty");
    }
    else
    {
        for(int i = Top; i >= 0; i--)
        {
            printf("\n|%d|", Array_Val[i]);
            printf("\n -- ");
        }
    }
    
}
void push()
{
    int Val;
    
    printf("\n Enter the Number to be Pushed : ");
    scanf("%d", &Val);
    
    if (Top == N-1)
    {
        printf("\n STACK OVERFLOW");
    }
    else
    {
        Top++;
        Array_Val[Top]=Val;
        printf(" %d is Pushed into Stack", Val);
    }
    
}

void pop()
{
    int Val;
    
    if (Top == -1)
    {
        printf("\n STACK UNDERFLOW");
    }
    else
    {
        Val = Array_Val[Top];
        Top--;
        printf("\n The value poped : %d", Val);
    }
}

void peep()
{
    
    if (Top == -1)
    {
        printf("\n Stack is Empty");
    }
    else
    {
        printf("\n The element at the top : %d", Array_Val[Top]);
    }
}
