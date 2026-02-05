#include <stdio.h>

int main() {
    int n, k, i;
    int comparisons = 0;
    int found = 0;
    int index = -1;

    if (scanf("%d", &n) != 1) return 1;

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    for (i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            found = 1;
            index = i;
            break;
        }
    }

    if (found) {
        printf("Found at index %d\n", index);
    } else {
        printf("Not Found\n");
    }

    printf("Comparisons = %d\n", comparisons);

    return 0;
}