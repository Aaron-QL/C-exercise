#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: diff a.file b.file\n");
        exit(1);
    }
    char *f1 = argv[1], *f2 = argv[2], *line1, *line2;
    FILE *fp1, *fp2;

    if ((fp1 = fopen(f1, "r")) == NULL) {
        fprintf(stderr, "open %s failed\n", f1);
        exit(2);
    }

    if ((fp2 = fopen(f2, "r")) == NULL) {
        fprintf(stderr, "open %s failed\n", f2);
        exit(2);
    }

    while ((fgets(line1, MAXLINE, fp1) != NULL)
            && (fgets(line2, MAXLINE, fp2) != NULL))
    {
        if (strcmp(line1, line2) != 0) {
            printf("%s : %s\n", f1, line1);
            printf("%s : %s\n", f2, line2);
        }
    }

    while (fgets(line1, MAXLINE, fp1) != NULL) {
        printf("%s : %s\n", f1, line1);
    }

    while (fgets(line2, MAXLINE, fp2) != NULL) {
        printf("%s : %s\n", f2, line2);
    }

    fclose(fp1);
    fclose(fp2);
    if (ferror(stdout)) {
        fprintf(stderr, "error writing stdout\n");
        exit(3);
    }

    exit(0);
}