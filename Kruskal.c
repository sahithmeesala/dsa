#include <stdio.h>
int cost[100][100], n, t[100][2], m, p[100], e[100],p1;
void adjust(int e[], int i, int m) {
    int j = 2 * i;
    int item = e[i];
    while (j <= m) {
        if (j < m && e[j] > e[j + 1]) {
            j = j + 1;
        }
        if (item <= e[j]) {
            break;
        }
        e[j / 2] = e[j];
        j = 2 * j;
    }
    e[j / 2] = item;
}
void heapify() {
    for (int i = m / 2; i > 0; i--) {
        adjust(e, i, m);
    }
}
int delete1() {
    int x;
    if (m == 0) {
        return 0;
    } else {
        x = e[1];
        e[1] = e[m];
        m--;
        adjust(e, 1, m);
    }
    return x;
}
int find(int k) {
    while (p[k] > 0) {
        k = p[k];
    }
    return k;
}
float kruskal() {
    m = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cost[i][j] != 0) {
                m++;
                e[m] = cost[i][j];
            }
        }
    }
    heapify();
    for (int i = 0; i < n; i++) {
        p[i] = -1;
    }

    int i = 0;
    float mincost = 0.0;
    while (i < n - 1 && m != 0) {
        p1 = delete1();
        for (int u = 0; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                if (cost[u][v] == p1) {
                    int j = find(u);
                    int k = find(v);
                    if (j != k) {
                        i++;
                        t[i][1] = u;
                        t[i][2] = v;
                        mincost += cost[u][v];
                        p[j] = k;
                    }
                }
            }
        }
    }
    if (i != n - 1) {
        printf("No spanning tree\n");
        return -1;
    } else {
        return mincost;
    }
}
int main() {
    int i, j;
    printf("Enter no. of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    float minCost = kruskal();
    printf("The edges added in spanning tree:\n");
    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=2;j++)
        {
            printf("%d ",t[i][j]);
        }
        printf("\n");
    }
    if (minCost != -1) {
        printf("Minimum spanning tree cost: %.2f\n", minCost);
    }
    return 0;
}