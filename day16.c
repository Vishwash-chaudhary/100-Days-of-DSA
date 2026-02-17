#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 1;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int first = 1;
    for (int i = 0; i < n; i++) {
        int seen = 0;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                seen = 1;
                break;
            }
        }
        
        if (!seen) {
            int count = 0;
            for (int j = i; j < n; j++) {
                if (arr[j] == arr[i]) {
                    count++;
                }
            }
            if (!first) printf(" ");
            printf("%d:%d", arr[i], count);
            first = 0;
        }
    }
    printf("\n");

    free(arr);
    return 0;
}