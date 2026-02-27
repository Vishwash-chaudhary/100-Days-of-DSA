#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    long long val_a = *(long long*)a;
    long long val_b = *(long long*)b;
    if (val_a < val_b) return -1;
    if (val_a > val_b) return 1;
    return 0;
}

int main() {
    int n;
    
    if (scanf("%d", &n) != 1) return 0;
    
    long long *pref = (long long*)malloc(n * sizeof(long long));
    long long sum = 0;
    long long total_zero_subarrays = 0;

    for (int i = 0; i < n; i++) {
        long long val;
        scanf("%lld", &val);
        sum += val;
        pref[i] = sum;
        
        if (sum == 0) {
            total_zero_subarrays++;
        }
    }

    qsort(pref, n, sizeof(long long), compare);

    long long frequency = 1;
    for (int i = 1; i < n; i++) {
        if (pref[i] == pref[i-1]) {
            frequency++;
        } else {
            total_zero_subarrays += (frequency * (frequency - 1)) / 2;
            frequency = 1;
        }
    }
    total_zero_subarrays += (frequency * (frequency - 1)) / 2;

    printf("%lld\n", total_zero_subarrays);

    free(pref);
    return 0;
}