/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 06:09:09 by bebosson          #+#    #+#             */
/*   Updated: 2019/10/05 17:36:20 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

int		set_wireframe(t_win *data, char *av)
{
	t_co	*c_info;

	data->iso = ft_atoi(av);
	if (data->iso == 1)
	{
		ft_coor_z(data, 0.1);
		iso_list(data);
	}
	data->scr = 1000;
	data->mlx = mlx_init();
	(data)->w = mlx_new_window(data->mlx, data->scr, data->scr, "FDF");
	data->scr2 = 500;
	(data)->win = mlx_new_window(data->mlx, data->scr2, data->scr2, "info");
	if (!(c_info = malloc(sizeof(t_co))))
	{
		ft_error(0);
		ft_free_list_and_exit(&data);
	}
	data->c = c_info;
	set_colour_info(data);
	ft_coor_z(data, 0);
	return (1);
}

int		graphic(t_win *data, char *av)
{
	if (!(set_wireframe(data, av)))
	{
		ft_error(0);
		ft_free_list_and_exit(&data);
	}
	fix_c(&data);
	point_central(&data);
	centrer(&data);
	get_image(data);
	test_echelle(data);
	fix_nbr_pt(data);
	fix_image(&data, data->scr, data->scr);
	mlx_hook(data->w, 2, 0, deal_key, data);
	mlx_loop(data->mlx);
	return (0);
}

int		coor_to_graph(int fd, char *av)
{
	t_win	*data;

	if (!(data = (t_win *)malloc(sizeof(t_win))))
		return (0);
	if (!(data->tpoint = read_to_list(fd, data)))
	{
		ft_error(0);
		ft_free_list_and_exit(&data);
	}
	if (!(graphic(data, av)))
	{
		ft_error(0);
		ft_free_list_and_exit(&data);
	}
	return (1);
}

int		deal_key(int key, t_win *data)
{
	set_colour_info(data);
	if (key == 8)
		mlx_hook(data->w, 2, 0, deal_key_c, data);
	if (key == 6)
	{
		mlx_hook(data->w, 2, 0, deal_key_zoom, data);
		data->c->r = 0xff88ff;
		data_borne(data);
	}
	if (key == 15)
	{
		data->c->r = 0xff88ff;
		data_borne(data);
		mlx_hook(data->w, 2, 0, deal_key_r, data);
	}
	if (key == 17)
		mlx_hook(data->w, 2, 0, deal_key_translation, data);
	if (key == 34)
		mlx_hook(data->w, 2, 0, deal_key_ziso_menu, data);
	if (key == 53)
		ft_free_list_and_exit(&data);
	return (0);
}

int		main(int ac, char **av)
{
	int fd;

	if (ft_error_maps(ac, av) > 0)
	{
		fd = open(av[1], O_RDONLY);
		if (!(coor_to_graph(fd, av[2])))
		{
			ft_error(0);
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		ft_error(0);
		exit(EXIT_SUCCESS);
	}
}
