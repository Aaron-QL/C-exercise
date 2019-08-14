#include <stdio.h>

int main() {
    char c;
    char space[4];
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("    ");
        } else {
            putchar(c);
        }
    }
}