#include <stdio.h>
#include <string.h>

int main() {
    char str[1001];

    if (scanf("%s", str) != 1) {
        return 0;
    }

    int left = 0;
    int right = strlen(str) - 1;
    int isPalindrome = 1;

    while (left < right) {
        if (str[left] != str[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}