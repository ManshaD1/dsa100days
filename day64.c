#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adjList;
};

struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));

    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Queue for BFS
struct Queue {
    int front, rear, size, capacity;
    int* arr;
};

struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = 0;
    q->size = 0;
    q->rear = capacity - 1;
    q->arr = (int*)malloc(capacity * sizeof(int));
    return q;
}

int isEmpty(struct Queue* q) {
    return q->size == 0;
}

void enqueue(struct Queue* q, int val) {
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = val;
    q->size++;
}

int dequeue(struct Queue* q) {
    int val = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return val;
}

void BFS(struct Graph* graph, int start) {
    int* visited = (int*)calloc(graph->V, sizeof(int));
    struct Queue* q = createQueue(graph->V);

    visited[start] = 1;
    enqueue(q, start);

    while (!isEmpty(q)) {
        int v = dequeue(q);
        printf("%d ", v);

        struct Node* temp = graph->adjList[v];
        while (temp != NULL) {
            if (!visited[temp->dest]) {
                visited[temp->dest] = 1;
                enqueue(q, temp->dest);
            }
            temp = temp->next;
        }
    }

    free(visited);
}

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    BFS(graph, 0);

    return 0;
}