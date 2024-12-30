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


void DFS(Graph* g, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("Visited %d\n", vertex);

    for (int i = 0; i < g->numVertices; i++) {
        if (g->adj[vertex][i] == 1 && !visited[i]) {
            DFS(g, i, visited);
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


    printf("Enter the start vertex for DFS: ");
    scanf("%d", &startVertex);

    bool visited[MAX_VERTICES] = {false};


    printf("DFS Traversal starting from vertex %d:\n", startVertex);
    DFS(&g, startVertex, visited);

    return 0;
}
