#include <stdio.h>
#define MAX 10  // Maximum number of vertices
#define INF 999 // A large value representing infinity for non-existent edges

int cost[MAX][MAX], visited[MAX], mincost = 0;  // Global variables for cost matrix, visited array, and minimum cost

// Prim's Algorithm for Minimum Spanning Tree
void prims(int num) {
    int i, j, ne = 1;  // Loop counters and number of edges
    int min, a = 0, b = 0;  // Variables to track the minimum edge
    int u, v;

    // Initialize visited array to 0 (no vertex visited yet)
    for (i = 1; i <= num; i++) {
        visited[i] = 0;
    }

    // Replace all 0s (no edge) in the cost matrix with INF to prevent selection of non-existent edges
    for (i = 1; i <= num; i++) {
        for (j = 1; j <= num; j++) {
            if (cost[i][j] == 0) {
                cost[i][j] = INF;  // No edge is treated as infinity (not selectable)
            }
        }
    }

    visited[1] = 1;  // Start from the first vertex (assuming it's 1-based)

    // Loop until we include all vertices in the MST (num-1 edges for num vertices)
    while (ne < num) {
        min = INF;  // Initialize min to infinity

        // Find the minimum cost edge between a visited and an unvisited vertex
        for (i = 1; i <= num; i++) {
            if (visited[i]) {  // Only consider vertices that are already visited
                for (j = 1; j <= num; j++) {
                    if (!visited[j] && cost[i][j] < min) {  // Find the smallest edge to an unvisited vertex
                        min = cost[i][j];  // Update minimum cost
                        a = i;  // Store the index of the current vertex
                        b = j;  // Store the index of the adjacent vertex
                    }
                }
            }
        }

        printf("\nEdge %d: (%d - %d) cost: %d", ne++, a, b, min);  // Print the selected edge
        mincost += min;  // Add the minimum cost to the total minimum cost
        visited[b] = 1;  // Mark the selected vertex as visited
        cost[a][b] = cost[b][a] = INF;  // Set the edge cost to infinity to avoid reselecting it
    }

    // Print the total minimum cost of the MST
    printf("\n\nMinimum cost = %d\n", mincost);
}

int main() {
    int num, i, j;

    // Input the number of vertices in the graph
    printf("Enter the number of vertices: ");
    scanf("%d", &num);

    // Input the cost matrix (adjacency matrix representation of the graph)
    printf("Enter the cost matrix:\n");
    for (i = 1; i <= num; i++) {
        for (j = 1; j <= num; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Call Prim's algorithm
    prims(num);

    return 0;
}
