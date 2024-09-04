#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*result;

	if (min >= max)
        return 0;
	i = max - min;
	result = (int *)malloc(sizeof(int) * (i));
    if(!result)
        return result;
	i = 0;
	while (max > min)
		result[i++] = min++;
	return result;
}