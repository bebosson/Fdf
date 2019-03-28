/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:21:59 by bebosson          #+#    #+#             */
/*   Updated: 2019/03/28 21:38:16 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"


void	ft_trace(t_win *display)
{
	mlx_clear_window(display->mlx,display->win_ptr_s);
	ft_relier_h(display);
	ft_relier_v(display);
}


void	ft_origin(t_win **display, int echelle, float angle)
{
	t_point *tmp;

	tmp = (*display)->tpoint;
	while (tmp->next)
	{
		tmp->x = tmp->coor_x;
		tmp->y = tmp->coor_y;
		tmp = tmp->next;
	}
	fix_display(display, echelle, angle);
}

void	ft_relier_h(t_win *display)
{
	t_point	*tmp_1;
	t_point	*tmp_2;

	tmp_1 = display->tpoint;
	tmp_2 = display->tpoint->next;
	while (tmp_2->next)
	{
		if (tmp_1->coor_x <  tmp_2->coor_x)
			ligne(tmp_1->x,tmp_1->y,tmp_2->x,tmp_2->y,display);
		tmp_2 = tmp_2->next;
		tmp_1 = tmp_1->next;
	}
}
void	ft_relier_v(t_win *display)
{
	t_point	*tmp_1;
	t_point	*tmp_2;

	tmp_1 = display->tpoint;
	tmp_2 = display->tpoint->next;
	while (tmp_2->coor_x != tmp_1->coor_x)
		tmp_2 = tmp_2->next;
	while (tmp_2->next)
	{
		if (tmp_1->coor_x ==  tmp_2->coor_x)
			ligne(tmp_1->x,tmp_1->y,tmp_2->x,tmp_2->y,display);
		tmp_2 = tmp_2->next;
		tmp_1 = tmp_1->next;
	}
}
