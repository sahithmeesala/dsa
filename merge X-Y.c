#include <stdio.h>

void mergeSortedArrays(int X[], int m, int Y[], int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (X[i] > Y[j]) {
            X[k--] = X[i--];
        } else {
            X[k--] = Y[j--];
        }
    }

    while (i >= 0) {
        X[k--] = X[i--];
    }
}

int main() {
    int m, n;

    printf("Enter the size of X[]: ");
    scanf("%d", &m);
    printf("Enter the size of Y[]: ");
    scanf("%d", &n);

    int X[m];
    int Y[n];

    printf("Enter elements of X[] in sorted order:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &X[i]);
    }

    printf("Enter elements of Y[] in sorted order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &Y[i]);
    }

    mergeSortedArrays(X, m, Y, n);

    printf("Merged X[] and Y[]:\n");
    printf("X[] = { ");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", X[i]);
    }
    printf("}\n");

    printf("Y[] = { ");
    for (int i = 0; i < n; i++) {
        printf("%d ", Y[i]);
    }
    printf("}\n");

    return 0;
}
