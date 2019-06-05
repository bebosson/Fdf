/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligne_juepee.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 23:19:37 by bebosson          #+#    #+#             */
/*   Updated: 2019/06/04 20:24:18 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"


void	sup(int dx, int dy, t_win *display, int i)
{
	int		cumul;
	int		xi; //display->x_o?
	int		yi; //display->y_o?
	int p;

	xi = display->x_o;
	yi = display->y_o;
	cumul = dx / 2 ;
	while (i <= dx)
	{
		xi += display->xinc ;
		cumul += dy ;
		if (cumul >= dx)
		{
			cumul -= dx;
			yi += display->yinc;
		}
		p = (int)(yi * display->screen + xi);
		display->addr[p] = display->couleur;
		i++;
	}
}

void	inf(int dx, int dy, t_win *display, int i)
{
	int		cumul;
	int		xi;
	int		yi;
	int		p;

	xi = display->x_o;
	yi = display->y_o;
	cumul = dy / 2 ;
	while (i <= dy)
	{
		yi += display->yinc;
		cumul += dx;
		if (cumul >= dy)
		{
			cumul -= dy;
			xi += display->xinc;
		}
		p = yi * display->screen + xi;
		display->addr[p] = display->couleur;
		i++;
	}
}

void	ligne_2(t_point *pt1, t_point *pt2, t_win *display)
{
	int		dx;
	int		dy;
	int		i;

	dx = pt2->x - pt1->x;
	dy = pt2->y - pt1->y;
	display->x_o = pt1->x;
	display->y_o = pt1->y;
//	mlx_pixel_put(display->mlx,display->win_ptr_s, display->x_o, display->y_o, pt1->couleur);
	display->xinc = (dx > 0) ? 1 : -1;
	display->yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	display->couleur = pt1->couleur;
	if (dx > dy)
		sup(dx, dy, display, 1);
	else
		inf(dx, dy, display, 1);
}
