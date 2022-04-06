#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct stack{
    int data;
    struct stack *next;
};
struct stack *push(struct stack *,int);
struct stack *pop(struct stack *);
struct stack *Display(struct stack *);
struct stack *top=NULL;
int main(){
    int val,opt;
    
    do{
        printf("\n1_PUSH \n2_POP \n3_DISPLAY\n");
        scanf("%d",&opt);
        
        switch(opt){
            case 1:printf("Enter a Number to PUSH\n");
            scanf("\n%d",&val);
            top=push(top,val);
            break;
            case 2:top=pop(top);
            break;
            case 3:top=Display(top);
            break;
            case 4:printf("THANK YOU");
            exit(0);
            default:printf("Incorrect One Please Choose Above One Option");
            
        }
    }while( opt!=5);
    return 0;
}


struct stack *push(struct stack *top,int val){
    struct stack *ptr;
    ptr=(struct stack *)malloc(sizeof(struct stack));
    ptr->data=val;
    if(top==NULL){
        ptr->next=NULL;
        top=ptr;
    }
    else{
        ptr->next=top;
        top=ptr;
    }
    return top;
}
struct stack *pop(struct stack *top){
    struct stack *ptr;
    ptr=top;
    if(top==NULL){
        printf("STACK IS UNDERFLOW");
    }else{
        top=top->next;
        printf("[%d]",ptr->data);
    }
    return top;
}
struct stack *Display(struct stack *top){
    struct stack *ptr;
    ptr=top;
    int i=0;
    printf("STACK DISPLAY:\n");
    printf("------------");
    if(top=NULL){
        printf("\n the stack is empty");
    }
    else{
        while(ptr!=NULL){
            printf("\n|%d|",ptr->data);
            ptr=ptr->next;
            i++;
        }
        
    }
    printf("\n------------");
    return top;
}
