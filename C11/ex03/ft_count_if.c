#include <stdlib.h>

int ft_count_if(char **tab, int length, int(*f)(char*))
{
    int i;
    int *res;
    int count;

    i = -1;
    count = 0;
    while(tab[++i])
    {
        res = f(tab[i]);
        if(*res != 0) count++;
    }
    return count;
}