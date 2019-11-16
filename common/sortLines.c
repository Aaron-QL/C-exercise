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
    int nlines; //读取的行数
    //读取所有输入行
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        //对问本行进行排序
        qsort(lineptr, 0, nlines - 1);
        //按次序打印问本行
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000 //每个问本行最大长度
int my_getline(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines = 0;
    char line[MAXLEN], *p;
    while ((len = my_getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        } else {
            line[len - 1] = '\0'; //删除结尾的换行符
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}


void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0) {
        printf("%s\n", *lineptr++);
    }
}

void qsort(char *v[], int left, int right)
{
    int i, last;
    if (left >= right) {
        return;
    }
    void swap(char *v[], int i, int j);
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}