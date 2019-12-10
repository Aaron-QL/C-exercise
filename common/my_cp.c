#include <stdio.h>
#include <fcntl.h>

#define BUFSIZE 100
#define PERMS 0666

main(int argc, char *argv[])
{
    int f1, f2, n;
    char buf[BUFSIZE];
    if (argc != 3) {

    }
    if ((f1 = open(argv[1], O_RDONLY, 0)) == -1) {

    }
    if ((f2 = create(argv[2], PERMS)) == -1) {

    }
    while ((n = read(f1, buf, BUFSIZE)) > 0) {
        if (write(f2, buf, n) != n) {

        }
    }

    return 0;
}