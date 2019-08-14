#include <stdio.h>
//#include "getLine.c"

extern int ac;

//
//#define MAXLINE 100
//
//int getLine(char line[], int maxline);
//void copy(char to[], char from[]);

int main() {
    ac = 1;
    printf("%d\n", ac);
//    int len;
//    int max = 0;
//    char line[MAXLINE];
//    char longest[MAXLINE];
//    while ((len = getLine(line, MAXLINE)) != 0) {
//        if (len > max) {
//            copy(longest, line);
//            max = len;
//        }
//    }
//
//    printf("%s", longest);
    return 0;
}

void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}