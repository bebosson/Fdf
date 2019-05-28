/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 19:05:50 by bebosson          #+#    #+#             */
/*   Updated: 2019/05/28 18:17:11 by bebosson         ###   ########.fr       */
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
		tmp = tmp->next;
	}
//	free(tmp);
}

void	display_max(t_win **display)
{
	float x_max;
	float y_max;
	t_point *tmp;

	tmp = (*display)->tpoint;
	x_max = tmp->x;
	y_max = tmp->y;
	while (tmp->next)
	{
		if (x_max <= tmp->x && tmp->z)
			x_max = tmp->x;
		if (y_max <= tmp->y && tmp->z)
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
		if (x_min >= tmp->x)
			x_min = tmp->x;
		if (y_min >= tmp->y)
			y_min = tmp->y;
		tmp = tmp->next;
	}
	(*display)->x_min = x_min;
	(*display)->y_min = y_min;
}

void		display_point(t_point *tmp)
{
	printf("x = %.5f / ", tmp->x);
	printf("y = %.5f / ", tmp->y);
	printf("z = %.5f / ", tmp->z);
	printf("coor_x = %d /", tmp->coor_x);
	printf("coor_y = %d / ",tmp->coor_y);
	printf("couleur = %d / \n", tmp->couleur);
}

void		display_borne(t_win *display)
{
	printf("x_max = %.5f \n",display->x_max);
	printf("y_max = %.5f \n",display->y_max);
	printf("x_min = %.5f \n",display->x_min);
	printf("y_min = %.5f \n",display->y_min);
}

void		display_repere(t_win *display)
{
	t_point *tmp;

	tmp = display->tpoint;
	display_max(&display);
	display_min(&display);
	while (tmp->next)
	{
		display_point(tmp);
		tmp = tmp->next;
	}
	display_borne(display);
}
