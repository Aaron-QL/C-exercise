#include <stdio.h>

#define YES 1
#define NO 0

int htoi(char s[]);

int main(int argc, char **argv)
{
    printf("%d\n", argc);

    printf("%s\n", argv[1]);

    printf("%d\n", htoi(argv[1]));
}


int htoi(char s[])
{
    int i = 0;
    if (s[i] == '0') {
        i++;
        if (s[i] == 'x' || s[i] == 'X') {
            i++;
        }
    }

    int n = 0, index = YES, hexdigit;
    for(; index == YES; i++) {
        if ((hexdigit = s[i]) >= '0' && hexdigit <= '9') {
            hexdigit = hexdigit - '0';
        } else if (hexdigit >= 'a' && hexdigit <= 'f') {
            hexdigit = hexdigit - 'a' + 10;
        } else if (hexdigit >= 'A' && hexdigit <= 'F') {
            hexdigit = hexdigit - 'A' + 10;
        } else {
            index = NO;
        }
        if (index == YES) {
            n = n * 16 + hexdigit;
        }
    }
    return n;
}