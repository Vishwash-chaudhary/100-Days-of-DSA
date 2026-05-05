#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

// sort by start time
int cmp(const void *a, const void *b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // sort intervals
    qsort(arr, n, sizeof(Interval), cmp);

    Interval result[n];
    int idx = 0;

    result[0] = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= result[idx].end) {
            // overlap → merge
            if (arr[i].end > result[idx].end)
                result[idx].end = arr[i].end;
        } else {
            // no overlap → move to next slot
            idx++;
            result[idx] = arr[i];
        }
    }

    // print merged intervals
    for (int i = 0; i <= idx; i++) {
        printf("%d %d\n", result[i].start, result[i].end);
    }

    return 0;
}