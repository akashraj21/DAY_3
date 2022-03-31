#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 10
long int PostFix_eva();
void push(long int ch);//Push Operation 
int top;//check top
int pop();//pop operation
int isEmpty();/check Is Empty or not
long int Stack[N];
char PostFix_exp[N];


//Calling Main Function....
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
int isEmpty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
///Make an empty stack implemented as an array.
//Get an input postfix expression from the user.
//Scan the expression from left to right.
//During your scanning:
///If you encounter an operand, push it onto the stack and continue scanning.
///If you encounter an operator, pop only the topmost two elements from the stack, apply the operator on the elements and push the result back to the stack.
//When you reach the end of the string, there should be only one element on to the stack. Pop this value to get the result of your postfix expression.//
