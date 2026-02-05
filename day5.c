#include <stdio.h>
#include <stdlib.h>

int main() {
    int p, q;
    int *arr1, *arr2;
    int i = 0, j = 0;

    if (scanf("%d", &p) != 1) return 1;
    arr1 = (int*)malloc(p * sizeof(int));
    for (int k = 0; k < p; k++) {
        scanf("%d", &arr1[k]);
    }

    if (scanf("%d", &q) != 1) return 1;
    arr2 = (int*)malloc(q * sizeof(int));
    for (int k = 0; k < q; k++) {
        scanf("%d", &arr2[k]);
    }

    while (i < p && j < q) {
        if (arr1[i] < arr2[j]) {
            printf("%d ", arr1[i]);
            i++;
        } else {
            printf("%d ", arr2[j]);
            j++;
        }
    }

    while (i < p) {
        printf("%d ", arr1[i]);
        i++;
    }

    while (j < q) {
        printf("%d ", arr2[j]);
        j++;
    }

    free(arr1);
    free(arr2);

    return 0;
}