/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 19:50:12 by bebosson          #+#    #+#             */
/*   Updated: 2019/10/05 19:54:21 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key_r_z(int key, t_win *data)
{
	data->angle = 0;
	if (key == 0)
		data->angle += 0.25;
	if (key == 12)
		data->angle -= 0.25;
	r_list_z(data, data->angle);
	centrer(&data);
	fix_image(&data, data->scr, data->scr);
	if (key == 46)
		mlx_key_hook(data->w, deal_key, data);
	if (key == 53)
		ft_free_list_and_exit(&data);
	return (0);
}

int		deal_key_r_x(int key, t_win *data)
{
	float angle;

	angle = 0;
	if (key == 1)
		angle = 0.25;
	if (key == 2)
		angle = -0.25;
	data->angle_x += angle;
	r_list_x(data, angle);
	centrer(&data);
	fix_image(&data, data->scr, data->scr);
	if (key == 46)
		mlx_key_hook(data->w, deal_key, data);
	if (key == 53)
		ft_free_list_and_exit(&data);
	return (0);
}

int		deal_key_r_y(int key, t_win *data)
{
	float angle;

	angle = 0;
	if (key == 22)
		angle = 0.1;
	if (key == 26)
		angle = -0.1;
	data->angle_y += angle;
	r_list_y(data, angle);
	centrer(&data);
	fix_image(&data, data->scr, data->scr);
	if (key == 46)
		mlx_key_hook(data->w, deal_key, data);
	if (key == 53)
		ft_free_list_and_exit(&data);
	return (0);
}

int		deal_key_r(int key, t_win *data)
{
	set_colour_info(data);
	if (key == 3)
		mlx_hook(data->w, 2, 0, deal_key_r_z, data);
	if (key == 7)
		mlx_hook(data->w, 2, 0, deal_key_r_x, data);
	if (key == 16)
		mlx_hook(data->w, 2, 0, deal_key_r_y, data);
	if (key == 46)
		mlx_hook(data->w, 2, 0, deal_key, data);
	if (key == 53)
		ft_free_list_and_exit(&data);
	return (0);
}
