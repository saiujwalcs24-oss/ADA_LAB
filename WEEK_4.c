#include <stdio.h>
#include <limits.h>
#define MAX 100
void Dijkstra(int n, int cost[MAX][MAX], int s, int dist[MAX]) {
    int visited[MAX];

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        dist[i] = cost[s][i];
    }

    dist[s] = 0;
    visited[s] = 1;

    for (int k = 1; k < n; k++) {
        int min = INT_MAX;
        int U = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                U = i;
            }
        }
        if (U == -1) break;
        visited[U] = 1;
        for (int V = 0; V < n; V++) {
            if (!visited[V] && dist[U] + cost[U][V] < dist[V]) {
                dist[V] = dist[U] + cost[U][V];
            }
        }
    }
}

int main(void) {
    int n, s;
    int cost[MAX][MAX];
    int dist[MAX];

    printf("Enter number of vertices (<= %d): ", MAX);
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &s);

    Dijkstra(n, cost, s, dist);

    printf("Shortest distances from vertex %d:\n", s);
    for (int i = 0; i < n; i++) {
        printf("To %d: %d\n", i, dist[i]);
    }

    return 0;
}
