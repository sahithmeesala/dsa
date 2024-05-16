#include <stdio.h>

#define size 100

int f = 0, r = 0, q[size], v[size];

void enq(int i) {
   
    q[r] = i;
    r++;
}

void deq() {
    f++;
}

void bfs(int vi, int n, int m[size][size]) {
    int u = vi;
    v[u] =1;
    enq(u);
    printf("%d ", u);
    while (f <= r) {
        u = q[f];
        deq();
        for (int w = 1; w <=n; w++) {
            if (m[u][w] == 1 && v[w] == 0) {
                enq(w);
                v[w] = 1;
                printf("%d ", w);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the graph: ");
    scanf("%d", &n);

    int m[size][size];
    printf("Enter the adjacency matrix: \n");
    for (int i = 1; i <=n; i++) {
        for (int j=1; j <= n; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    for (int i = 1; i <+n; i++) {
        v[i] = 0;
    }

    int s;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &s);

    printf("BFS traversal is: \n");
    bfs(s, n, m);

    return 0;
}