#include <stdio.h>
#include <string.h>
#include "my_getline.c"
#include "alloc.c"
#include "my_numcmp.c"
#include "my_strcmp.c"

//能处理的最大行数量
#define MAXLINES 1000
#define MAXLEN 1000 //每个问本行最大长度

char *lineptr[MAXLINES];
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int maxlines);
void my_qsort(char *lineptr[], int left, int right, int (*comp)(void *, void *));
int my_numcmp(char *, char *);
int my_strcmp(char *, char *);
char *alloc(int);

int main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0;

    if (argc == 2 && strcmp(argv[1], "-n") == 0) {
        numeric = 1;
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        my_qsort(
                lineptr,
                0,
                nlines - 1,
                (int (*)(void *, void *))(numeric ? my_numcmp : my_strcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

int reaadlines(char *lineptr[], int maxlines)
{

}

void writelines(char *lineptr[], int nlines)
{

}

int my_qsort(char *lineptr[], int left, int right, int (*comp)(void *, void *))
{

}

void swap(char *v[], int i, int j)
{
    char * temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}