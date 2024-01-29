#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
}*top=NULL;
void push(int value){
    struct node *newNode;
    newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=value;
    newNode->next=top;
    top=newNode;
    printf("Successfully Added %d",value);
}
void pop(){
    if(top==NULL){
        printf("The stack is empty");
    }else{
        struct node *temp;
    temp=top;
    top=top->next;
    printf("%d deleted\n", temp->data);
    free(temp);
    }
}
void display(){
    struct node *ptr;
    ptr=top;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

int main(){
    int boolean=1,choice,value;
    while(boolean){
        printf("\n1.PUSH\t2.PULL\t3.DISPLAY\t4.EXIT\n");
        scanf("%d",&choice);
        switch(choice){
        case 1:{printf("Enter a value");
            scanf("%d",&value);
                push(value);
                break;}
        case 2:pop();
        break;
        case 3:display();
        break;
        case 4:boolean=0;
        break;
        default:printf("Invalid Input");
        }
    }
    return 0;
    }