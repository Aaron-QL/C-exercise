#include <stdio.h>

int my_getline(char line[], int maxLine)
{
    int c, i;
    i = 0;
    while (--maxLine > 0 && (c = getchar()) != '\n' && c != EOF) {
        line[i++] = c;
    }
    if (c == '\n') {
        line[i++] = c;
    }
    line[i] = '\0';
    return i;
}