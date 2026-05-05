#include <stdio.h>

void merge(int arr[], int l, int mid, int r) {
    int i = l, j = mid + 1, k = 0;
    int temp[r - l + 1];

    // merge two sorted halves
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // remaining elements
    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= r)
        temp[k++] = arr[j++];

    // copy back
    for (i = 0; i < k; i++)
        arr[l + i] = temp[i];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}