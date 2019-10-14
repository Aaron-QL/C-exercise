#include <stdio.h>

int main() {
    int counter = 0;
    char c;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            counter++;
        } else {
            while (counter > 3) {
                putchar('\t');
                counter -= 4;
            }

            while (counter > 0) {
                putchar(' ');
                counter--;
            }

            putchar(c);
        }
    }
}