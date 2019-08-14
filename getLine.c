#include <stdio.h>


int getLine(char line[], int maxline)
{
    char c;
    int i;
    for (i = 0; i < maxline - 1 && (c = getchar()) != '\n' && c != EOF; i++) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}
