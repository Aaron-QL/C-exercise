#include <stdio.h>

#include "common/strcat.c"

int main() {
    char s[6] = "asd";
    char *sp = s;
    char *t = "qqq";

    m_strcat(sp, t);
    printf("%s\n", s);
}