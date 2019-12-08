#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100

void filecmp(FILE *, FILE *);

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: diff a.file b.file\n");
        exit(1);
    }

    FILE *fp1, *fp2;

    if ((fp1 = fopen(*++argv, "r")) == NULL) {
        fprintf(stderr, "open %s failed\n", *argv);
        exit(2);
    } else if ((fp2 = fopen(*++argv, "r")) == NULL) {
        fprintf(stderr, "open %s failed\n", *argv);
        exit(2);
    } else {
        filecmp(fp1, fp2);
        fclose(fp1);
        fclose(fp2);
        exit(0);
    }
}

void filecmp(FILE *fp1, FILE *fp2)
{
    char line1[MAXLINE], line2[MAXLINE];
    char *lp1, *lp2;

    do {
        lp1 = fgets(line1, MAXLINE, fp1);
        lp2 = fgets(line2, MAXLINE, fp2);
        if (lp1 == line1 && lp2 == line2) {
            if (strcmp(line1, line2) != 0) {
                printf("difference:\n");
                printf("%s", line1);
                printf("%s", line2);
            }
        } else if (lp1 != line1 && lp2 == line2) {
            printf("file1 to end\n");
            break;
        } else if (lp1 == line1 && lp2 != line2) {
            printf("file2 to end\n");
            break;
        }
    } while (lp1 == line1 && lp2 == line2);

}