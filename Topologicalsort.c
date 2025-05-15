#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int n;
int indegree[MAX], front = -1, rear = -1;
int adjacency[MAX][MAX];
int vis[MAX], queue[MAX], finalq[MAX];

void enqueue(int q[], int item) {
    if (rear >= n - 1) {
        printf("Queue overflow\n");
        return;
    }
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
    int item = queue[front];
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

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adjacency[i][j]);
        }
    }

    // Initialize indegree and visited arrays using loops
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        vis[i] = 0;
        queue[i] = 0;
        finalq[i] = 0;
    }

    // Calculate indegree of each vertex
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            indegree[i] += adjacency[j][i];
        }
    }

    // Enqueue vertices with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(queue, i);
            vis[i] = 1;
        }
    }

    int finalIndex = 0;

    // Perform topological sort
    while (!isEmpty()) {
        int u = dequeue();
        if (u != -1) {
            finalq[finalIndex++] = u;
        }

        for (int i = 0; i < n; i++) {
            if (adjacency[u][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0 && vis[i] == 0) {
                    enqueue(queue, i);
                    vis[i] = 1;
                }
            }
        }
    }

    if (finalIndex != n) {
        printf("The graph has a cycle, so topological sorting is not possible.\n");
    } else {
        printf("Topological Order: ");
        for (int i = 0; i < finalIndex; i++) {
            printf("%d ", finalq[i]);
        }
        printf("\n");
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[MAX];  // array of pointers to linked list
int indegree[MAX], vis[MAX], queue[MAX], finalq[MAX];
int n, front = -1, rear = -1;

void enqueue(int item) {
    if (rear >= n - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = item;
}

int dequeue() {
    if (front == -1) return -1;
    int item = queue[front];
    if (front == rear) front = rear = -1;
    else front++;
    return item;
}

void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
    indegree[v]++;
}

int main() {
    int edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Init
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        indegree[i] = 0;
        vis[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (from to):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
            vis[i] = 1;
        }
    }

    int finalIndex = 0;

    while (front != -1) {
        int u = dequeue();
        finalq[finalIndex++] = u;

        Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            indegree[v]--;
            if (indegree[v] == 0 && vis[v] == 0) {
                enqueue(v);
                vis[v] = 1;
            }
            temp = temp->next;
        }
    }

    if (finalIndex != n) {
        printf("Cycle detected. Topological sort not possible.\n");
    } else {
        printf("Topological Order: ");
        for (int i = 0; i < finalIndex; i++) {
            printf("%d ", finalq[i]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        Node* temp = adj[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }

    return 0;
}
