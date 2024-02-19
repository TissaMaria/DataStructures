/*
  Definition for singly-linked list.*/
  #include <stdio.h>
  #include <stdlib.h>
  struct ListNode {
     int val;
     struct ListNode *next;
  };

struct ListNode* oddEvenList(struct ListNode* head) {
    if(head==NULL||head->next==NULL){
            return head;
    }
    struct ListNode *oddHead=head;
    struct ListNode *evenHead=head->next;
    struct ListNode *odd=oddHead;
    struct ListNode *even=evenHead;
    while(even !=NULL&&even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenHead;
    return oddHead;
}