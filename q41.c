#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node *front, *rear;
};

// Initialize queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue operation
void enqueue(struct Queue* q, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

// Dequeue operation
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return -1; // Queue is empty
    }

    struct Node* temp = q->front;
    int value = temp->data;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return value;
}

int main() {
    int N;
    scanf("%d", &N);

    struct Queue* q = createQueue();

    for (int i = 0; i < N; i++) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int x;
            scanf("%d", &x);
            enqueue(q, x);
        } else if (op == 2) {
            printf("%d\n", dequeue(q));
        }
    }

    return 0;
}