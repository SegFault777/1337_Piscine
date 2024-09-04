#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *s)
{
    int i;

    i = -1;
    while(s[++i]);
    return i;
}

void ft_cpy(char *d, char *s, int *index)
{
    int i;

    i = 0;
    while(s[i])
        d[(*index)++] = s[i++];
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    int i;
    int index;
    char *dest;
    int total_len;

    i = 0;
    total_len = 0;
    index = 0;
    while(i < size)
        total_len = total_len + ft_strlen(strs[i++]);
    dest = malloc(total_len + (ft_strlen(sep) * (size - 1)) + 1);
    if(!dest)
        return dest;
    i = -1;
    while(++i < size)
    {
        ft_cpy(dest, strs[i], &index);
        if(i < size - 1)
            ft_cpy(dest, sep, &index);
    }
    dest[index] = '\0';
    return dest;
}