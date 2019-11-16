#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31) {
        printf("param invalid\n");
        return -1;
    }
    char *p, leap;
    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    p = daytab[leap];
    while (--month) {
        day += *++p;
    }
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    if (year < 1 || yearday < 1 || yearday > 365) {
        printf("param invalid\n");
        return;
    }
    char *p, leap;
    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    p = daytab[leap];
    while (yearday > *++p) {
        yearday -= *p;
    }
    *pmonth = p - *(daytab + leap);
    *pday = yearday;

}

int main()
{
    int i = day_of_year(2019, 2, 31);
    printf("%d\n", i);


    int m = 0;
    int d = 0;
    int *pm = &m;
    int *pd = &d;
    month_day(2019, 60, pm, pd);
    printf("%d %d \n", *pm, *pd);
}