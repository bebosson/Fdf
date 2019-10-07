/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echelle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:49:34 by bebosson          #+#    #+#             */
/*   Updated: 2019/10/05 19:57:38 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	set_echelle(t_win *data, int *echelle)
{
	data->echelle_max = 1;
	*echelle = 1;
	if (data->iso == 1)
	{
		*echelle = 4;
		data->echelle_max = 4;
	}
}

void	fix_nbr_pt(t_win *data)
{
	int	max;
	int	min;
	int echelle;

	max = ft_relier_halid(data);
	min = ft_relier_valid(data);
	data->echelle = 1;
	if (max < min)
		max = min;
	if (max > 10000)
	{
		data->nb_p = 4000;
		set_echelle(data, &echelle);
	}
	else
	{
		data->nb_p = max;
		data->echelle_max = 1;
		echelle = 1;
	}
	ft_echelle(&data, echelle);
}

int		test_echelle(t_win *data)
{
	if (ft_relier_halid(data) < data->nb_p
			&& ft_relier_valid(data) < data->nb_p)
		return (0);
	else
		return (1);
}

void	ft_echelle(t_win **data, float echelle)
{
	t_point *tmp;

	if ((*data)->echelle == 0)
		(*data)->echelle = 1;
	(*data)->echelle *= echelle;
	tmp = (*data)->tpoint;
	while (tmp->next)
	{
		tmp->x *= echelle;
		tmp->y *= echelle;
		tmp = tmp->next;
	}
}
