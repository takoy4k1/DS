#include <stdio.h>
#define MAX 10
#define INF 9999

void dijkstra(int G[MAX][MAX], int n, int start) {
    int cost[MAX][MAX], dist[MAX], pred[MAX], visited[MAX];
    int count, mindist, nextnode, i, j;

    // Initialize cost matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cost[i][j] = (G[i][j] == 0) ? INF : G[i][j];

    // Initialize distance, predecessor and visited arrays
    for (i = 0; i < n; i++) {
        dist[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    dist[start] = 0;
    visited[start] = 1;
    count = 1;

    while (count < n - 1) {
        mindist = INF;

        // Find the node with minimum distance
        for (i = 0; i < n; i++)
            if (dist[i] < mindist && !visited[i]) {
                mindist = dist[i];
                nextnode = i;
            }

        visited[nextnode] = 1;

        // Update distances of neighboring nodes
        for (i = 0; i < n; i++)
            if (!visited[i] && (mindist + cost[nextnode][i] < dist[i])) {
                dist[i] = mindist + cost[nextnode][i];
                pred[i] = nextnode;
            }

        count++;
    }

    // Print shortest distances and paths
    for (i = 0; i < n; i++)
        if (i != start) {
            printf("\nDistance to node %d = %d", i, dist[i]);
            printf("\nPath = %d", i);
            j = i;
            while (j != start) {
                j = pred[j];
                printf(" <- %d", j);
            }
        }
}

int main() {
    int G[MAX][MAX], n, start, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    printf("Enter starting node: ");
    scanf("%d", &start);

    dijkstra(G, n, start);

    return 0;
}
