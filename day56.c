#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Queue for iterative approach
struct Queue {
    int front, rear, size, capacity;
    struct TreeNode** arr;
};

struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = 0;
    q->size = 0;
    q->rear = capacity - 1;
    q->arr = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
    return q;
}

int isEmpty(struct Queue* q) {
    return q->size == 0;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = node;
    q->size++;
}

struct TreeNode* dequeue(struct Queue* q) {
    struct TreeNode* node = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return node;
}

int isSymmetric(struct TreeNode* root) {
    if (root == NULL) return 1;

    struct Queue* q = createQueue(1000);
    enqueue(q, root->left);
    enqueue(q, root->right);

    while (!isEmpty(q)) {
        struct TreeNode* t1 = dequeue(q);
        struct TreeNode* t2 = dequeue(q);

        if (t1 == NULL && t2 == NULL) continue;
        if (t1 == NULL || t2 == NULL) return 0;
        if (t1->val != t2->val) return 0;

        enqueue(q, t1->left);
        enqueue(q, t2->right);
        enqueue(q, t1->right);
        enqueue(q, t2->left);
    }

    return 1;
}