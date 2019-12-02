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
        {"a", 0},
        {"b", 0}
};

struct key *binsearch(char *, struct key *, int);

int main()
{
    struct key *p;
    char word[MAXWORD];
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            if ((p = binsearch(word, keytab, NKEYS)) != NULL) {
                p->count++;
            }
        }
    }
    printf("print:\n");
    for (p = keytab; p < keytab + NKEYS; p++) {
        if (p->count > 0) {
            printf("%4d %s\n", p->count, p->word);
        }
    }

    return 0;
}

struct key *binsearch(char *word, struct key tab[], int n)
{
    int cond;
    struct key *low = &tab[0], *high = &tab[n - 1], *mid;
    while (low <= high) {
        mid = low + (high - low) / sizeof(struct key);
        if ((cond = strcmp(word, mid->word)) < 0) {
            high = mid;
        } else if (cond > 0) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return NULL;
}
