int strlen(char *str)
{
    int n;
    for (n = 0; *str != '\0'; str++) {
        n++;
    }
    return n;
}