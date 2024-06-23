#include <stdio.h>
#include <string.h>
int min_opera(char S[], char T[], int n) {
    int diff[n];
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (S[i] != T[i]) {
            diff[count++] = i;
        }
    }
    if (count % 2 != 0) {
        return -1;
    }
    int operations = 0;
    int i = 0;
    while (i < count - 1) {
        if (diff[i] + 1 == diff[i + 1]) {
            operations++;
            i += 2;
        } else {
            operations++;
            i += 1;
        }
    }
    return operations;
}
int main() {
    char S[100];
    char T[100];
    printf("Enter the first binary string S: ");
    scanf("%s", S);
    printf("Enter the second binary string T: ");
    scanf("%s", T);
    int n = strlen(S);
    if (n != strlen(T)) {
        printf("The lengths of S and T must be the same.\n");
        return 1;
    }
    int result = min_opera(S, T, n);
    
    if (result != -1) {
        printf("Minimum operations: %d\n", result);
    } else {
        printf("It is impossible to make the strings equal.\n");
    }
    return 0;
}
