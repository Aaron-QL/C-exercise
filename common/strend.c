int strend(char *s, char *t)
{
    char *bs = s;
    char *bt = t;
    while (*s) {
        s++;
    }
    while (*t) {
        t++;
    }
    for (; *s == *t; s--, t--) {
        if (s == bs || t == bt) {
            break;
        }
    }
    if (*s == *t && t == bt && *s != '\0') {
        return 1;
    } else {
        return 0;
    }
}