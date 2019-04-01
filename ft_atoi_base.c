#include <stdlib.h>
#include "Fdf.h"


int	ft_whitespace(char const c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
			|| c == '\r' || c == '\f')
		return (1);
	return (0);
}

int		base(int c, int base)
{
	char *str = "0123456789abcdef";
	char *str2 = "0123456789ABCDEF";
	int  i = 0;

	while (i < base)
	{
		if (c == str[i] || c == str2[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int nb = 0;
	int negatif = 0;
	int	i = 0;
	while (ft_whitespace(str[i]))
		i++;
	if (str[i] == '+'	 || str[i] == '-')
	{
		if (str[i] == '-')
			negatif = 1;
		i++;
	}
	while (base(str[i], str_base) != -1)
	{
		nb = nb * str_base;
		nb = nb + base(str[i], str_base);
		i++;
	}
	if (negatif)
		return (-nb);
	return (nb);
}
