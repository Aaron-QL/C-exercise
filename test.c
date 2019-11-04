#include <stdio.h>

#include "common/strend.c"

int main() {
    char *s = "asd";
    char *t = "";
    printf("%d\n", strend(s, t));
}