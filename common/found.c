#include <stdio.h>

#include "my_getline.c"
#include "strIndex.c"

const int MAXLINE = 100;
char TARGET[] = "tt";

int main() {
    int i = 0;
    char line[MAXLINE];
    while (getLine(line, MAXLINE) > 0) {
        if (strIndex(line, TARGET) != -1) {
            printf("%s", line);
            i++;
        }
    }

    return i;
}