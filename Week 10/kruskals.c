#include <stdio.h>
#define MAX 9999 // Infinity value assumed

void kruskals(int c[][100], int n);

int main() {
    int n, i, j;
    int c[100][100]; // Assuming a maximum size for the cost matrix

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
            if (c[i][j] == 0) // Assuming 0 represents no edge, set it to a large value
                c[i][j] = MAX;
        }
    }

    kruskals(c, n);

    return 0;
}

void kruskals(int c[][100], int n) {
    int ne = 0, mincost = 0;
    int parent[100];
    int min, u, v, a, b, i, j;

    for (i = 1; i <= n; i++)
        parent[i] = 0;

    while (ne != n - 1) {
        min = MAX;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (c[i][j] < min) {
                    min = c[i][j];
                    u = a = i;
                    v = b = j;
                }
            }
        }
        while (parent[u] != 0)
            u = parent[u];

        while (parent[v] != 0)
            v = parent[v];

        if (u != v) {
            printf("Edge %d-%d: %d\n", a, b, min);
            parent[v] = u;
            mincost += min;
            ne++;
        }

        c[a][b] = c[b][a] = MAX;
    }

    printf("Minimum cost of spanning tree: %d\n", mincost);
}

