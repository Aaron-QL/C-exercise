#include <stdio.h>
#include <string.h>
#include "my_getline.c"

#define MAXLINE 1000
int my_getline(char *line, int max);

int main(int argc, char *argv[])
{
    int c, found = 0, lineno = 0, except = 0, number = 0;
    char line[MAXLINE];
    while (--argc > 0 && (*++argv)[0] == '-') {
        while ((c = *++argv[0])) {
            switch (c) {
                case 'n':
                    number = 1;
                    break;
                case 'x':
                    except = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
        }
    }

    if (argc != 1) {
        printf("Usage: find -x -n pattern\n");
        return -1;
    }
    while (my_getline(line, MAXLINE) > 0) {
        lineno++;
        if ((strstr(line, *argv) != NULL) != except) {
            if (number) {
                printf("%d: ", lineno);
            }
            printf("%s", line);
            found++;
        }
    }
    return found;
}