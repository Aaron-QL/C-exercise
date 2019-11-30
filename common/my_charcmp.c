#include <ctype.h>

int my_charcmp(char *s1, char *s2)
{
    for(; tolower(*s1) == tolower(*s2); s1++, s2++) {
        if (*s1 == '\0') {
            return 0;
        }
    }
    return tolower(*s1) - tolower(*s2);
}