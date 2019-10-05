/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key_r.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:13:23 by bebosson          #+#    #+#             */
/*   Updated: 2019/07/29 18:17:02 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"


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
		mlx_key_hook(data->win_ptr_s, deal_key, data);
	if (key == 53)
		ft_free_list_and_exit(&data);
	return (0);
}

int		deal_key_r_x(int key, t_win *data)
{
	float angle;
	
	if (key == 1)
		angle = 0.25;
	if (key == 2)
		angle = -0.25;
	data->angle_x += angle;
//	if (data->angle_y != 0)
//	{
//		r_list_y(data, -data->angle_y);
//		centrer(&data);
//		data->angle_y = 0;
//	}
	r_list_x(data, angle);
	centrer(&data);
	fix_image(&data, data->scr, data->scr);
	if (key == 46)
		mlx_key_hook(data->win_ptr_s, deal_key, data);
	if (key == 53)
		ft_free_list_and_exit(&data);

	return (0);
}

int		deal_key_r_y(int key, t_win *data)
{
	float angle;
	
	if (key == 22)
		angle = 0.1;
	if (key == 26)
		angle = -0.1;
	data->angle_y += angle;
//	if (data->angle_x != 0)
//	{
//		r_list_x(data, -data->angle_x);
//		centrer(&data);
//		data->angle_x = 0;
//	}
	r_list_y(data, angle);
	centrer(&data);
	fix_image(&data, data->scr, data->scr);
	if (key == 46)
		mlx_key_hook(data->win_ptr_s, deal_key, data);
	if (key == 53)
		ft_free_list_and_exit(&data);
	return (0);
}


int		deal_key_r(int key, t_win *data)
{
	set_colour_info(data);
	if (key == 3)
		mlx_hook(data->win_ptr_s, 2, 0,deal_key_r_z, data);
	if (key == 7)
		mlx_hook(data->win_ptr_s, 2,0, deal_key_r_x, data);
	if (key == 16)
		mlx_hook(data->win_ptr_s, 2, 0, deal_key_r_y, data);
	if (key == 46)
		mlx_hook(data->win_ptr_s, 2, 0,deal_key, data);
	if (key == 53)
		ft_free_list_and_exit(&data);

	return (0);
}
