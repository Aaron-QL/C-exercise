#include <stdio.h>

int main() {
    void *a = 0x7ffedff9491c;
    printf("%p\n", &a[0]);
    printf("%p\n", a);

}