/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligne.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 18:59:20 by bebosson          #+#    #+#             */
/*   Updated: 2019/10/05 18:10:16 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	sup(int dx, int dy, t_win *data, int i)
{
	int	cumul;
	int	xi;
	int	yi;
	int p;

	xi = data->x_o;
	yi = data->y_o;
	cumul = dx / 2;
	while (i <= dx)
	{
		xi += data->xinc;
		cumul += dy;
		if (cumul >= dx)
		{
			cumul -= dx;
			yi += data->yinc;
		}
		p = yi * data->scr + xi;
		if (p < X_W && p >= 0)
			data->addr[p] = data->c_on;
		i++;
	}
}

void	inf(int dx, int dy, t_win *data, int i)
{
	int		cumul;
	int		xi;
	int		yi;
	int		p;

	xi = data->x_o;
	yi = data->y_o;
	cumul = dy / 2;
	while (i <= dy)
	{
		yi += data->yinc;
		cumul += dx;
		if (cumul >= dy)
		{
			cumul -= dy;
			xi += data->xinc;
		}
		p = yi * (data->scr) + xi;
		if (p < X_W && p >= 0)
			data->addr[p] = data->c_on;
		i++;
	}
}

void	ligne_2(t_point *pt1, t_point *pt2, t_win *data)
{
	int		dx;
	int		dy;

	dx = pt2->x - pt1->x;
	dy = pt2->y - pt1->y;
	data->x_o = pt1->x;
	data->y_o = pt1->y;
	data->xinc = (dx > 0) ? 1 : -1;
	data->yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	data->c_on = pt2->c;
	if (dx > dy)
		sup(dx, dy, data, 1);
	else
		inf(dx, dy, data, 1);
}
