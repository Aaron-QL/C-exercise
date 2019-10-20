#include <stdio.h>

void inComment(char c);
void readComment(char c);

int main() {
    char c;
    while ((c = getchar()) != EOF) {
        readComment(c);
    }
}

void readComment(char c)
{
    char d;
    d = getchar();
    if (c == '/' && (d == '/' || d == '*')) {
        if () {

        }
    }

    readComment(d);
}

void inComment(char c)
{
}