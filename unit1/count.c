#include <stdio.h>

int main()
{
    char c, previous;

    previous = 0;

    while ((c = getchar()) != EOF)
    {
        if ((c == ' ') && (previous == c)) {
            continue;
        }
        putchar(c);
        previous = c;
    }
}