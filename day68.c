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
}

// Queue
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

void kahnTopologicalSort(struct Graph* graph) {
    int V = graph->V;

    int* indegree = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        struct Node* temp = graph->adjList[i];
        while (temp != NULL) {
            indegree[temp->dest]++;
            temp = temp->next;
        }
    }

    struct Queue* q = createQueue(V);

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            enqueue(q, i);
    }

    int count = 0;

    while (!isEmpty(q)) {
        int u = dequeue(q);
        printf("%d ", u);
        count++;

        struct Node* temp = graph->adjList[u];
        while (temp != NULL) {
            indegree[temp->dest]--;

            if (indegree[temp->dest] == 0)
                enqueue(q, temp->dest);

            temp = temp->next;
        }
    }

    if (count != V)
        printf("\nCycle detected (Topological sort not possible)");

    free(indegree);
}

int main() {
    int V = 6;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    kahnTopologicalSort(graph);

    return 0;
}