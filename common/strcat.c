void m_strcat(char *s, char *t)
{
    while (*s) {
        s++;
    }
    while ((*s++ = *t++)) {
    }
}