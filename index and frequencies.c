#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calculateFrequencyAndIndex(int arr[], int n, int freq[], int firstIndex[]) {
    for (int i = 0; i < n; i++) {
        freq[i] = 1;
        firstIndex[i] = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                freq[i]++;
                arr[j] = -1; 
            }
        }
    }
}

void sortByFrequencyAndIndex(int arr[], int freq[], int firstIndex[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (freq[j] < freq[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swap(&freq[j], &freq[j + 1]);
                swap(&firstIndex[j], &firstIndex[j + 1]);
            } else if (freq[j] == freq[j + 1] && firstIndex[j] > firstIndex[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swap(&freq[j], &freq[j + 1]);
                swap(&firstIndex[j], &firstIndex[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int freq[n];
    int firstIndex[n];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    calculateFrequencyAndIndex(arr, n, freq, firstIndex);
    sortByFrequencyAndIndex(arr, freq, firstIndex, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1) {
            for (int j = 0; j < freq[i]; j++) {
                printf("%d ", arr[i]);
            }
        }
    }

    return 0;
}
