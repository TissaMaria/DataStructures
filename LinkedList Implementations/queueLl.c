#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value) {
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newNode;
        printf("Successfully Added %d\n", value);
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("The queue is empty\n");
    } else {
        struct node *temp;
        temp = front;
        int value = temp->data;
        front = front->next;

        printf("%d deleted\n", value);
        free(temp);
    }
}

void display() {
    struct node *ptr;
    ptr = front;
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    int isRunning = 1, choice, value;

    while (isRunning) {
        printf("\n1.Enqueue\t2.Dequeue\t3.DISPLAY\t4.EXIT\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                isRunning = 0;
                break;

            default:
                printf("Invalid Input\n");
        }
    }

    return 0;
}
