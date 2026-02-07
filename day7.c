#include <stdio.h>

int fib(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Input must be non-negative.\n");
    } else {
        printf("%d", fib(n));
    }
    
    return 0;
}