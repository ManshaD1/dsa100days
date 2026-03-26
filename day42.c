#include <stdio.h>
#include <stdlib.h>

// -------- Queue (Linked List) --------
struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Node* newNode(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

int isEmptyQueue(struct Queue* q) {
    return q->front == NULL;
}

void enqueue(struct Queue* q, int x) {
    struct Node* temp = newNode(x);

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(struct Queue* q) {
    if (isEmptyQueue(q))
        return -1;

    struct Node* temp = q->front;
    int val = temp->data;

    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return val;
}

// -------- Stack (Array) --------
#define MAX 1000

struct Stack {
    int arr[MAX];
    int top;
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isEmptyStack(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, int x) {
    s->arr[++(s->top)] = x;
}

int pop(struct Stack* s) {
    if (isEmptyStack(s))
        return -1;
    return s->arr[(s->top)--];
}

// -------- Reverse Queue --------
void reverseQueue(struct Queue* q) {
    struct Stack s;
    initStack(&s);

    // Step 1: Move queue elements to stack
    while (!isEmptyQueue(q)) {
        push(&s, dequeue(q));
    }

    // Step 2: Move back to queue
    while (!isEmptyStack(&s)) {
        enqueue(q, pop(&s));
    }
}

// -------- Print Queue --------
void printQueue(struct Queue* q) {
    struct Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// -------- Main --------
int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);

    printf("Original Queue:\n");
    printQueue(&q);

    reverseQueue(&q);

    printf("Reversed Queue:\n");
    printQueue(&q);

    return 0;
}