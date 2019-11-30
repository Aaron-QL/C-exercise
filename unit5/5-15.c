#include <stdio.h>
#include <string.h>
#include "../common/my_getline.c"
#include "../common/alloc.c"
#include "../common/my_numcmp.c"
#include "../common/my_strcmp.c"
#include "../common/my_charcmp.c"

//能处理的最大行数量
#define NUMERIC 1
#define DECR 2
#define FOLD 4
#define MAXLINES 1000
#define MAXLEN 1000 //每个问本行最大长度

static char option = 0;

char *lineptr[MAXLINES];
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int maxlines, int decr);
void my_qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int my_numcmp(char *, char *);
int my_strcmp(char *, char *);
int my_charcmp(char *, char *);
char *alloc(int);
int my_getline(char *, int);

int main(int argc, char *argv[])
{
    int nlines;
    char c, rc = 0;

    while (--argc > 0 && (*++argv)[0] == '-') {
        while ((c = *++argv[0])) {
            switch (c) {
                case 'f':
                    option |= FOLD;
                    break;
                case 'n':
                    option |= NUMERIC;
                    break;
                case 'r':
                    option |= DECR;
                    break;
                default:
                    printf("sort: illegal option %c\n", c);
                    argc = 1;
                    rc = 1;
                    break;
            }
        }
    }

    if (argc) {
        printf("Usage: sort -fnr \n");
    } else {
        if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
            if (option & NUMERIC) {
                my_qsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))my_numcmp);
            } else if (option & FOLD) {
                my_qsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))my_charcmp);
            } else {
                my_qsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))my_strcmp);
            }

            writelines(lineptr, nlines, option & DECR);
        } else {
            printf("input too big to sort\n");
            rc = -1;
        }
    }

    return rc;

}

int readlines(char *lineptr[], int maxlines)
{
    int nlines = 0, len;
    char line[MAXLEN], *p;
    while ((len = my_getline(line, MAXLEN)) > 0) {
        if (nlines > MAXLINES || (p = alloc(len)) == NULL) {
            return -1;
        }
        line[len - 1] = '\0';
        strcpy(p, line);
        lineptr[nlines++] = p;
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines, int decr)
{
    if (decr) {
        char **p;
        p = lineptr + nlines;
        while (nlines-- >0) {
            printf("%s\n", *--p);
        }
    } else {
        while (nlines-- > 0) {
            printf("%s\n", *lineptr++);
        }
    }
}

void my_qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);
    if (left >= right) {
        return;;
    }
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if ((*comp)(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    my_qsort(v, left, last - 1, comp);
    my_qsort(v, last + 1, right, comp);
}

void swap(void *v[], int i, int j)
{
    char * temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}