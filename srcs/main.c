/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 06:09:09 by bebosson          #+#    #+#             */
/*   Updated: 2019/07/26 01:04:54 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fdf.h"

int		set_wireframe(t_win *display, char *av)
{
	t_color *color_info;

	display->iso = ft_atoi(av);
	if (display->iso == 1)
		iso_list(display);
	display->screen = 1000;
	display->mlx = mlx_init();
	(display)->win_ptr_s
		= mlx_new_window(display->mlx, display->screen, display->screen,"FDF");
	display->screen2 = 500;
	(display)->win
		= mlx_new_window(display->mlx, display->screen2, display->screen2,"d");
	if (!(color_info = malloc(sizeof(t_color))))
	{
		ft_error(0);
		ft_free_list_and_exit(&display);
	}
	display->color = color_info;
	set_colour_info(display);
	return (1);
}

int		graphic(t_win *display, char *av)
{
	if (!(set_wireframe(display,av)))
	{
		ft_error(0);
		ft_free_list_and_exit(&display);
	}
	fix_couleur(&display);
	point_central(&display);
	centrer(&display);
	get_image(display);
	test_echelle(display);
	fix_nbr_pt(display);
	ft_coor_z(&display, 0.5);
	fix_image(&display, display->screen, display->screen);
	mlx_hook(display->win_ptr_s,2, 0, deal_key, display);
	mlx_loop(display->mlx);
	return (0);
}

int		coor_to_graph(int fd, char *av)
{
	t_win	*display;

	if (!(display = (t_win *)malloc(sizeof(t_win))))
		return (0);
	if (!(display->tpoint = read_to_list(fd, display)))
	{
		ft_error(0);
		ft_free_list_and_exit(&display);
	}
	if (!(graphic(display, av)))
	{
		ft_error(0);
		ft_free_list_and_exit(&display);
	}
	return (1);
}

int main(int ac, char **av)
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
