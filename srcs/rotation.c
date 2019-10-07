/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:23:33 by bebosson          #+#    #+#             */
/*   Updated: 2019/07/29 21:23:38 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	r_z(float teta, float *x, float *y, t_win *data)
{
	float	x_p;
	float	y_p;
	int		sym_x;
	int		sym_y;

	x_p = ((*x)) * cos(teta) - ((*y)) * sin(teta);
	y_p = ((*x)) * sin(teta) + ((*y)) * cos(teta);
	*x = x_p;
	*y = y_p;
}

void	r_x(float teta, float *y, float *z, t_win *data)
{
	float	y_p;
	float	z_p;
	int		sym_x;
	int		sym_y;

	y_p = ((*y)) * cos(teta) + ((*z)) * sin(teta);
	z_p = ((*z)) * cos(teta) - ((*y)) * sin(teta);
	*y = y_p;
	*z = z_p;
}

void	r_y(float teta, float *x, float *z, t_win *data)
{
	float	x_p;
	float	z_p;

	x_p = ((*x)) * cos(teta) - ((*z)) * sin(teta);
	z_p = ((*x)) * sin(teta) + ((*z)) * cos(teta);
	*x = x_p;
	*z = z_p;
}

void	ft_set_to_zero(t_win *data, int angle_y, int angle_x)
{
	if (data->angle_y != 0)
	{
		r_list_y(data, angle_y);
		data->angle_y = 0;
	}
	if (data->angle_x != 0)
	{
		r_list_x(data, angle_x);
		data->angle_x = 0;
	}
}
