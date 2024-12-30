#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10


typedef struct {
    int adj[MAX_VERTICES][MAX_VERTICES]; 
    int numVertices; 
} Graph;


void createGraph(Graph* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adj[i][j] = 0; 
        }
    }
}


void addEdge(Graph* g, int start, int end) {
    g->adj[start][end] = 1;
    g->adj[end][start] = 1;
}


void BFS(Graph* g, int startVertex) {
    int visited[MAX_VERTICES] = {0}; 
    int bfsQueue[MAX_VERTICES]; 
    int front = 0, rear = 0; 

    visited[startVertex] = 1;
    bfsQueue[rear++] = startVertex; 

    printf("BFS Traversal starting from vertex %d:\n", startVertex);


    while (front < rear) {
        int currentVertex = bfsQueue[front++];
        printf("Visited %d\n", currentVertex);

        for (int i = 0; i < g->numVertices; i++) {
            if (g->adj[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;  
                bfsQueue[rear++] = i;
            }
        }
    }
}

int main() {
    Graph g;
    int vertices, edges, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    createGraph(&g, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (start_vertex end_vertex):\n");
    for (int i = 0; i < edges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        addEdge(&g, start, end);
    }

    printf("Enter the start vertex for BFS: ");
    scanf("%d", &startVertex);

    BFS(&g, startVertex);

    return 0;
}
