/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 23:42:39 by bebosson          #+#    #+#             */
/*   Updated: 2019/10/05 17:07:16 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_coor_delta(t_win **data, int trans_x, int trans_y)
{
	t_point *tmp;

	tmp = (*data)->tpoint;
	while (tmp->next)
	{
		tmp->x += trans_x;
		tmp->y += trans_y;
		tmp = tmp->next;
	}
}

int		ft_coor_z(t_win *data, float trans)
{
	t_point *tmp;

	tmp = data->tpoint;
	while (tmp->next)
	{
		tmp->z = tmp->z * trans;
		tmp = tmp->next;
	}
	return (0);
}

void	ft_origin(t_win **data)
{
	t_point *tmp;

	tmp = (*data)->tpoint;
	while (tmp->next)
	{
		tmp->x = tmp->coor_x;
		tmp->y = tmp->coor_y;
		tmp = tmp->next;
	}
}

void	ft_origin_z(t_win **data)
{
	t_point *tmp;

	tmp = (*data)->tpoint;
	while (tmp->next)
	{
		if (tmp->z_o != 0)
			tmp->z = tmp->z_o;
		else
			tmp->z = 0;
		tmp = tmp->next;
	}
}

void	centrer(t_win **data)
{
	float delta_x;
	float delta_y;
	float sym_x;
	float sym_y;

	sym_x = (*data)->middle->x;
	sym_y = (*data)->middle->y;
	delta_x = ((*data)->scr / 2) - sym_x;
	delta_y = ((*data)->scr / 2) - sym_y;
	ft_coor_delta(data, delta_x, delta_y);
}
