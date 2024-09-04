#include <stdlib.h>

int		print(int nb, char *str, char *result, int index)
{
	unsigned int	nbr;
	unsigned int	str_length;

	str_length = 0;
	while (str[str_length])
		str_length++;
	if (nb < 0)
	{
		result[index++] = '-';
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr >= str_length)
		print(nbr / str_length, str, result, index - 1);
	result[index] = str[nbr % str_length];
	return (index);
}

int		get_length(int number, char *base)
{
	int	length;
	int	base_length;

	base_length = -1;
	while (base[++base_length])
	length = 0;
	while (number >= base_length)
	{
		++length;
		number /= base_length;
	}
	return (++length);
}

int		get_nb(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i] && base[i] != c)
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int	s;
	int	i;
	int	res;
	int	negative;
	int	base_length;

	base_length = -1;
	while (base[++base_length])
	s = 0;
	while (str[s] != '\0' && (str[s] == ' ' || str[s] == '\t' || str[s] == '\r'
				|| str[s] == '\n' || str[s] == '\v' || str[s] == '\f'))
		s++;
	i = s - 1;
	res = 0;
	negative = 1;
	while (str[++i] && (((str[i] == '-' || str[i] == '+') && i == s) ||
				(str[i] != '-' && str[i] != '+')))
		if (str[i] == '-')
			negative = -1;
		else if (str[i] != '+')
			res = (res * base_length) + (get_nb(str[i], base));
	return (res * negative);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char			*result;
	int				number;
	int				last_index;

	if (!nbr || !base_from || !base_to)
		return (0);
	number = ft_atoi_base(nbr, base_from);
	result = malloc(sizeof(char) * get_length(number, base_to));
	last_index = print(number, base_to, result,
		get_length(number, base_to) - 1);
	result[last_index + 1] = '\0';
	return (result);
}