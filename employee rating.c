#include <stdio.h>
int maxdays(int N, int workload[]) {
    int max = 0;
    int c = 0;
    for (int i = 0; i < N; ++i) {
        if (workload[i] > 6) {
            c++;
        } else {
            if (c > max) {
                max = c;
            }
            c = 0;
        }
    }
    if (c > max) {
        max = c;
    }
    
    return max;
}
int main() {
    int N;
    printf("Enter the number of working days: ");
    scanf("%d", &N);
    int workload[N];
    printf("Enter the workload for each day:\n");
    for (int i = 0; i < N; ++i) {
        scanf("%d", &workload[i]);
    }
    int rating = maxdays(N, workload);
    printf("Employee rating: %d\n", rating);
    return 0;
}
