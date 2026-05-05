#include <stdio.h>

// check if we can paint within maxTime using k painters
int canPaint(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int total = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime)
            return 0;

        if (total + arr[i] <= maxTime) {
            total += arr[i];
        } else {
            painters++;
            total = arr[i];
        }

        if (painters > k)
            return 0;
    }

    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    int sum = 0, maxVal = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    int left = maxVal;
    int right = sum;
    int ans = sum;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPaint(arr, n, k, mid)) {
            ans = mid;
            right = mid - 1;  // try smaller time
        } else {
            left = mid + 1;   // need more time
        }
    }

    printf("%d\n", ans);

    return 0;
}