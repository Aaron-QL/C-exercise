#include <stdio.h>

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

int main(int argc, char *argv[])
{
    struct point pt = {300, 200};
    struct rect screen = {pt, pt};
    printf("%d %d\n", screen.pt1.x, screen.pt2.y);
}