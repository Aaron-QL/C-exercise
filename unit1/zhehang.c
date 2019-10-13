#include <stdio.h>
#include "../common/getLine.c"

#define MAXLINE 10
#define NEWLINE 6


int main() {
    int len;
    char line[MAXLINE];
    while ((len = getLine(line, MAXLINE)) != 0) {
        if (len < NEWLINE) {
            printf("%s", line);
            continue;
        }

        putchar(line[len-2]);
    }
}