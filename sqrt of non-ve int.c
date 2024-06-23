#include <stdio.h>
int mySqrt(int x) {
    if (x == 0) return 0;
    int left = 1, right = x;
    int ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (mid <= x / mid) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}
int main() {
    int x;
    printf("Enter a non-negative integer: ");
    scanf("%d", &x);
    int result = mySqrt(x);
    printf("Square root of %d: %d\n", x, result);
    return 0;
}