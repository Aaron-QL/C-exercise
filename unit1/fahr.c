//
// Created by akaQin on 2019-08-08.
//

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
    int fahr, celsius;

    fahr = UPPER;
    while (fahr >= LOWER) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr -= STEP;
    }
}