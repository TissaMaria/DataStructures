#include <stdio.h>
#include <stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node* DInsertAtBeg(struct node *head, int value){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->next=NULL;
    temp->data=value;
    if(head==NULL){
        head=temp;
       
    }else{
        temp->next=head;
        head->prev=temp;
        head=temp;
        
    }
    printf("Successfully Added %d at the beginning\n",value);
    return head;
}
struct node* DInsertAtEnd(struct node *head, int value){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->next=NULL;
    temp->data=value;
    if(head==NULL){
        head=temp;
        
    }else{
        struct node *ptr;
        ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->prev=ptr;
        

    }
    printf("Successfully Added %d at the end\n",value);
    return head;
}
struct node* DInsertAfter(struct node* head, int pos, int value){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->next=NULL;
    temp->data=value;
    int position = pos;
    struct node *ptr1, *ptr2;
    pos--;
    ptr1=head;
 
    while(pos!=0){
        ptr1=ptr1->next;
        pos--;
    }
    ptr2=ptr1->next;
    temp->prev=ptr1;
    temp->next=ptr2;
    ptr1->next=temp;
    ptr2->prev=temp;
    printf("Successfully Added %d after position %d\n",value,position);
    return head;
    
}
struct node* DInsertBefore(struct node* head, int pos, int value){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->next=NULL;
    temp->data=value;
    int position=pos;
    struct node *ptr1, *ptr2;
    pos--;
    ptr1=head;
 
    while(pos!=1){
        ptr1=ptr1->next;
        pos--;
    }
    ptr2=ptr1->next;
    temp->prev=ptr1;
    temp->next=ptr2;
    ptr1->next=temp;
    ptr2->prev=temp;
    printf("Successfully Added %d before position %d\n",value,position);
    return head;
    
}
void delAtBeg(struct node **head){
    if(*head==NULL){
        printf("The List is Empty.\n");
    }else{
        struct node *ptr=*head;
        *head=(*head)->next;
       (*head)->prev = NULL;
        free(ptr);
        ptr=NULL;
        printf("Value deleted at the beginning\n");
    }
}
void delAtEnd(struct node *head){
    if(head==NULL){
        printf("The List is Empty.\n");
    }else{
        struct node *ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->prev->next=NULL;
        free(ptr);
        ptr=NULL;
        printf("Value deleted at the end\n");
    }
}
void delVal(struct node *head, int val){
    if(head==NULL){
        printf("Empty list");
    }else{
        struct node *ptr1,*ptr2;
        ptr1=head;
        while(ptr1->data!=val){
            ptr1=ptr1->next;
        }
        if(ptr1!=NULL){
        ptr2=ptr1->next;
        ptr2->prev=ptr1->prev;
        ptr1->prev->next=ptr2;
        free(ptr1);
        ptr1=NULL;
        printf("%d deleted\n",val);}
        else{
            printf("Not Found\n");
        }
    }
}
void printData(struct node* head){
    if(head==NULL){
        printf("Empty list\n");
    }else{
        struct node *ptr;
        ptr=head;
        while(ptr!=NULL){
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
        printf("----------------\n");
    }
}
int main(){
    struct node *head;
    head=NULL;
    printData(head);
    head=DInsertAtBeg(head,30);
    head=DInsertAtBeg(head,45);
    head=DInsertAtEnd(head,56);
    printData(head);
    head=DInsertAfter(head,2,23);
    printData(head);
    head=DInsertBefore(head,2,11);
    printData(head);
    delAtBeg(&head);
    printData(head);
    delAtEnd(head);
    printData(head);
    delVal(head,30);
    printData(head);
    return 0;
}