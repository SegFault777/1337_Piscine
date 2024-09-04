#include <stdlib.h>
#include <stdio.h>

static int  ft_isspliter(char c, char spliter)
{
    if (c == spliter)
        return (1);
    return (0);
}

static int  ft_count(char *str, char spliter)
{
    int i;
    int c;

    i = 0;
    c = 0;
    while(str[i])
    {
            while(str[i] && ft_isspliter(str[i], spliter))
                i++;
            if(str[i])
                c++;
            while(str[i] && !ft_isspliter(str[i], spliter))
                i++;
    }
    return c;
}

static char *ft_allocate(char *str, char c, int *index)
{
    int     i;
    int     saved_index;
    char    *splited;

    i = 0;
    saved_index = *index;
    while (str[saved_index] && !ft_isspliter(str[saved_index], c))
    {
        saved_index++;
        i++;
    }
    splited = malloc(i + 1);
    if (!splited)
        return (NULL);
    splited[i] = '\0';
    i = 0;
    while (str[*index] && !ft_isspliter(str[*index], c))
        splited[i++] = str[(*index)++];
    return (splited);
}

static char **ft_free(char **splites, int index)
{
    while (index >= 0)
    {
        free(splites[index]);
        index--;
    }
    return (NULL);
}

char **ft_split(char const *s, char c)
{
    char    **splites;
    int     count_spiltes;
    int     i;
    int     index;

    i = 0;
    index = 0;
    count_spiltes = ft_count((char *)s, c);
    splites = malloc(sizeof(char *) * (count_spiltes + 1));
    if (!splites)
        return (NULL);
    splites[count_spiltes] = NULL;
    while (i < count_spiltes)
    {
        while (s[index] && ft_isspliter(s[index], c))
            index++;
        splites[i] = ft_allocate((char *)s, c, &index);
        if (!splites[i])
            return (ft_free(splites, i));
        i++;
    }
    return (splites);
}