#include <stdio.h>
#include <limits.h>

#define V 100
#define E 1000

struct Edge {
    int src, dest, weight;
};

void bellmanFord(struct Edge edges[], int e, int v, int src) {
    int dist[V];

    for (int i = 0; i < v; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int i = 1; i <= v - 1; i++) {
        for (int j = 0; j < e; j++) {
            int u = edges[j].src;
            int vtx = edges[j].dest;
            int wt = edges[j].weight;

            if (dist[u] != INT_MAX && dist[u] + wt < dist[vtx]) {
                dist[vtx] = dist[u] + wt;
            }
        }
    }

    for (int i = 0; i < e; i++) {
        int u = edges[i].src;
        int vtx = edges[i].dest;
        int wt = edges[i].weight;

        if (dist[u] != INT_MAX && dist[u] + wt < dist[vtx]) {
            printf("Negative weight cycle detected\n");
            return;
        }
    }

    for (int i = 0; i < v; i++) {
        printf("%d %d\n", i, dist[i]);
    }
}

int main() {
    int v = 5, e = 8;

    struct Edge edges[E] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    bellmanFord(edges, e, v, 0);

    return 0;
}