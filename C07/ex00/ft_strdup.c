#include <stdlib.h>

char *ft_strdup(char *src)
{
    int i;
    char *dest;

    i = -1;
    while(src[++i]);
    dest = malloc(i + 1);
    i = -1;
    while(src[++i]) dest[i] = src[i];
    return dest;
}