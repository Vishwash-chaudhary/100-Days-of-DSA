#include <stdio.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX];
int n, m;

int minDist(int dist[], int visited[]) {
    int min = INT_MAX, idx = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            idx = i;
        }
    }
    return idx;
}

void dijkstra(int src) {
    int dist[MAX], visited[MAX];

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 1; count <= n; count++) {
        int u = minDist(dist, visited);
        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !visited[v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // print result
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    scanf("%d %d", &n, &m);

    // initialize
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = 0;

    // input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;  // undirected
    }

    int src;
    scanf("%d", &src);

    dijkstra(src);

    return 0;
}