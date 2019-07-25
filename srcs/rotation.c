/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:05:55 by bebosson          #+#    #+#             */
/*   Updated: 2019/07/21 20:51:38 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	rotation_z(float teta, float *x, float *y, t_win *display)
{
	float x_p;
	float y_p;
	int sym_x;
	int sym_y;

	x_p = ((*x)) * cos(teta) - ((*y)) * sin(teta);
	y_p = ((*x)) * sin(teta) + ((*y)) * cos(teta);
	*x = x_p;
	*y = y_p;
}

void	rotation_x(float teta, float *y, float *z, t_win *display)
{
	float y_p;
	float z_p;
	int sym_x;
	int sym_y;

	y_p = ((*y)) * cos(teta) + ((*z)) * sin(teta);
	z_p = ((*z)) * cos(teta) - ((*y)) * sin(teta);
	*y = y_p;
	*z = z_p;
}

void	rotation_y(float teta, float *x, float *z, t_win *display)
{
	float x_p;
	float z_p;

	x_p = ((*x)) * cos(teta) - ((*z)) * sin(teta);
	z_p = ((*x)) * sin(teta) + ((*z)) * cos(teta);
	*x = x_p;
	*z = z_p;
}

void	ft_set_to_zero(t_win *display, int angle_y, int angle_x)
{
	if (display->angle_y != 0)
	{
		rotation_list_y(display, angle_y);
		display->angle_y = 0;
	}
	if (display->angle_x != 0)
	{
		rotation_list_x(display, angle_x);
		display->angle_x = 0;
	}
}
