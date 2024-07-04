#include <stdio.h>

#define MAX 9999

void prims(int n, int cost[n][n]) {
    int i, j, u, min, sum = 0, source, K = 0;
    int S[n], d[n], P[n], T[n-1][2];
    min = MAX;
    source = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (cost[i][j] != 0 && cost[i][j] < min) {
                min = cost[i][j];
                source = i;
            }
        }
    }
    for (i = 0; i < n; i++) {
        S[i] = 0;
        d[i] = cost[source][i];
        P[i] = source;
    }
    S[source] = 1;
    for (i = 1; i < n; i++) {
        min = MAX;
        u = -1;
        for (j = 0; j < n; j++) {
            if (S[j] == 0 && d[j] <= min) {
                min = d[j];
                u = j;
            }
        }
        T[K][0] = u;
        T[K][1] = P[u];
        K++;
        sum += cost[u][P[u]];
        S[u] = 1;
        for (j = 0; j < n; j++) {
            if (S[j] == 0 && cost[u][j] < d[j]) {
                d[j] = cost[u][j];
                P[j] = u;
            }
        }
    }
    if (sum >= MAX) {
        printf("Spanning tree does not exist.\n");
    } else {
        printf("Spanning tree exists and MST is:\n");
        for (i = 0; i < n-1; i++) {
            printf("%d - %d\n", T[i][0], T[i][1]);
        }
        printf("The cost of spanning tree (MST) is %d\n", sum);
    }
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int cost[n][n];
    printf("Enter the cost adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    prims(n, cost);

    return 0;
}
