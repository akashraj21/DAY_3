#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 10

long int PostFix_eva();

void push(long int ch);

int top;
int pop();
int isEmpty();

long int Stack[N];

char PostFix_exp[N];

int main()
{
    int Ev_Value;
    printf("Enter a Expression Value\n");
    scanf("%[^\n]s",PostFix_exp);
    printf("%s",PostFix_exp);
    Ev_Value=PostFix_eva();
    printf("\nEvaluation of Postfix Expression:\n%d\n", Ev_Value);
    return 0;
}
long int PostFix_eva()
{
    long int x,y,temp,value;
    for(int i=0;i<strlen(PostFix_exp);i++){
        if(PostFix_exp[i]<='9' &&PostFix_exp[i] >='0'){
            push(PostFix_exp[i]-'0');
        }
        else{
            x=pop();
            y=pop();
        switch(PostFix_exp[i]){
            case '+':temp=y+x;
            break;
            case '-':temp=y-x;
            break;
            case '*':temp=y*x;
            break;
            case '/':temp=y/x;
            break;
            case '%':temp=y%x;
            break;
            case '^':temp=pow(y,x);
            break;
            default:printf("Invalid");
        }
        push(temp);
    }
}
value=pop();
return value;
}
int isEmpty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(long int ch){
    if(top>10){
        printf("Stack OverFlow");
        exit(1);
    }
    top=top+1;
    Stack[top]=ch;
}


int pop(){
    if(isEmpty()){
        printf("Stack is Empty");
        exit(1);
    }
    return(Stack[top--]);
}
