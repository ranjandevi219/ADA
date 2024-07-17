#include <stdio.h>
#include <stdlib.h> 
#define MAX_N 10 
int x[MAX_N]; 
int Place(int k, int i, int n) {
 for (int j = 1; j <= k - 1; j++) {
 if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
 return 0; 
 }
 }
 return 1; 
}
void NQueens(int k, int n) {
 for (int i = 1; i <= n; i++) {
 if (Place(k, i, n)) {
 x[k] = i; 
 if (k == n) {
 printf("Solution: ");
 for (int j = 1; j <= n; j++) {
 printf("%d ", x[j]);
 }
 printf("\n");
 } else {
 NQueens(k + 1, n);
 }
 }
 }
}
45
int main() {
 int n;
 printf("Enter the number of queens (n): ");
 scanf("%d", &n);
 for (int i = 0; i <= n; i++) {
 x[i] = 0;
 }
 NQueens(1, n);
 return 0;
}
