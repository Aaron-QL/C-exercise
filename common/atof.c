#include <ctype.h>

double atof(char s[])
{
    double val;
    int i, power, sign;
    for (i = 0; isspace(s[i]); i++) {

    }
    sign = s[i] == '-' ? -1 : 1;
    if (s[i] == '-' || s[i] == '+') {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++) {
        val = val * 10 + s[i] - '0';
    }
    if (s[i] == '.') {
        i++;
    }
    for (power = 1; isdigit(s[i]); i++) {
        val = val * 10 + s[i] - '0';
        power *= 10;
    }

    return val * sign / power;
}