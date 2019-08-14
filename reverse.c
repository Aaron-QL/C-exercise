#include <stdio.h>
#include "getLine.c"

#define MAXLINE 1000

int main() {
    char line[MAXLINE];

    int last = getLine(line, MAXLINE) - 1;


    char target[last];

    for (int i = 0; i < last; i++) {
        target[i] = line[last - i - 1];
    }
    target[last] = '\0';

    printf("%d\n", last);
    printf("%s\n", target);
}