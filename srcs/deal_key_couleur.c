/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key_couleur.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 19:44:57 by bebosson          #+#    #+#             */
/*   Updated: 2019/10/05 19:44:59 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key_c_r(int key, t_win *data)
{
	int delta_r;

	data->c->c_r = 0xff88ff;
	data_borne(data);
	if (key == 126 && data->tpoint->r < 255)
		delta_r = 5;
	else if (key == 125 && data->tpoint->r >= 1)
		delta_r = -5;
	else
		delta_r = 0;
	if (key == 46)
		mlx_key_hook(data->w, deal_key, data);
	change_c_point(&data, delta_r, 0, 0);
	fix_image(&data, data->scr, data->scr);
	if (key == 53)
		ft_free_list_and_exit(&data);
	return (0);
}

int		deal_key_c_g(int key, t_win *data)
{
	int delta_g;

	data->c->c_g = 0xff88ff;
	data_borne(data);
	if (key == 126 && data->tpoint->g < 255)
		delta_g = 5;
	else if (key == 125 && data->tpoint->g >= 1)
		delta_g = -5;
	else
		delta_g = 0;
	if (key == 8)
		mlx_hook(data->w, 2, 0, deal_key, data);
	change_c_point(&data, 0, delta_g, 0);
	fix_image(&data, data->scr, data->scr);
	if (key == 46)
		mlx_key_hook(data->w, deal_key_translation, data);
	if (key == 53)
		ft_free_list_and_exit(&data);
	return (0);
}

int		deal_key_c_b(int key, t_win *data)
{
	int delta_b;

	data->c->c_b = 0xff88ff;
	data_borne(data);
	if (key == 126 && data->tpoint->b < 255)
		delta_b = 5;
	else if (key == 125 && data->tpoint->b >= 1)
		delta_b = -5;
	else
		delta_b = 0;
	change_c_point(&data, 0, 0, delta_b);
	fix_image(&data, data->scr, data->scr);
	if (key == 8)
		mlx_key_hook(data->w, deal_key, data);
	if (key == 17)
		mlx_hook(data->w, 2, 0, deal_key_translation, data);
	if (key == 53)
		ft_free_list_and_exit(&data);
	return (0);
}

int		deal_key_c(int key, t_win *data)
{
	data->c->c = 0xff88ff;
	data_borne(data);
	if (key == 14)
		mlx_hook(data->w, 2, 0, deal_key_c_r, data);
	if (key == 5)
		mlx_hook(data->w, 2, 0, deal_key_c_g, data);
	if (key == 11)
		mlx_hook(data->w, 2, 0, deal_key_c_b, data);
	if (key == 17)
		mlx_key_hook(data->w, deal_key, data);
	if (key == 53)
		ft_free_list_and_exit(&data);
	return (0);
}
