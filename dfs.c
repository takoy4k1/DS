#include <stdio.h>

int adjacencyMatrix[20][20], stack[20], visited[20]; // Graph, stack for DFS, visited array
int numVertices, top = -1;  // Number of vertices and stack top

// Function declaration for DFS
void dfs(int startVertex);

int main() {
    int startVertex, i, j;  // Variables for the starting vertex and loop counters
    
    // Input the number of vertices in the graph
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    
    // Input the adjacency matrix representing the graph
    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < numVertices; i++) {
        for(j = 0; j < numVertices; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);  // 1 means an edge exists, 0 means no edge
        }
    }

    // Input the starting vertex for DFS traversal
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    // Initialize visited array to 0 (not visited)
    for(i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    // Start DFS traversal
    dfs(startVertex);

    // Print the reachable nodes from the starting vertex
    printf("The reachable nodes are: ");
    for(i = 0; i < numVertices; i++) {
        if(visited[i]) {
            printf("%d ", i);  // Print each reachable node
        }
    }

    return 0;
}

// DFS function using a stack
void dfs(int startVertex) {
    int i, currentVertex;

    // Push the starting vertex onto the stack
    stack[++top] = startVertex;
    visited[startVertex] = 1;  // Mark the starting vertex as visited
    printf("DFS Traversal starting from vertex %d: ", startVertex);

    // Continue until the stack is empty
    while(top != -1) {
        // Pop the top vertex from the stack
        currentVertex = stack[top--];
        printf("%d ", currentVertex);  // Print the current vertex
        
        // Explore all adjacent vertices
        for(i = 0; i < numVertices; i++) {
            // If an edge exists and the vertex is unvisited, push it onto the stack
            if(adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                stack[++top] = i;  // Push adjacent vertex onto stack
                visited[i] = 1;    // Mark the vertex as visited
            }
        }
    }
}
