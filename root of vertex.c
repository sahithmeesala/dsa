#include<stdio.h>
int main()
{
 int n;
 printf("Enter the no.of elements in the graph:");
 scanf("%d",&n);
 int m[n][n];
 for(int i=0;i<n;i++)
 {
 for(int j=0;j<n;j++)
 {
 scanf("%d",&m[i][j]);
 }
 }
 for(int i=0;i<n;i++)
 {
 int c=0;
 for(int j=0;j<n;j++)
 {
 if(m[i][j]==1)
 {
 C++;
 }
 }
 if(c==n-1)
 {
 printf("\nRoot of vertex:");
 printf("%d ",i);
 }
 }
}
