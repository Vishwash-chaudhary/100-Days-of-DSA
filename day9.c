#include <stdio.h>

void reverse_print(char *str) {
    if (*str == '\0') {
        return;
    }
    reverse_print(str + 1);
    printf("%c", *str);
}

int main() {
    char str[1001];

    if (scanf("%s", str) == 1) {
        reverse_print(str);
        printf("\n");
    }

    return 0;
}