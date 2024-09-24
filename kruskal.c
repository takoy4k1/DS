#include <stdio.h>
#include <stdlib.h>

int i, j, u, v, n, ne = 1;  // Loop counters and graph-related variables
int min, mincost = 0, cost[9][9], parent[9];  // Minimum cost, cost adjacency matrix, and parent array

// Function prototypes for Kruskal's algorithm
int find(int);
int uni(int, int);

int main() {
    // Input the number of vertices in the graph
    printf("\n\tImplementation of Kruskal's algorithm\n");
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);
    
    // Input the cost adjacency matrix for the graph
    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            // Replace 0s with a large value (999) to indicate no edge between the vertices
            if (cost[i][j] == 0) {
                cost[i][j] = 999;
            }
        }
    }

    printf("The edges of the Minimum Cost Spanning Tree are:\n");
    
    // Kruskal's algorithm to find the MST
    while (ne < n) {
        min = 999;  // Initialize min to a large value to find the smallest edge

        // Find the smallest edge in the graph
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];  // Update the minimum cost edge
                    u = i;  // Store the vertex u
                    v = j;  // Store the vertex v
                }
            }
        }

        // Find the root of u and v
        u = find(u);
        v = find(v);

        // If u and v are not in the same component, include this edge in the MST
        if (uni(u, v)) {
            printf("%d edge (%d,%d) = %d\n", ne++, i, j, min);
            mincost += min;  // Add the edge cost to the total minimum cost
        }

        // Remove the selected edge from the graph by setting its cost to 999
        cost[i][j] = cost[j][i] = 999;
    }

    // Print the total minimum cost of the MST
    printf("\nMinimum cost = %d\n", mincost);
}

// Find the root of a vertex using path compression
int find(int i) {
    while (parent[i] > 0) {
        i = parent[i];  // Traverse up to the root
    }
    return i;
}

// Union function to unite two components (if they are disjoint)
int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;  // Make one component's root point to the other component's root
        return 1;  // Return 1 if the components were successfully united
    }
    return 0;  // Return 0 if they were already in the same component
}
