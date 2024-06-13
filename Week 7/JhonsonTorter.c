#include <stdio.h>
#include <stdbool.h>

#define MAXN 10

// Direction array, dir[i] stores the direction of ith element in permutation
int dir[MAXN];
int n; // Number of elements in the permutation

// Function to print the current permutation
void printPermutation(int perm[]) {
    for (int i = 0; i < n; i++)
        printf("%d ", perm[i]);
    printf("\n");
}

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to generate all permutations using Johnson-Trotter algorithm
void generatePermutations() {
    int perm[MAXN]; // Current permutation
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1; // Initialize permutation to 1, 2, ..., n
        dir[i] = -1; // All directions initially set to -1 (left)
    }

    printPermutation(perm); // Print the initial permutation

    int k, mobile, pos;
    bool found;

    while (true) {
        // Step 1: Find the largest mobile integer
        mobile = -1;
        for (int i = 0; i < n; i++) {
            if ((dir[i] == -1 && i != 0 && perm[i] > perm[i - 1]) ||
                (dir[i] == 1 && i != n - 1 && perm[i] > perm[i + 1])) {
                if (mobile == -1 || perm[i] > perm[mobile]) {
                    mobile = i;
                }
            }
        }
        if (mobile == -1) // No more mobile integers, algorithm terminates
            break;

        // Step 2: Swap the mobile integer with the adjacent integer it is pointing to
        k = mobile + dir[mobile];
        swap(&perm[mobile], &perm[k]);
        swap(&dir[mobile], &dir[k]);

        // Step 3: Reverse the direction of all integers greater than the mobile integer
        for (int i = 0; i < n; i++) {
            if (perm[i] > perm[k]) {
                dir[i] = -dir[i];
            }
        }

        // Print the current permutation
        printPermutation(perm);
    }
}

int main() {
    printf("Enter the number of elements (maximum %d): ", MAXN);
    scanf("%d", &n);
    if (n <= 0 || n > MAXN) {
        printf("Invalid input. Number of elements should be between 1 and %d.\n", MAXN);
        return 1;
    }

    generatePermutations(); // Generate permutations using Johnson-Trotter algorithm

    return 0;
}

