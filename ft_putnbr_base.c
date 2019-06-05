/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 13:24:06 by bebosson          #+#    #+#             */
/*   Updated: 2019/06/02 13:34:25 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>


void	ft_putchar(char c)
{
	write(1,&c,1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);

}

void	ft_putnbr_base(int nbr, char *base)
{
	int len;

	len = ft_strlen(base);

	if (nbr > len)
	{
		ft_putnbr_base(nbr / ft_strlen(base),base);
		ft_putchar(base[nbr % ft_strlen(base)]);
	}
}

int main(int argc, char **av)
{
	ft_putnbr_base(atoi(av[1]),av[2]);
}
