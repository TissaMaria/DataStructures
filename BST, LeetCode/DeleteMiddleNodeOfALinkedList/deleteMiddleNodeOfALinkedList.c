/**
 * Definition for singly-linked list.*/
#include <stdlib.h>
#include <stdio.h>
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 
struct ListNode* deleteMiddle(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        free(head);
        return NULL;
    }

    struct ListNode *ptr1 = head;
    struct ListNode *ptr2 = head;
    struct ListNode *ptr3 = head;
    int count = 0;
    while(ptr3!=NULL){
        count++;
        ptr3=ptr3->next;
    }
    int pos=0;
    while(pos<(count/2)){
        ptr2=ptr1;
        ptr1=ptr1->next;
        pos++;
    }
    
    ptr2->next=ptr1->next;
    free(ptr1);
    ptr1=NULL;
    return head;

    }