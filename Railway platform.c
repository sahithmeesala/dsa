#include <stdio.h>

// Function to find the minimum number of platforms required
int findMinPlatforms(float arr[], float dep[], int n) {
    int i = 0, j = 0;
    int platforms = 0, maxPlatforms = 0;

    // Sort the arrival and departure arrays
    for (int k = 0; k < n-1; k++) {
        for (int l = 0; l < n-k-1; l++) {
            if (arr[l] > arr[l+1]) {
                float temp = arr[l];
                arr[l] = arr[l+1];
                arr[l+1] = temp;
            }
            if (dep[l] > dep[l+1]) {
                float temp = dep[l];
                dep[l] = dep[l+1];
                dep[l+1] = temp;
            }
        }
    }

    // Use two indices to traverse the arrival and departure arrays
    while (i < n && j < n) {
        if (arr[i] < dep[j]) {
            platforms++;
            if (platforms > maxPlatforms) {
                maxPlatforms = platforms;
            }
            i++;
        } else {
            platforms--;
            j++;
        }
    }

    return maxPlatforms;
}

int main() {
    int n;
    printf("Enter the number of trains: ");
    scanf("%d", &n);

    float arrival[n];
    float departure[n];

    printf("Enter the arrival times of the trains:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arrival[i]);
    }

    printf("Enter the departure times of the trains:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &departure[i]);
    }

    int minPlatforms = findMinPlatforms(arrival, departure, n);
    printf("Minimum number of platforms needed: %d\n", minPlatforms);

    return 0;
}
