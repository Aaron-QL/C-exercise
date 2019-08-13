#include <stdio.h>

#define MAXLINE 100
int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len;
    int max = 0;
    char line[MAXLINE];
    char longest[MAXLINE];
    while ((len = getLine(line, MAXLINE)) != 0) {
        if (len > max) {
            copy(longest, line);
            max = len;
        }
    }

    printf("%s", longest);
    return 0;
}

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

void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}