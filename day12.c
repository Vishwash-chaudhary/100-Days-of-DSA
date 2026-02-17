#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) {
        return 1;
    }

    int *mat = (int *)malloc(m * n * sizeof(int));
    for (int i = 0; i < m * n; i++) {
        scanf("%d", &mat[i]);
    }

    if (m != n) {
        printf("Not a Symmetric Matrix\n");
    } else {
        int is_symmetric = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (mat[i * n + j] != mat[j * n + i]) {
                    is_symmetric = 0;
                    break;
                }
            }
            if (!is_symmetric) break;
        }

        if (is_symmetric) {
            printf("Symmetric Matrix\n");
        } else {
            printf("Not a Symmetric Matrix\n");
        }
    }

    free(mat);
    return 0;
}