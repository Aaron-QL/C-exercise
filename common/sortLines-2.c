#include <stdio.h>
#include <string.h>
#include "my_getline.c"
#include "alloc.c"

//能处理的最大行数量
#define MAXLINES 1000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int maxlines);

void qsort(char *lineptr[], int left, int right);

int main()
{

}

#define MAXLEN 1000 //每个问本行最大长度
int my_getline(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines)
{
}


void writelines(char *lineptr[], int nlines)
{
}

void qsort(char *v[], int left, int right)
{
}

void swap(char *v[], int i, int j)
{
}