#include <stdio.h>

static int tab[][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main() {
    int d, *pmonth, *pday;
    d = day_of_year(2019, 11, 23);
    int month = 0;
    int day = 0;
    int *pm = &month;
    int *pd = &day;
    month_day(2019, 66, pm, pd);
    printf("%d %d \n", *pm, *pd);
}

int day_of_year(int year, int month, int day)
{
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        return 0;
    }

    int leap, *p;
    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    p = tab[leap];
    while (--month) {
        day += *++p;
    }

    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    if (yearday < 1 || yearday > 366) {
        return;
    }
    int leap, *p;
    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    p = tab[leap];
    while (yearday > *++p) {
        yearday -= *p;
    }

//    两种写法都可以
//    *pmonth = p - tab[leap];
    *pmonth = p - *(tab+leap);
    *pday = yearday;
}