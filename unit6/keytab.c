#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../common/getword.c"

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof (keytab[0]))

struct key {
    char *word;
    int count;
} keytab[] = {
    "a", 0,
    "b", 0,
    "c", 0
};

int getword(char *, int);
int binsearch(char *, struct key *, int);

int main()
{
    int n;
    char word[MAXWORD];
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            if ((n = binsearch(word, keytab, NKEYS)) >= 0) {
                keytab[n].count++;
            }
        }
    }
    printf("print:\n");
    for (n = 0; n < NKEYS; n++) {
        if (keytab[n].count > 0) {
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
        }
    }

    return 0;
}

int binsearch(char *word, struct key tab[], int n)
{
    int low = 0, high = n - 1, mid, cond;

    while (low <= high) {
        mid = (low + high) / 2;
        cond = strcmp(word, tab[mid].word);
        if (cond > 0) {
            low = mid + 1;
        } else if (cond < 0) {
            high = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}
