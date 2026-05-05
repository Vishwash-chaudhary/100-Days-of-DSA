#include <stdio.h>
#include <stdlib.h>

// node for linked list
typedef struct Node {
    float data;
    struct Node* next;
} Node;

// insert in sorted order (insertion sort style)
void insertSorted(Node** head, float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* curr = *head;
        while (curr->next != NULL && curr->next->data < value)
            curr = curr->next;

        newNode->next = curr->next;
        curr->next = newNode;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    // create buckets
    Node* buckets[n];
    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    // distribute elements
    for (int i = 0; i < n; i++) {
        int idx = (int)(n * arr[i]);  // bucket index
        insertSorted(&buckets[idx], arr[i]);
    }

    // concatenate
    int k = 0;
    for (int i = 0; i < n; i++) {
        Node* curr = buckets[i];
        while (curr != NULL) {
            arr[k++] = curr->data;
            curr = curr->next;
        }
    }

    // print sorted array
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    return 0;
}