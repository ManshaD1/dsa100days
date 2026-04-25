#include <stdio.h>

#define MAX 1000

int adj[MAX][MAX];
int visited[MAX];
int n;

void dfs(int node) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    dfs(0);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            printf("Not Connected\n");
            return 0;
        }
    }

    printf("Connected\n");

    return 0;
}