#include <stdio.h>
#include "../common/atoi.c"

#define MAXLINE 10
#define TAB 8

char line[MAXLINE];

int explodeTab(int index);
int findBlank(int index);
int newIndex(int index);
void printLn(int index);

int main() {
    int index = 0;
    char c;
    while ((c = getchar()) != EOF) {
        line[index] = c;
        if (c == '\t') {
            index = explodeTab(index);
        } else if (c == '\n') {
            printLn(index);
            index = 0;
        } else if (++index >= MAXLINE) {
            index = findBlank(index);
            printLn(index);
            index = newIndex(index);
        }
    }
}

void printLn(int index) {
    for (int i = 0; i < index; i++) {
        putchar(line[i]);
    }
    if (index > 0) {
        putchar('\n');
    }
}

int explodeTab(int index) {
    line[index] = ' ';
    for (++index; index < MAXLINE && index % TAB != 0; index ++) {
        line[index] = ' ';
    }
    if (index < MAXLINE) {
        return index;
    } else {
        printLn(index);
        return 0;
    }
}

int findBlank(int index) {
    while (index > 0 && line[index] != ' ') {
        index--;
    }
    if (index == 0) {
        return MAXLINE;
    } else {
        return index + 1;
    }
}

int newIndex(int index) {
    if (index <= 0 || index >= MAXLINE) {
        return 0;
    }

    int i = 0, j = index;
    while (j < MAXLINE) {
        line[i++] = line[j++];
    }

    return i;
}