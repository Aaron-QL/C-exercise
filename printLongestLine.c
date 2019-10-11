#include <stdio.h>
#include "getLine.c"
#include "copy.c"

#define MAXLINE 100

int main() {
    int maxLen = 0, len;
    char longestLine[MAXLINE];
    char line[MAXLINE];
    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > maxLen) {
            copy(longestLine, line);
            maxLen = len;
        }
    }
    if (maxLen > 0) {
        printf("%s", longestLine);
    }
    return 0;
}