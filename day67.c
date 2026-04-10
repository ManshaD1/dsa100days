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

void topoDFS(struct Graph* graph, int v, int visited[], struct Stack* stack);

struct Stack {
    int top;
    int capacity;
    int* arr;
};

struct Stack* createStack(int capacity) {
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->capacity = capacity;
    s->top = -1;
    s->arr = (int*)malloc(capacity * sizeof(int));
    return s;
}

void push(struct Stack* s, int val) {
    s->arr[++s->top] = val;
}

int pop(struct Stack* s) {
    return s->arr[s->top--];
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void topoDFSUtil(struct Graph* graph, int v, int visited[], struct Stack* stack) {
    visited[v] = 1;

    struct Node* temp = graph->adjList[v];
    while (temp != NULL) {
        if (!visited[temp->dest]) {
            topoDFSUtil(graph, temp->dest, visited, stack);
        }
        temp = temp->next;
    }

    push(stack, v);
}

void topologicalSort(struct Graph* graph) {
    int* visited = (int*)calloc(graph->V, sizeof(int));
    struct Stack* stack = createStack(graph->V);

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            topoDFSUtil(graph, i, visited, stack);
        }
    }

    while (!isEmpty(stack)) {
        printf("%d ", pop(stack));
    }
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

    topologicalSort(graph);

    return 0;
}