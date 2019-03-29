/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 19:05:50 by bebosson          #+#    #+#             */
/*   Updated: 2019/03/29 18:01:23 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fdf.h"

void	ft_echelle(t_win **display, float echelle)
{
	t_point *tmp;

	tmp = (*display)->tpoint;
	while (tmp->next)
	{
		tmp->x *= echelle;
		tmp->y *= echelle;
//		tmp->z *= echelle;
		tmp = tmp->next;
	}
}

void	display_max(t_win **display)
{
	float x_max;
	float y_max;
	t_point *tmp;

	tmp = (*display)->tpoint;
//	x_max = 0;
//	y_max = 0;
	x_max = tmp->x;
	y_max = tmp->y;
	while (tmp->next)
	{
		if (x_max <= tmp->x && tmp->z == 0)
			x_max = tmp->x;
		if (y_max <= tmp->y && tmp->z == 0)
			y_max = tmp->y;
		tmp = tmp->next;
	}
	(*display)->x_max = x_max;
	(*display)->y_max = y_max;
}

void	display_min(t_win **display)
{
	float x_min;
	float y_min;
	t_point *tmp;

	tmp = (*display)->tpoint;
	x_min = tmp->x;
	y_min = tmp->y;
	while (tmp->next)
	{
		if (x_min >= tmp->x && tmp->z == 0)
			x_min = tmp->x;
		if (y_min >= tmp->y && tmp->z == 0)
			y_min = tmp->y;
		tmp = tmp->next;
	}
	(*display)->x_min = x_min;
	(*display)->y_min = y_min;
}

