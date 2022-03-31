#include<stdio.h>
#define Length 20
void initialize();
void push(char c);
char pop();

void (*iptr)();
void (*pptr)(char);
char (*poptr)();

char stk[Length];
int top = -1;


int main()
{
    iptr = initialize;
    iptr();
    return 0;
}

void initialize()
{
    
    char exp[Length];
    
    printf("Enter the parentheses Expression : ");
    scanf("%s", exp);
    
    char temp;
    int flag = 1;
    
    pptr = push;
    poptr = pop;
    
    for(int i = 0; exp[i] != '\0'; i++){
        
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            pptr(exp[i]);
        }
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (top == -1)
            {
                flag = 0;
            }
            else
            {
                temp = poptr();
            
                if (exp[i] == ')' && (temp == '}' || temp == ']')){
                    flag = 0;
                }
                if (exp[i] == '}' && (temp == ')' || temp == ']')){
                    flag = 0;
                }
                if (exp[i] == ']' && (temp == ')' || temp == '}')){
                    flag = 0;
                }
                
            }
                
        }
    }
    
    if (top >= 0){
        flag = 0;
    }
    if (flag == 1){
        printf("\n The Expression is balanced");
    }
    else{
        printf("\n The expression is unbalanced");
    }

    
}

void push(char c)
{
    if (top == Length - 1)
    {
        printf("Stack Overflow");
    }
    else
    {
        top++;
        stk[top] = c;
    }
    
}

char pop()
{
    char c;
    
    if (top == -1)
    {
        printf("Stack Underflow");
    }
    else
    {
        c = stk[top];
        top--;
        return c;
    }
}
