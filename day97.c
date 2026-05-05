#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Meeting;

// sort by start time
int cmp(const void *a, const void *b) {
    return ((Meeting*)a)->start - ((Meeting*)b)->start;
}

// simple min heap
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] <= heap[index]) break;
        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

void heapifyDown(int heap[], int size, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index) break;

        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Meeting arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // sort by start time
    qsort(arr, n, sizeof(Meeting), cmp);

    int heap[n];  // stores end times
    int size = 0;

    // first meeting
    heap[size++] = arr[0].end;

    int maxRooms = 1;

    for (int i = 1; i < n; i++) {
        // if earliest ending meeting is done
        if (heap[0] <= arr[i].start) {
            heap[0] = arr[i].end;
            heapifyDown(heap, size, 0);
        } else {
            // need new room
            heap[size] = arr[i].end;
            heapifyUp(heap, size);
            size++;
        }

        if (size > maxRooms)
            maxRooms = size;
    }

    printf("%d\n", maxRooms);

    return 0;
}