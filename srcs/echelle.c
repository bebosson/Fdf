/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echelle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:49:34 by bebosson          #+#    #+#             */
/*   Updated: 2019/07/21 21:18:57 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	set_echelle(t_win *display, int *echelle)
{
	display->echelle_max = 1;
	*echelle = 1;
	if (display->iso == 1)
	{
		*echelle = 4;
		display->echelle_max = 4;
	}
}

void	fix_nbr_pt(t_win *display)
{
	int	max;
	int	min;
	int echelle;

	max = ft_relier_halid(display);
	min = ft_relier_valid(display);
	display->echelle = 1;
	if (max < min)
		max = min;
	if (max > 10000)
	{
		display->nbr_print = 4000;
		set_echelle(display, &echelle);
	}
	else
	{
		display->nbr_print = max;
		display->echelle_max = 1;
		echelle = 1;
	}
	ft_echelle(&display, echelle);
}

int		test_echelle(t_win *display)
{
	if (ft_relier_halid(display) < display->nbr_print && ft_relier_valid(display) < display->nbr_print)
		return (0);
	else
		return (1);
}

void	ft_echelle(t_win **display, float echelle)
{
	t_point *tmp;

	if ((*display)->echelle == 0)
		(*display)->echelle = 1;
	(*display)->echelle *= echelle;
	tmp = (*display)->tpoint;
	while (tmp->next)
	{
		tmp->x *= echelle;
		tmp->y *= echelle;
		tmp = tmp->next;
	}
}
