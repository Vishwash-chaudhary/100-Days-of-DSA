#include <stdio.h>

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) {
        return 1;
    }

    long long sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            scanf("%d", &val);
            if (i == j) {
                sum += val;
            }
        }
    }

    printf("%lld\n", sum);

    return 0;
}