#include <stdio.h>

#define size 20

int min(int* x, int y) {
    return (*x < y) ? *x : y;
}

void printAPSP(int n, int arr[][size]) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

void APSP(int n, int arr[][size]) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j) {
                    arr[i][j] = min(&arr[i][j], (arr[i][k] + arr[k][j]));
                }
            }
        }
    }
    printAPSP(n, arr);
}

int main() {
    int n, arr[size][size];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    APSP(n, arr);
    return 0;
}