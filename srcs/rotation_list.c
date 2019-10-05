/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:22:16 by bebosson          #+#    #+#             */
/*   Updated: 2019/10/05 17:08:33 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	r_list_z(t_win *data, float angle)
{
	t_point *tmp;

	data->c->r_z = 0xff88ff;
	data_borne(data);
	tmp = data->tpoint;
	while (tmp->next)
	{
		r_z(angle, &tmp->x, &tmp->y, data);
		tmp = tmp->next;
	}
}

void	r_list_x(t_win *data, float angle)
{
	t_point *tmp;

	data->c->r_x = 0xff88ff;
	data_borne(data);
	tmp = data->tpoint;
	while (tmp->next)
	{
		r_x(angle, &tmp->y, &tmp->z, data);
		tmp = tmp->next;
	}
}

void	r_list_y(t_win *data, float angle)
{
	t_point *tmp;

	data->c->r_y = 0xff88ff;
	data_borne(data);
	tmp = data->tpoint;
	while (tmp->next)
	{
		r_y(angle, &tmp->z, &tmp->x, data);
		tmp = tmp->next;
	}
}

void	ft_trace(t_win *data)
{
	ft_relier_h2(data);
	ft_relier_v2(data);
}
