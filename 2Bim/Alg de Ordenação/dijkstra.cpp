#include <stdio.h>
#include <limits.h>

#define V 4

//== Para simplificar, utilizaremos uma matriz de adjacência.

int minDistancia(int dist[], int visitado[]) {
    int min = INT_MAX;
    int minIndice;

    for (int v = 0; v < V; v++) {
        if (!visitado[v] && dist[v] <= min) {
            min = dist[v];
            minIndice = v;
        }
    }

    return minIndice;
}

void dijkstra(int grafo[V][V], int origem) {
    int dist[V];
    int visitado[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visitado[i] = 0;
    }
    dist[origem] = 0;
    for (int cont = 0; cont < V - 1; cont++) {
        int u = minDistancia(dist, visitado);
        visitado[u] = 1;
        for (int v = 0; v < V; v++) {
            if (!visitado[v] &&
                grafo[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + grafo[u][v] < dist[v]) {

                dist[v] = dist[u] + grafo[u][v];
            }
        }
    }
    printf("Menores distancias a partir da origem:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertice %d -> %d\n", i, dist[i]);
    }
}

int main() {

    int grafo[V][V] = {
        {0, 4, 2, 7},
        {4, 0, 0, 5},
        {2, 0, 0, 1},
        {7, 5, 1, 0}
    };

    dijkstra(grafo, 0);

    return 0;
}
