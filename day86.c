#include <stdio.h>

int integerSqrt(int n) {
    int left = 0, right = n;
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (mid <= n / mid) {  // avoids overflow
            ans = mid;         // valid candidate
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", integerSqrt(n));

    return 0;
}