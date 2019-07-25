/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:34:32 by bebosson          #+#    #+#             */
/*   Updated: 2019/07/21 19:13:34 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	rotation_list_z(t_win *display, float angle)
{
	t_point *tmp;

	display->color->rotation_z = 0xff88ff;
	display_borne(display);
	tmp = display->tpoint;
	while (tmp->next)
	{
		rotation_z(angle,&tmp->x,&tmp->y, display);
		tmp = tmp->next;
	}
}

void	rotation_list_x(t_win *display, float angle)
{
	t_point *tmp;

	display->color->rotation_x = 0xff88ff;
	display_borne(display);
	tmp = display->tpoint;
	while (tmp->next)
	{
		rotation_x(angle,&tmp->y,&tmp->z, display);
		tmp = tmp->next;
	}
}

void	rotation_list_y(t_win *display, float angle)
{
	t_point *tmp;

	display->color->rotation_y = 0xff88ff;
	display_borne(display);
	tmp = display->tpoint;
	while (tmp->next)
	{
		rotation_y(angle,&tmp->z,&tmp->x, display);
		tmp = tmp->next;
	}
}
