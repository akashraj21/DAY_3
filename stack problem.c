#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


struct node{
    int data;
    struct node *next;
};

struct node *top=NULL;

struct node *push(struct node *,int);
struct node *pop(struct node *);
struct node *display(struct node *);
int main(int argc, char* argv[]){
    int val,opt;
    do{
        printf("...Choose One Operation...");
        printf("\n1_PUSH \n2_POP \n3_PEEK \n4_DISPLAY");
        scanf("%d",&opt);
        
        switch(opt){
            case 1:printf("Enter a Number to PUSH the Element in Stack...");
            scanf("%d",&val);
            top=push(top,val);
            break;
            case 2:top=pop(top);
            break;
            case 3:top=display(top);
            break;
        }
        
    }while(opt!=5);
    return 0;
}
struct node *push(struct node *top,int val){
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
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
struct node *pop(struct node *top){
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr=top;
    if(top==NULL){
        printf("\n...STACK IS UNDER FLOW..\n");
    }
    else{
        top=top->next;
        printf("\n%d POP ELEMENT\n",ptr->data);
        free(ptr);
    }
    return top;
}
struct node *display(struct node *top){
    struct node *ptr;
    ptr=top;
    if(top==NULL){
        printf("\n...lIST IS EMPTY...\n");
    }
    else{
        while(ptr!=NULL){
            printf(" %d->",ptr->data);
            ptr=ptr->next;
        }
    }
    return top;
}
