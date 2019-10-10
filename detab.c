#include <stdio.h>

int main() {
    char c;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("    ");
        } else {
            putchar(c);
        }
    }
}