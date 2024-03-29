#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../common/strdup.c"

#define HASHSIZE 101

struct nlist {
    struct nlist *next;
    char *name;
    char  *defn;
};

struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++) {
        hashval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    {
        if (strcmp(s, np->name) == 0) {
            return np;
        }
    }
    return NULL;
}

struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL) {
        np = (struct nlist*)malloc(sizeof(struct nlist));
        if (np == NULL || (np->name = strdump(name)) == NULL) {
            return NULL;
        }
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else {
        free((void *) np->defn);
    }
    if ((np->defn = strdump(defn)) == NULL) {
        return NULL;
    }
    return np;
}

void listprint()
{
    struct nlist *np;
    for (int i = 0; i < HASHSIZE; i++) {
        np = hashtab[i];
        while (np != NULL) {
            printf("%s : %s\n", np->name, np->defn);
            np = np->next;
        }
    }
}

void undef(char *name)
{
    unsigned hashval = hash(name);
    struct nlist *np, *prev;
    for (np = hashtab[hashval]; np != NULL; np = np->next) {
        if (strcmp(name, np->name) == 0) {
            break;
        }
        prev = np;
    }
    if (np == NULL) {
        return;
    }
    if (prev == NULL) {
        hashtab[hashval] = np->next;
    } else {
        prev->next = np->next;
    }
    free((void *) np->name);
    free((void *) np->defn);
    free((void *) np);
}

int main() {

}