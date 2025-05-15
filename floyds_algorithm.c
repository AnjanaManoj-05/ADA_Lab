#include <stdio.h>
#define INF 99999
#define V 100

// Function to print the path from u to v using the next matrix
void printPath(int next[V][V], int u, int v) {
if (next[u][v] == -1) {
printf("No path\n");
return;
}
printf("Path: %d", u);
while (u != v) {
u = next[u][v];
printf(" -> %d", u);
}
printf("\n");
}

// Floyd-Warshall algorithm with path reconstruction
void floydWarshall(int graph[V][V], int n) {
int dist[V][V], next[V][V];

perl
Copy
Edit
// Initialize distance and next matrices
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        dist[i][j] = graph[i][j];
        if (graph[i][j] != INF && i != j)
            next[i][j] = j;
        else
            next[i][j] = -1;
    }
}

// Floyd-Warshall main loop
for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][k] != INF && dist[k][j] != INF &&
                dist[i][k] + dist[k][j] < dist[i][j]) {
                dist[i][j] = dist[i][k] + dist[k][j];
                next[i][j] = next[i][k];
            }
        }
    }
}

// Print shortest distance matrix
printf("\nAll Pairs Shortest Path Distances:\n");
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (dist[i][j] == INF)
            printf("%7s", "INF");
        else
            printf("%7d", dist[i][j]);
    }
    printf("\n");
}

// Print all shortest paths
printf("\nShortest Paths:\n");
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (i != j) {
            printf("From %d to %d: ", i, j);
            printPath(next, i, j);
        }
    }
}
}

int main() {
int n;
int graph[V][V];

perl
Copy
Edit
printf("Enter the number of vertices: ");
scanf("%d", &n);

printf("Enter the adjacency matrix (use %d for INF):\n", INF);
for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        scanf("%d", &graph[i][j]);

floydWarshall(graph, n);

return 0;
}







