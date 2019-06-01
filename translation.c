/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 23:42:39 by bebosson          #+#    #+#             */
/*   Updated: 2019/06/01 19:14:41 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fdf.h"



void	ft_coor_delta(t_win **display, int trans_x , int trans_y)
{
	t_point *tmp;

	tmp = (*display)->tpoint;
	while (tmp->next)
	{
		tmp->x += trans_x;
		tmp->y += trans_y;
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
		if (tmp->z_o != 0)
			tmp->z += trans;
		tmp = tmp->next;
	}
	return (0);
}

void	ft_origin_z(t_win **display)
{
	t_point *tmp;
	
	tmp = (*display)->tpoint;
	while (tmp->next)
	{
		tmp->z = tmp->z_o;
		tmp = tmp->next;
	}
}
void	centrer(t_win **display)
{
	float delta_x;
	float delta_y;
	float sym_x;
	float sym_y;

	display_repere(*display);
	sym_x = (*display)->middle->x;
	sym_y = (*display)->middle->y;
	delta_x = ((*display)->screen / 2) - sym_x;
	delta_y = ((*display)->screen / 2) - sym_y;
	ft_coor_delta(display,delta_x,delta_y);
}
