#include <stdio.h>
#include <stdbool.h>

#define V 100 // Maximum number of vertices
#define INF 99999 // A large number to represent infinity

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[], int n) {
    int min = INF;
    int min_index = -1;

    // Loop through all vertices to find the minimum key vertex not yet included in MST
    for (int v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index; // Return index of the vertex with minimum key value
}

// Function to construct and print MST using Prim's algorithm
void primMST(int graph[V][V], int n) {
    int parent[V]; // Stores the MST (i.e., parent of each vertex in MST)
    int key[V]; // Key values to pick minimum weight edge
    bool mstSet[V]; // Tracks vertices included in MST

    // Initialize all keys as infinite and mstSet[] as false
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0; // Start from the first vertex (you can choose any)
    parent[0] = -1; // First vertex is the root of MST, so it has no parent

    // The MST will have (n - 1) edges
    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n); // Pick the minimum key vertex not yet in MST
        mstSet[u] = true; // Include it in the MST

        // Update key and parent of the adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++) {
            // graph[u][v] != 0 means there is an edge
            // !mstSet[v] means vertex is not yet included in MST
            // graph[u][v] < key[v] means this edge is lighter than previously known
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the MST using parent[] array
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n); // Input number of vertices

    int graph[V][V];
    printf("Enter the adjacency matrix (0 if no edge):\n");

    // Input adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    // Run Prim's algorithm
    primMST(graph, n);

    return 0;
}
