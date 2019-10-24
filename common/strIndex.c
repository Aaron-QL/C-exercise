#include <stdio.h>

int strIndex(char s[], char t[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (k = 0, j = i; t[k] == s[j] && t[k] != '\0'; k++) {
            j ++;
        }
        if (t[k] == '\0') {
            return i;
        }
    }

    return -1;
}