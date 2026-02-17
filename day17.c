#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    int val, max, min;
    scanf("%d", &val);
    max = val;
    min = val;

    for (int i = 1; i < n; i++) {
        scanf("%d", &val);
        if (val > max) {
            max = val;
        }
        if (val < min) {
            min = val;
        }
    }

    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}