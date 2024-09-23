#include <stdio.h>

int adjacencyMatrix[20][20], queue[20], visited[20]; // Adjacency matrix to represent the graph, queue for BFS, visited array
int numVertices, front = -1, rear = -1;  // Number of vertices, queue front and rear

// Function declaration for BFS
void bfs(int vertex);

int main() {
    int startVertex, i, j;  // Variables for the starting vertex and loop counters
    
    // Input the number of vertices in the graph
    printf("\nEnter number of vertices: ");
    scanf("%d", &numVertices);
    
    // Initialize all vertices as unvisited (0 means not visited)
    for (i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }
    
    // Input the adjacency matrix representing the graph
    printf("\nEnter graph data in matrix form:\n");
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);  // 1 means an edge exists, 0 means no edge
        }
    }
    
    // Input the starting vertex for BFS traversal
    printf("\nEnter the starting vertex: ");
    scanf("%d", &startVertex);
    
    // Initialize queue for BFS traversal
    front = rear = 0;  // Start the queue with the first vertex
    queue[rear] = startVertex;  // Enqueue the starting vertex
    visited[startVertex] = 1;   // Mark the starting vertex as visited
    
    // Print the BFS traversal order
    printf("\nBFS Traversal is: ");
    printf("%d ", startVertex);  // Print the starting vertex
    
    // Call BFS to traverse the graph
    bfs(startVertex);
    
    return 0;
}

// BFS function definition
void bfs(int vertex) {
    int i;  // Loop counter
    
    // Loop through all vertices adjacent to the current vertex
    for (i = 0; i < numVertices; i++) {
        // Check if there's an edge between the current vertex and vertex 'i', and if 'i' is unvisited
        if (adjacencyMatrix[vertex][i] != 0 && visited[i] == 0) {
            rear++;              // Increment the rear of the queue
            queue[rear] = i;     // Enqueue the adjacent vertex
            visited[i] = 1;      // Mark the adjacent vertex as visited
            printf("%d ", i);    // Print the vertex as part of the BFS traversal
        }
    }
    
    // Move the front pointer forward and continue BFS if more vertices are in the queue
    front++;
    if (front <= rear) {
        bfs(queue[front]);  // Recursively call BFS for the next vertex in the queue
    }
}
