#include <stdlib.h>

int *ft_map(int *tab, int length, int(*f)(int))
{
    int i;
    int *ret;

    i = 0;
    ret = malloc(sizeof(int) * length);
    while(i < length)
        ret[i++] = f(tab[i]);
    
    return ret;
}