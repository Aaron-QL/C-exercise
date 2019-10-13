#include <stdio.h>
#include "../common/getLine.c"


int atoi(char s[])
{
    int n = 0;
    for (int i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
        n = n * 10 + s[i] - '0';
    }
    return n;
}

int main() {
    char str[100];
    getLine(str, 100);
    printf("%d\n", atoi(str));
}
