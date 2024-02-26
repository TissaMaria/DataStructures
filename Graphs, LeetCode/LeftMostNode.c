  #include <stdio.h>
  #include <stdlib.h>
  struct TreeNode {
      int val;
     struct TreeNode *left;
      struct TreeNode *right;
 };
 
int findBottomLeftValue(struct TreeNode* root) {
    if (root == NULL) {
        return -1;
    }

    struct TreeNode** queue = (struct TreeNode**)malloc(pow(10,4) * sizeof(struct TreeNode*)); 
    int front = 0, rear = 0;
    int leftmostValue = 0;

    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* currentNode = queue[front++];

            if (i == 0) {
                leftmostValue = currentNode->val;
            }

            if (currentNode->left) {
                queue[rear++] = currentNode->left;
            }

            if (currentNode->right) {
                queue[rear++] = currentNode->right;
            }
        }
    }

    free(queue);
    return leftmostValue;
} 