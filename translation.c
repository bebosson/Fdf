/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 23:42:39 by bebosson          #+#    #+#             */
/*   Updated: 2019/03/29 22:04:00 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fdf.h"



void	ft_coor_x(t_win **display, int trans)
{
	t_point *tmp;

	tmp = (*display)->tpoint;
	while (tmp->next)
	{
		tmp->x += trans;
		tmp = tmp->next;
	}
}
void	ft_coor_y(t_win **display, int trans)
{
	t_point *tmp;

	tmp = (*display)->tpoint;
	while (tmp->next)
	{
		tmp->y += trans;
		tmp = tmp->next;
	}
}
int	ft_coor_z(t_win **display, float trans)
{
	t_point *tmp;
	t_point *tmp_2;
	
	tmp = (*display)->tpoint;
	tmp_2 = (*display)->tpoint;
	while (tmp->next)
	{
		if (tmp->z != 0)
			tmp->z *= trans;
		tmp = tmp->next;
	}
	while (tmp_2->next)
	{
		if (tmp_2->z < 1 && tmp_2->z > 0)
		{
			(*display)->z *= -20;
			ft_coor_z(display,(*display)->z);
			return (1);
			//tmp_2 = tmp_2->next;
		}
		if (tmp_2->z > -1 && tmp_2->z < 0)
		{
			(*display)->z *= -20;
			ft_coor_z(display,(*display)->z);
			return (1);
			//	tmp_2->z *= 10;
		//	tmp_2 = tmp_2->next;
		}
		tmp_2 = tmp_2->next;
	}
	return (0);
}

void	centrer(t_win **display)
{
	float delta_x;
	float delta_y;
	float sym_x;
	float sym_y;

	display_min(display);
	display_max(display);
	sym_x = ((*display)->x_max + (*display)->x_min) / 2;
	sym_y = ((*display)->y_max + ((*display)->y_min)) / 2;
	delta_x = ((*display)->screen / 2) - sym_x;
	delta_y = ((*display)->screen / 2) - sym_y;
	ft_coor_y(display,delta_y);
	ft_coor_x(display,delta_x);
}
