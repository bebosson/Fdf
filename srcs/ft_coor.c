/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:44:16 by bebosson          #+#    #+#             */
/*   Updated: 2019/07/21 20:38:03 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Fdf.h"

void	point_central(t_win **display)
{
	int coor_x;
	int coor_y;	
	t_point *tmp;
	t_point *tmp2;
	tmp = (*display)->tpoint;
	tmp2 = (*display)->tpoint;
	while (tmp->next)
	{
		coor_x = tmp->coor_x;
		coor_y = tmp->coor_y;
		tmp = tmp->next;
	}
	coor_x /= 2;
	coor_y /= 2;
	while (tmp2->coor_x != coor_x || tmp2->coor_y != coor_y)
		tmp2 = tmp2->next;
	(*display)->middle = tmp2;
}

void	display_max(t_win **display)
{
	float	x_max;
	float	y_max;
	float	z_max;
	t_point *tmp;

	tmp = (*display)->tpoint;
	x_max = tmp->x;
	y_max = tmp->y;
	z_max = tmp->z;
	while (tmp->next)
	{
		if (x_max <= tmp->x && tmp->z)
			x_max = tmp->x;
		if (y_max <= tmp->y && tmp->z)
			y_max = tmp->y;
		if (z_max <= tmp->z)
			z_max = tmp->z;
		tmp = tmp->next;
	}
	(*display)->x_max = x_max;
	(*display)->y_max = y_max;
	(*display)->z_max = z_max;
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
		if (x_min >= tmp->x)
			x_min = tmp->x;
		if (y_min >= tmp->y)
			y_min = tmp->y;
		tmp = tmp->next;
	}
	(*display)->x_min = x_min;
	(*display)->y_min = y_min;
}
