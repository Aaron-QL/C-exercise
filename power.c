#include <stdio.h>

int power(int x, int y)
{
    int p = 1;
    while (y-- > 0) {
        p *= x;
    }

    return p;
}

int main()
{
    for (int i = 0; i < 10; i++) {
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    }
}
