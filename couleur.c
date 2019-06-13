/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   couleur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 19:20:33 by bebosson          #+#    #+#             */
/*   Updated: 2019/06/13 01:24:40 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	fix_couleur(t_win **display)
{
	t_point	*tmp;

	tmp = (*display)->tpoint;
	while(tmp->next)
	{
		tmp->r = 155;
		tmp->g = 30;
		tmp->b = 50;
		if (tmp->z != 0)
			tmp->b = 250 - tmp->g;
		tmp->couleur = ft_rgb(tmp->r,tmp->g,tmp->b);
		tmp = tmp->next;
	}
}


void	change_couleur_point(t_win **display, int r, int g, int b)
{
	t_point	*tmp;

	tmp = (*display)->tpoint;
	while(tmp->next)
	{
		tmp->r += r;
		tmp->g += g;
		tmp->b += b;
		if (tmp->z && tmp->b < 255)
			tmp->b += 250 - tmp->g;
		tmp->couleur = ft_rgb(tmp->r,tmp->g,tmp->b);
		tmp = tmp->next;
	}
}

static	int		ft_power(int nbr, int pwr)
{
	int i;
	int result;

	if (pwr == 0)
		return (1);
	if (pwr == 1)
		return (nbr);
	if (pwr > 1)
		return (nbr * ft_power(nbr, pwr - 1));
	return (result);
}

int		ft_rgb(int r, int g, int b)
{
	int i;
	int divide;
	int result;

	//result = b; 
	//result += ft_power(16,2) * g % 16;
	//result += ft_power(16,3) * g / 16;
	//result += ft_power(16,4) * r % 16;
	//result += ft_power(16,5) * r / 16;
	return ((r << 16) | (g << 8) | b);
}


