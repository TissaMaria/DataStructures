#include <stdio.h>
#include<stdlib.h>
//for queue
struct node{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int x){
    struct node *newNode;
    newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=x;
    newNode->next=NULL;
    if(front==NULL&&rear==NULL){
        front=rear=newNode;
    }else{
        rear->next=newNode;
        rear=newNode;
    }
}
int dequeue(){
    if(front!=NULL){
    struct node *ptr;
    ptr=front;
    front=front->next;
    free(ptr);
    ptr=NULL;}
}
int isEmpty(){
    return front==NULL;
}
void BFS(int G[][7],int start,int n){
    int i=start;
   
    int visited[7]={0};
    printf("%d ",i);
    visited[i]=1;
    enqueue(i);
    while(!isEmpty()){
        i=dequeue();
        for(int j=1;j<n;j++){
            if(G[i][j]=1&&visited[j]==0){
                enqueue(j);
                visited[j]=1;
                printf("%d ",j);
            }
        }
    }
}
int main(){
    int G[7][7]={{0,0,0,0,0,0,0},
    {0,0,1,1,0,0,0},
    {0,1,0,0,1,0,0},
    {0,1,0,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}

    };
    printf("BFS\n");
    BFS(G,4,7);
    
    
    return 0;
}
