
  #include <stdio.h>
  #include <stdlib.h>
  struct TreeNode {
      int val;
     struct TreeNode *left;
      struct TreeNode *right;
 };
 
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
     struct TreeNode *current = root;
    struct TreeNode *parent;

   
    while (current != NULL && current->val != key) {
        parent = current;
        if (key < current->val) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

   
    if (current == NULL) {
        return root;
    }

    if (current->left == NULL) {
        struct TreeNode *temp = current->right;
        if (parent == NULL) {
            free(current);
            return temp;
        } else if (current == parent->left) {
            parent->left = temp;
        } else {
            parent->right = temp;
        }
        free(current);
    } else if (current->right == NULL) {
        struct TreeNode *temp = current->left;
        if (parent == NULL) {
            free(current);
            return temp;
        } else if (current == parent->left) {
            parent->left = temp;
        } else {
            parent->right = temp;
        }
        free(current);
    } else {
 
        struct TreeNode *successor = current->right;
        while (successor->left != NULL) {
            successor = successor->left;
        }

        current->val = successor->val;

       
        current->right = deleteNode(current->right, successor->val);
    }

    return root;
}
