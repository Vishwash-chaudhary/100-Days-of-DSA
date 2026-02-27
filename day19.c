#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    
    if (scanf("%d", &n) != 1) return 0;
    
    if (n < 2) return 0;
    
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;
    int min_abs_sum = INT_MAX;
    int pair1 = arr[left];
    int pair2 = arr[right];

    while (left < right) {
        int sum = arr[left] + arr[right];
        
        if (abs(sum) < abs(min_abs_sum)) {
            min_abs_sum = sum;
            pair1 = arr[left];
            pair2 = arr[right];
        }

        if (sum < 0) {
            left++;
        } else if (sum > 0) {
            right--;
        } else {
            break; 
        }
    }

    printf("%d %d\n", pair1, pair2);

    free(arr);
    return 0;
}