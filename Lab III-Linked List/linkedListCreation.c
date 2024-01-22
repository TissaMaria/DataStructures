#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};
void countNode(struct node *head){
    int count=0;
    if(head==NULL){
        printf("Empty List");
    }else{
        struct node *ptr;
        ptr=head;
        while(ptr!=NULL){
            count++;
            ptr=ptr->link;
        }
        printf("%d", count);
    }
}
void printData(struct node* head){
    if(head==NULL){
        printf("Empty list");
    }else{
        struct node *ptr;
        ptr=head;
        while(ptr!=NULL){
            printf("%d\n",ptr->data);
            ptr=ptr->link;
        }
    }
}
void insertAtEnd(struct node *head,int value){
    struct node *temp, *ptr;
    temp=(struct node* )malloc(sizeof(struct node));
    temp->data=value;
    temp->link=NULL;
    ptr=head;
    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=temp;
    printf("%d inserted at the end successfully\n",value);
}
void insertBeg(struct node **head, int value){
    struct node *temp;
    temp=(struct node* )malloc(sizeof(struct node));
    temp->data=value;
    temp->link = *head;
    *head = temp;
    printf("%d inserted at the beginning successfully\n",value);
}
void addToPos(struct node *head,int value, int pos){
    struct node *ptr, *ptr2;
    ptr=head;
    ptr2=(struct node* )malloc(sizeof(struct node));
    ptr2->data=value;
    ptr2->link=NULL;
    pos--;
    while(pos!=1){
        ptr=ptr->link;
        pos--;
    }
    ptr2->link=ptr->link;
    ptr->link=ptr2;
    printf("%d inserted successfully\n",value);
}

void delBeg(struct node **head){
     if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct node *temp;
    temp=*head;
    *head=(*head)->link;
    printf("%d deleted\n", temp->data);
    free(temp);
}
void delEnd(struct node *head){
    if(head==NULL){
        printf("The list is empty");
    }else if(head->link==NULL){
        free(head);
        head=NULL;
    }else{
        struct node *temp, *prev;
        temp=head;
        while(temp->link!=NULL){
            prev=temp;
            temp=temp->link;
        }
        printf("%d Deleted successfully\n",temp->data);
        free(temp);
        temp=NULL;
        prev->link=NULL;


    }
}
void delAtPos(struct node **head, int pos){
    struct node *current=*head;
    struct node *previous=*head;
    if(*head==NULL){
        printf("The link is empty");
    }else if(pos==1){
        *head=current->link;
        free(current);
        current=NULL;
    }else{
        while(pos!=1){
            previous=current;
            current=current->link;
            pos--;
        }
        previous->link=current->link;
        free(current);
        current=NULL;
    }
}

int main(){
    struct node *head;
    head=NULL;
    insertBeg(&head,34);
    printData(head);
    printf("---------------\n");
    insertAtEnd(head,75);
    insertAtEnd(head,56);
    insertAtEnd(head,87);
    printData(head);
    printf("---------------\n");
    addToPos(head,89,3);
    printData(head);
    printf("---------------\n");
    delBeg(&head);
    printData(head);
    printf("---------------\n");
    delEnd(head);
    printData(head);
    printf("---------------\n");
    delAtPos(&head,2);
    printData(head);
    printf("---------------\n");
  return 0;}
