/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:21:59 by bebosson          #+#    #+#             */
/*   Updated: 2019/03/12 19:24:02 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	display_max(t_point *list, t_win *display)
{
	int x_win;
	int y_win;

	while (

}

void	rotation_list(t_point *list, t_win *display)
{
	t_point *tmp;

	tmp = list;
	while (tmp->next)
	{
		rotation_x(0.785,&tmp->x,&tmp->y);
		tmp = tmp->next;
	}

}
