/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:08:53 by bebosson          #+#    #+#             */
/*   Updated: 2019/10/05 18:11:10 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	iso_list(t_win *data)
{
	t_point *tmp;

	tmp = data->tpoint;
	while (tmp->next)
	{
		trans_iso(&tmp->x, &tmp->y, tmp->z);
		tmp = tmp->next;
	}
}

void	trans_iso(float *x, float *y, int z)
{
	float x_i;
	float y_i;

	x_i = 0.707 * (*x - *y);
	y_i = -(-0.707 * sin(0.4) * (*x + *y) + cos(0.4) * (z));
	*x = x_i;
	*y = y_i;
}
