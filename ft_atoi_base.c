/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 17:26:56 by juepee-m          #+#    #+#             */
/*   Updated: 2018/06/12 18:42:20 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int		index_base(char c, char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int		check_base(char *base)
{
	int			j;
	int			k;
	int			check;
	char		*cp_base;

	j = -1;
	if (ft_strlen(base) < 2)
		return (0);
	cp_base = base;
	while (base[++j])
	{
		check = 0;
		k = -1;
		while (cp_base[++k])
		{
			if (cp_base[k] == base[j])
				check++;
		}
		if (check != 1)
			return (0);
	}
	return (1);
}

static int		check_str(char *str, char *base)
{
	int			i;
	size_t		check;

	i = -1;
	check = 0;
	while (str[++i])
		if (str[i] == '+' || str[i] == '-' || index_base(str[i], base) >= 0)
			check++;
	return ((check == ft_strlen(str)) ? 1 : 0);
}

int				ft_atoi_base(char *str, char *base)
{
	int			i;
	int			result;
	int			neg;
	int			len_base;

	i = 0;
	result = 0;
	len_base = ft_strlen(base);
	if (!check_base(base) || !check_str(str, base))
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		neg = 1;
		if (str[i] == '-')
			neg = -neg;
		i++;
	}
	while (index_base(str[i], base) >= 0)
	{
		result = result * len_base + index_base(str[i], base);
		i++;
	}
	return (neg ? result : -result);
}
