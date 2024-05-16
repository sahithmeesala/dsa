#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define s 20
int cost[s][s];
int dist[s];
void printdist(int dist[],int n)
{
    int sum=0;
    for(int k=1;k<=n;k++)
    {
        printf("%d\t %d\n",k,dist[k]);
        sum=sum+dist[k];
    }
    printf("minimum cost of spanning tree is:%d",sum);
}
void shortestpath(int v,int cost[s][s],int n)
{
    bool S[s]={false};
    for(int i=1;i<=n;i++)
    {
        dist[i]=cost[v][i];
    }
    S[v]=true;
    dist[v]=0.0;
    for(int num=2;num<=n-1;num++)
    {
        int u;
        int min = 99999;
        for(int j = 1; j <= n; j++) {
            if(!S[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }
        S[u] = true;
       for(int w = 1; w <= n; w++)
       {
            if(!S[w] && dist[w] > (dist[u] + cost[u][w]))
            {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }
    printdist(dist,n);
}

int main() {
    int v,n;
    printf("enter number of vertices:");
    scanf("%d",&n);
    printf("enter source vertex:");
    scanf("%d",&v);
    printf("enter weighted matrix:");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    shortestpath(v,cost,n);

    return 0;
}