#include <stdio.h>
#include <stdbool.h>

int n, indegree[5], front = -1, rear = -1, item;
int adjacency[5][5];
int vis[5], queue[5], finalq[5];

void enqueue(int q[], int item) {
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = rear + 1;
    }
    q[rear] = item;
}

int dequeue() {
    if (front == -1) {
        return -1;
    }
    item = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = front + 1;
    }
    return item;
}

bool isEmpty() {
    return front == -1;
}

void main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adjacency[i][j]);
        }
    }

    // Initialize indegree and visited arrays
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        vis[i] = 0;
    }

    // Calculate indegree of each vertex
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            indegree[i] += adjacency[j][i];  // Increment indegree for vertex i
        }
    }

    // Enqueue vertices with no incoming edges (indegree == 0)
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(queue, i);
            vis[i] = 1; // Mark it as visited after enqueuing
        }
    }

    int finalIndex = 0;

    // Perform topological sort
    while (!isEmpty()) {
        int u = dequeue();
        if (u != -1) {
            finalq[finalIndex++] = u;
        }

        // Reduce indegree of all adjacent vertices
        for (int i = 0; i < n; i++) {
            if (adjacency[u][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0 && vis[i] == 0) {
                    enqueue(queue, i);
                    vis[i] = 1;  // Mark as visited when it is enqueued
                }
            }
        }
    }

    // If we processed fewer than n vertices, there is a cycle
    if (finalIndex != n) {
        printf("The graph has a cycle, so topological sorting is not possible.\n");
    } else {
        printf("Topological Order: ");
        for (int i = 0; i < finalIndex; i++) {
            printf("%d ", finalq[i]);
        }
        printf("\n");
    }
}
