/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:08:53 by bebosson          #+#    #+#             */
/*   Updated: 2019/03/28 19:44:39 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fdf.h"

void	iso_list(t_win *display)
{
	t_point *tmp;

	tmp = display->tpoint;
	while (tmp->next)
	{
		trans_iso(&tmp->x,&tmp->y,tmp->z);
		tmp = tmp->next;
	}
}

void	trans_iso(float *x, float *y, int z)
{
	float x_i;
	float y_i;

//	x_i = (0.7071) * (*x - *y);
//	y_i = -((0.8165 * z) - 0.40825 * (*x + *y));
//	x_i += 100;
//	y_i += 100;
//	 	x_i = 0.866 * (*x - *y);
//	y_i =  (0.5 * (*x) + 0.5 * (*y) + z);
	x_i = 0.707 * (*x - *y);
	y_i = -(-0.707 * sin(0.4) * (*x + *y) + cos(0.4) * (z));
	*x = x_i;
	*y = y_i;
//	round_value(x_i,y_i,x,y);
//	printf("y_iso = %d \n",*y);
}
