#include <stdio.h>
#include <string.h>
#include "my_getline.c"

#define MAXLINE 1000
int my_getline(char *line, int max);

int main(int argc, char *argv[])
{
    int found = 0;
    char *line;
    if (argc != 2) {
        printf("Usage: find pattern\n");
        return -1;
    }
    while (my_getline(line, MAXLINE) > 0) {
        if (strstr(line, argv[1]) != NULL) {
            printf("%s", line);
            found++;
        }
    }
    return found;
}