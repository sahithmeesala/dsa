#include <stdio.h>
#include <math.h>
#define size 20

void swap(double* x, double* y) {
    double temp = *x;
    *x = *y;
    *y = temp;
}
void result(double a[],double p[],int n)
{
double c=0;
    for(int i=0;i<n;i++)
    {
        c=c+(p[i]*a[i]);
    }
    printf("\nThe total profit is : %lf",c);
}
void calculate(double w[],double p[],double m,int n)
{
    double a[size];
  for(int i=0;i<n;i++)
  {
   
      if(w[i]<m)
      {
          m=m-w[i];
          a[i]=1;
         
      }
      else
      {
          a[i]=m/w[i];
          m=0;
      }
  }
  result(a,p,n);
 
}
void pbyw(double w[], double p[], int n,double m) {
    double arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = (p[i] / w[i]);
    }
    printf("\nThe (p[i] / w[i])ratio :\n");
    for(int i=0;i<n;i++)
    {
        printf("%lf\n",arr[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swap(&w[j], &w[j + 1]);
                swap(&p[j], &p[j + 1]);
            }
        }
    }

    printf("The weight and profits are :\n");
    for (int i = 0; i < n; i++) {
        printf("%lf and %lf\n", w[i], p[i]);
    }
    calculate(w,p,m,n);
}

int main() {
    int  n;
    double w[size], p[size],m;
    printf("Enter max capacity of bag: ");
    scanf("%lf", &m);
    printf("Enter number of objects: ");
    scanf("%d", &n);

    printf("Enter weights of objects:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &w[i]);
    }

    printf("Enter profits of objects:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &p[i]);
    }
   

    pbyw(w, p, n,m);
    return 0;
}