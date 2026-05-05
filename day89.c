#include <stdio.h>

// check if allocation is possible with maxPages limit
int canAllocate(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages)
            return 0;

        if (pages + arr[i] <= maxPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
        }

        if (students > m)
            return 0;
    }

    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    int sum = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    int left = 0, right = sum;
    int ans = sum;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canAllocate(arr, n, m, mid)) {
            ans = mid;
            right = mid - 1;  // try smaller max
        } else {
            left = mid + 1;   // increase limit
        }
    }

    printf("%d\n", ans);

    return 0;
}