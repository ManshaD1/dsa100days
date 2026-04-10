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

int dfsCycle(struct Graph* graph, int v, int visited[], int parent) {
    visited[v] = 1;

    struct Node* temp = graph->adjList[v];
    while (temp != NULL) {
        int adj = temp->dest;

        if (!visited[adj]) {
            if (dfsCycle(graph, adj, visited, v))
                return 1;
        }
        else if (adj != parent) {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

int isCyclic(struct Graph* graph) {
    int* visited = (int*)calloc(graph->V, sizeof(int));

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            if (dfsCycle(graph, i, visited, -1))
                return 1;
        }
    }

    return 0;
}

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1); // cycle
    addEdge(graph, 3, 4);

    if (isCyclic(graph))
        printf("Cycle Detected\n");
    else
        printf("No Cycle\n");

    return 0;
}