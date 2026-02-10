#include <stdio.h>

long long power(int base, int exp) {
    if (exp == 0) {
        return 1;
    }
    return base * power(base, exp - 1);
}

int main() {
    int a, b;
    
    if (scanf("%d %d", &a, &b) != 2) {
        return 1;
    }
    
    printf("%lld\n", power(a, b));
    
    return 0;
}