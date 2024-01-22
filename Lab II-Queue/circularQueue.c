#include <stdio.h>
#define MAX 5
int front=-1, rear=-1, q[MAX];
void enqueue(int value){
    if(front==-1 && rear ==-1){
        front=0;
        rear=0;
        q[rear]=value;
    }else if((rear+1)%MAX==front){
        printf("Overflow");}
    else{
        rear=(rear+1)%MAX;
        q[rear]=value;
    }
    }
void dequeue(){
if(front==-1){
    printf("Underflow");

}else{
    if(front==rear){
        front=-1;
        rear=-1;
    }else{
    printf("%d deleted",q[front]);
    front=(front+1)%MAX;}
    }
    }
void display(){
if(front==-1){
    printf("Underflow");
}else{
    int i=front;
while(i!=rear){
    printf("%d",q[i]);
    i=(i+1)%MAX;
}

}}

int main(){
    int boolean=1,choice,value;
    while(boolean){
        printf("\n1.Enqueue\n2.Dequeue\n3.DISPLAY\n4.EXIT\n");
        scanf("%d",&choice);
        switch(choice){
        case 1:{printf("Enter a value");
            scanf("%d",&value);
                enqueue(value);
                break;}
        case 2:dequeue();
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
