#include <ctype.h>
#include "../common/ch.c"

int getword(char *word, int limit)
{
    int c, *w = word;
    while (isspace(c = getch())) {

    }

    if (c != EOF) {
        *w++ = c;
    }

    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for (; --limit > 0; w++) {
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}