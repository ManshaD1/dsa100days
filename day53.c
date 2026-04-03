#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Queue node for BFS
struct QNode {
    struct TreeNode* node;
    int hd;
};

// Simple queue
struct Queue {
    int front, rear, size, capacity;
    struct QNode* array;
};

struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = 0;
    q->size = 0;
    q->rear = capacity - 1;
    q->array = (struct QNode*)malloc(capacity * sizeof(struct QNode));
    return q;
}

int isEmpty(struct Queue* q) {
    return q->size == 0;
}

void enqueue(struct Queue* q, struct TreeNode* node, int hd) {
    q->rear = (q->rear + 1) % q->capacity;
    q->array[q->rear].node = node;
    q->array[q->rear].hd = hd;
    q->size++;
}

struct QNode dequeue(struct Queue* q) {
    struct QNode item = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}

// Structure to store vertical order
struct VNode {
    int hd;
    int val;
};

int compare(const void* a, const void* b) {
    struct VNode* x = (struct VNode*)a;
    struct VNode* y = (struct VNode*)b;
    if (x->hd == y->hd)
        return 0;
    return x->hd - y->hd;
}

void verticalOrder(struct TreeNode* root) {
    if (root == NULL) return;

    struct Queue* q = createQueue(1000);
    struct VNode arr[1000];
    int idx = 0;

    enqueue(q, root, 0);

    while (!isEmpty(q)) {
        struct QNode temp = dequeue(q);
        struct TreeNode* node = temp.node;
        int hd = temp.hd;

        arr[idx].hd = hd;
        arr[idx].val = node->val;
        idx++;

        if (node->left)
            enqueue(q, node->left, hd - 1);
        if (node->right)
            enqueue(q, node->right, hd + 1);
    }

    qsort(arr, idx, sizeof(struct VNode), compare);

    for (int i = 0; i < idx; i++) {
        printf("%d ", arr[i].val);
    }
}