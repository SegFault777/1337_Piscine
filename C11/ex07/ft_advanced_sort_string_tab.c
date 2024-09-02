void ft_swap(char **a, char **b)
{
    char *tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int cmp(char *str1, char *str2)
{
    int i;

    i = 0;
    while(str1[i] && str2[i])
    {
        if(str1[i] > str2[i])
            return 1;
        i++;
    }
    return 0;
}

int ft_size(char **tab)
{
    int i;

    i = 0;
    while(tab[i++]);
    return i;
}

void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
    int i;
    int size;

    i = 1;
    size = ft_size(tab);
    while(i < size - 1)
    {
        if(cmp(tab[i], tab[i + 1]))
            ft_swap(&tab[i], &tab[i + 1]);
        i++;
    }
}