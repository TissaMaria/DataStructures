#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node* reverse(struct node *head){
    struct node *prev=NULL;
    struct node *nex=NULL;
    while(head!=NULL){
        nex=head->next;
        head->next=prev;
        prev=head;
        head=nex;
    }
    head=prev;
    return head;
}
void concatenate(struct node *head1, struct node *head2){
    struct node *ptr=head1;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=head2;
}
struct node* sort(struct node *head) {
    struct node *ptr, *cpt;
    int temp;
    for (ptr = head; ptr->next != NULL; ptr = ptr->next) {
        for (cpt = ptr->next; cpt != NULL; cpt = cpt->next) {
            if (cpt->data < ptr->data) {
                temp = ptr->data;
                ptr->data = cpt->data;
                cpt->data = temp;
            }
        }
    }
    return head;
}
void insertBeg(struct node **head, int value){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=*head;
    *head=temp;

}
void insertEnd(struct node *head, int value){
    struct node *temp;
    struct node *ptr=head;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
}
void printData(struct node *head){
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
    struct node *head=NULL;
    insertBeg(&head,34);
    insertEnd(head,45);
    insertEnd(head,5);
    insertEnd(head,65);
    insertEnd(head,47);
    insertEnd(head,90);
    insertEnd(head,87);
    printData(head);
    printf("--------------------\n");
    head = reverse(head);
    printData(head);
    printf("--------------------\n");
    struct node *head1=NULL;
    struct node *head2=NULL;
    insertBeg(&head1,3);
    insertEnd(head1,4);
    insertEnd(head1,5);
    insertBeg(&head2,7);
    insertEnd(head2,6);
    insertEnd(head2,9);
    concatenate(head1,head2);
    printData(head1);
    printf("--------------------\n");
    head=sort(head);
    printData(head);
    printf("--------------------\n");
    
}