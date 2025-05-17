**start input from 0**

#include <stdio.h>
#include <stdlib.h>

#define V 100 // Maximum number of vertices

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for Union-Find
struct Subset {
    int parent;
    int rank;
};

// Function to find the root of a set (with path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent); // Path compression

    return subsets[i].parent;
}

// Function to unite two subsets (by rank)
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Attach smaller rank tree under root of high rank tree
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to compare two edges based on their weights (for qsort)
int compareEdges(const void* a, const void* b) {
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge1->weight - edge2->weight;
}

// Kruskal's algorithm function
void kruskal(struct Edge edges[], int numVertices, int numEdges) {
    struct Edge result[V]; // To store the result MST
    int e = 0; // Index for result[]
    int i = 0; // Index for sorted edges

    // Sort edges in increasing order of weight
    qsort(edges, numEdges, sizeof(edges[0]), compareEdges);

    // Allocate memory for creating subsets
    struct Subset subsets[V];
    for (int v = 0; v < numVertices; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Process edges one by one
    while (e < numVertices - 1 && i < numEdges) {
        struct Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does not cause a cycle, include it
        if (x != y) {
            result[e++] = next_edge;
            unionSets(subsets, x, y);
        }
    }

    // Print the MST
    printf("Edge \tWeight\n");
    for (i = 0; i < e; i++)
        printf("%d - %d \t%d\n", result[i].src, result[i].dest, result[i].weight);
}

// Main function
int main() {
    int numVertices, numEdges;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &numVertices, &numEdges);

    struct Edge edges[V];

    printf("Enter each edge as: src dest weight\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    kruskal(edges, numVertices, numEdges);

    return 0;
}
