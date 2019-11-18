#include <stdio.h>
#include <string.h>
#include "my_getline.c"
#include "alloc.c"
#include "atoi.c"

//能处理的最大行数量
#define MAXLINES 1000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int maxlines, int offset);


int main(int argc, char *argv[])
{
    int n, nlines, offset;
    if (argc == 1) {
        n = 10;
    } else if (argc == 2 && (*++argv)[0] == '-') {
        n = atoi(argv[0] + 1);
    } else {
        printf("illegal1");
        return -1;
    }

    if ((nlines = readlines(lineptr, MAXLINES)) > 0) {
        offset = nlines > n ? nlines - n : 0;
        writelines(lineptr, nlines, offset);
    } else {
        printf("illegal2");
        return -1;
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


void writelines(char *lineptr[], int nlines, int offset)
{
    for (int i = offset; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}
