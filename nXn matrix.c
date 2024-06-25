#include <stdio.h>

#define MAX_SIZE 100

int isValid(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    int rowCount[MAX_SIZE][MAX_SIZE + 1] = {0};
    int colCount[MAX_SIZE][MAX_SIZE + 1] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num = matrix[i][j];
            rowCount[i][num]++;
            colCount[j][num]++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int num = 1; num <= n; num++) {
            if (rowCount[i][num] != 1 || colCount[i][num] != 1) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int matrix[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int result = isValid(matrix, n);

    if (result) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
