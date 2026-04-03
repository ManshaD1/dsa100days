#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Stack structure
struct Stack {
    int top;
    int capacity;
    struct TreeNode** arr;
};

struct Stack* createStack(int capacity) {
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->capacity = capacity;
    s->top = -1;
    s->arr = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
    return s;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, struct TreeNode* node) {
    s->arr[++s->top] = node;
}

struct TreeNode* pop(struct Stack* s) {
    if (isEmpty(s)) return NULL;
    return s->arr[s->top--];
}

void zigzagTraversal(struct TreeNode* root) {
    if (root == NULL) return;

    struct Stack* currentLevel = createStack(1000);
    struct Stack* nextLevel = createStack(1000);

    int leftToRight = 1;

    push(currentLevel, root);

    while (!isEmpty(currentLevel)) {
        struct TreeNode* node = pop(currentLevel);
        if (node) {
            printf("%d ", node->val);

            if (leftToRight) {
                if (node->left) push(nextLevel, node->left);
                if (node->right) push(nextLevel, node->right);
            } else {
                if (node->right) push(nextLevel, node->right);
                if (node->left) push(nextLevel, node->left);
            }
        }

        if (isEmpty(currentLevel)) {
            leftToRight = !leftToRight;

            struct Stack* temp = currentLevel;
            currentLevel = nextLevel;
            nextLevel = temp;
        }
    }
}