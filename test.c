#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct ab {
    int a;
    char *b;
};
int main(int argc, char *argv[])
{
    struct ab *p;
//    p = malloc(sizeof(struct ab));
    printf("%p\n", p);
    printf("%d", p == NULL);
}