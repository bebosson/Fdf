/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grille_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 17:24:22 by bebosson          #+#    #+#             */
/*   Updated: 2019/10/05 17:36:34 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key_zoom(int key, t_win *data)
{
	data->c->z_a = 0xff88ff;
	data_borne(data);
	if (data->iso == 0)
		ft_set_to_zero(data, -(data->angle_y), -(data->angle_x));
	if (key == 69 && test_echelle(data) == 1)
		ft_echelle(&data, 2);
	if (key == 78 && data->echelle > data->echelle_max)
		ft_echelle(&data, 0.5);
	centrer(&data);
	fix_image(&data, data->scr, data->scr);
	if (key == 46)
		mlx_key_hook(data->w, deal_key, data);
	if (key == 53)
		ft_free_list_and_exit(&data);
	return (0);
}

int	deal_key_ziso_plane(int key, t_win *data)
{
	data->iso = 0;
	ft_origin(&data);
	ft_origin_z(&data);
	data->angle_y = 0;
	data->angle_x = 0;
	test_echelle(data);
	data->echelle_max = 8;
	centrer(&data);
	fix_image(&data, data->scr, data->scr);
	if (key == 46)
		mlx_key_hook(data->w, deal_key, data);
	if (key == 53)
		ft_free_list_and_exit(&data);
	return (0);
}

int	deal_key_ziso(int key, t_win *data)
{
	data->iso = 1;
	ft_origin(&data);
	ft_origin_z(&data);
	ft_coor_z(data, 0.1);
	iso_list(data);
	test_echelle(data);
	data->echelle_max = 8;
	centrer(&data);
	fix_image(&data, data->scr, data->scr);
	if (key == 46)
		mlx_key_hook(data->w, deal_key, data);
	if (key == 53)
		ft_free_list_and_exit(&data);
	return (0);
}

int	deal_key_ziso_menu(int key, t_win *data)
{
	if (key == 35 && data->iso == 0)
		mlx_key_hook(data->w, deal_key_ziso, data);
	if (key == 31 && data->iso == 1)
		mlx_key_hook(data->w, deal_key_ziso_plane, data);
	if (key == 46)
		mlx_key_hook(data->w, deal_key, data);
	if (key == 53)
		ft_free_list_and_exit(&data);
	return (0);
}

int	deal_key_translation(int key, t_win *data)
{
	int y;
	int x;

	data->c->trans = 0xff88ff;
	data_borne(data);
	y = 0;
	x = 0;
	if (key == 124)
		x = 5;
	if (key == 123)
		x = -5;
	if (key == 125)
		y = 5;
	if (key == 126)
		y = -5;
	ft_coor_delta(&data, x, y);
	fix_image(&data, 0, 0);
	if (key == 46)
		mlx_key_hook(data->w, deal_key, data);
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
