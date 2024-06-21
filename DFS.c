#include <stdio.h>
#define size 100

int top = -1, stack[size], v[size];

void push(int i) {
    stack[++top] = i;
}

int pop() {
    return stack[top--];
}

void dfs(int vi, int n, int m[size][size]) {
    int u = vi;
    push(u);
    v[u] = 1;

    while (top != -1) {
        u = pop();
        printf("%d ", u);

        for (int w = 0; w < n; w++) {
            if (m[u][w] == 1 && v[w] == 0) {
                push(w);
                v[w] = 1;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    int m[size][size];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        v[i] = 0;
    }

    int s;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &s);

    printf("DFS traversal is: ");
    dfs(s, n, m);
    printf("\n");

    return 0;
}
