#include <stdio.h>
#include <stdlib.h>

int main() {
    int r, c;
    if (scanf("%d %d", &r, &c) != 2) return 1;

    int *mat = (int *)malloc(r * c * sizeof(int));
    for (int i = 0; i < r * c; i++) {
        scanf("%d", &mat[i]);
    }

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;
    int first = 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            if (!first) printf(" ");
            printf("%d", mat[top * c + i]);
            first = 0;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            if (!first) printf(" ");
            printf("%d", mat[i * c + right]);
            first = 0;
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                if (!first) printf(" ");
                printf("%d", mat[bottom * c + i]);
                first = 0;
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                if (!first) printf(" ");
                printf("%d", mat[i * c + left]);
                first = 0;
            }
            left++;
        }
    }
    printf("\n");

    free(mat);
    return 0;
}