#include <stdio.h>
#define N 4
int max(int a, int b) {
    return (a > b) ? a : b;
}
void knapsack(int W, int weights[], int profits[]) {
    int dp[N + 1][W + 1];
    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(profits[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    int maxProfit = dp[N][W];
    printf("Maximum Profit: %d\n", maxProfit);
    int w = W;
    printf("Objects selected in the knapsack:\n");
    for (int i = N; i > 0 && maxProfit > 0; i--) {
        if (maxProfit == dp[i - 1][w])
            continue;
        else {
            printf("Object %d (Weight = %d, Profit = %d)\n", i, weights[i - 1], profits[i - 1]);
            maxProfit -= profits[i - 1];
            w -= weights[i - 1];
        }
    }
}

int main() {
    int weights[20],n;
    int profits[20];
    printf("Enter number of weights: ");
    scanf("%d", &n);
    int W = 50;
    printf("Enter the weights:\n")
    for (int j = 0; j < n; j++) {
            scanf("%d", weights[i]);
        }
    printf("Enter the profits:\n");
    for (int j = 0; j < n; j++) {
            scanf("%d", profits[i]);
        }
    knapsack(W, weights, profits);
    return 0;
}

