#include <stdio.h>

int missingNumber(int nums[], int n) {
    int eSum = n * (n + 1) / 2;
    int aSum = 0;
    for (int i = 0; i < n; ++i) {
        aSum += nums[i];
    }
    return eSum - aSum;
}

int main() {
    int n;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int nums[n];
    
    printf("Enter the %d elements of the array:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
    }
    
    int result = missingNumber(nums, n);
    printf("Missing number in the array: %d\n", result);
    
    return 0;
}
