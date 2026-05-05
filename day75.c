#include <stdio.h>

#define MAX 1000

int maxLenZeroSum(int arr[], int n) {
    int sum = 0, maxLen = 0;

    // Simple hash map using arrays (for demo purpose)
    int hash[2 * MAX + 1];
    for (int i = 0; i < 2 * MAX + 1; i++)
        hash[i] = -2;  // -2 means not visited

    int offset = MAX;  // to handle negative sums

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            maxLen = i + 1;
        }

        if (hash[sum + offset] != -2) {
            int prevIndex = hash[sum + offset];
            int len = i - prevIndex;
            if (len > maxLen)
                maxLen = len;
        } else {
            hash[sum + offset] = i;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLenZeroSum(arr, n));

    return 0;
}