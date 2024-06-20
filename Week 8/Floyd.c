#include <stdio.h>
#include <limits.h>


void floyd(int n, int cost[][n], int D[][n]) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            D[i][j] = cost[i][j];
        }
    }

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (D[i][k] != INT_MAX && D[k][j] != INT_MAX && D[i][j] > D[i][k] + D[k][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
}

void printShortestPaths(int n, int D[][n]) {
    printf("Shortest paths between every pair of vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (D[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", D[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    int cost[n][n];
    printf("Enter the cost adjacency matrix (use 'INF' for infinity):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == -1) {
                cost[i][j] = INT_MAX;
            }
        }
    }
    int D[n][n];
    floyd(n, cost, D);

    printShortestPaths(n, D);

    return 0;
}

