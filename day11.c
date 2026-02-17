#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) {
        return 1;
    }

    int **mat1 = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        mat1[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            scanf("%d", &val);
            printf("%d", mat1[i][j] + val);
            if (j < n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++) {
        free(mat1[i]);
    }
    free(mat1);

    return 0;
}