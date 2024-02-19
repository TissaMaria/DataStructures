
#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *left;
    int data;
    struct node *right;
};

struct node* create() {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter value: ");
    int value;
    scanf("%d", &value);
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

void insert(struct node **root, struct node *temp) {
    if (*root == NULL) {
        *root = temp;
    } else {
        if ((*root)->data > temp->data) {
            if ((*root)->left != NULL) {
                insert(&((*root)->left), temp);
            } else {
                (*root)->left = temp;
            }
        } else {
            if ((*root)->right != NULL) {
                insert(&((*root)->right), temp);
            } else {
                (*root)->right = temp;
            }
        }
    }
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

int main() {
    struct node *root = NULL;
    char isRunning;
    do {
        struct node *temp = create();
        if (root == NULL) {
            root = temp;
        } else {
            insert(&root, temp);
        }
        printf("Do you want to continue? (Y/N): ");
        scanf(" %c", &isRunning);
    } while (isRunning == 'Y');

    printf("\nPreorder\n");
    preorder(root);
    printf("\nInorder\n");
    inorder(root);
    printf("\nPostorder\n");
    postorder(root);

    return 0;
}
