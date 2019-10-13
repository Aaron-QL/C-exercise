#include <stdio.h>

int getLine(char line[], int maxLine)
{
    char c;
    int i;
    for (i = 0; i < maxLine - 1 && (c = getchar()) != '\n' && c != EOF; i++) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}