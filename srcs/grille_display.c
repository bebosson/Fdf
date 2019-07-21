/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grille_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:38:33 by bebosson          #+#    #+#             */
/*   Updated: 2019/07/18 22:16:24 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

//expose hook and loop hook

int		deal_key_zoom(int key, t_win *display)
{
	display->color->zoom_action = 0xff88ff;
	display_borne(display);
	if (key == 69 && test_echelle(display) == 1)
		ft_echelle(&display, 2);
	if (key == 78 && display->echelle > display->echelle_max)
		ft_echelle(&display, 0.5);
	centrer(&display);
	fix_image(&display, display->screen, display->screen); //ft_trace !
	if (key == 46)
		mlx_key_hook(display->win_ptr_s, deal_key, display);
	if (key == 53)
		exit(EXIT_SUCCESS);

	return (0);
}

int		deal_key_ziso_plane(int key, t_win *display)
{
		display->iso = 0;
		ft_origin(&display);
		ft_origin_z(&display);
		test_echelle(display);
		display->echelle_max = 8;
		centrer(&display);
		fix_image(&display, display->screen, display->screen);
	if (key == 46)
		mlx_key_hook(display->win_ptr_s, deal_key, display);
	if (key == 53)
		exit(EXIT_SUCCESS);

	return (0);
}

int		deal_key_ziso(int key, t_win *display)
{
		display->iso = 1;
		ft_origin(&display); //regrouper origine
		ft_origin_z(&display);
		iso_list(display);
		test_echelle(display);
		display->echelle_max = 8;
		centrer(&display);
		fix_image(&display, display->screen, display->screen);
	if (key == 46)
		mlx_key_hook(display->win_ptr_s, deal_key, display);
	if (key == 53)
		exit(EXIT_SUCCESS);

	return (0);
}



int		deal_key_ziso_menu(int key, t_win *display)
{
	if (key == 35 && display->iso == 0)
		mlx_key_hook(display->win_ptr_s, deal_key_ziso, display);
	if (key == 31 && display->iso == 1)
		mlx_key_hook(display->win_ptr_s, deal_key_ziso_plane, display);
	if (key == 46)
		mlx_key_hook(display->win_ptr_s, deal_key, display);
	if (key == 53)
		exit(EXIT_SUCCESS);

	return (0);
}

int		deal_key_translation(int key, t_win *display)
{
	int y;
	int x;

	display->color->translation = 0xff88ff;
	display_borne(display);
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
	ft_coor_delta(&display, x, y);
	fix_image(&display,0,0);
	if (key == 46)
		mlx_key_hook(display->win_ptr_s, deal_key, display);
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
int		deal_key_change_z(int key, t_win *display)
{
	if (key == 38)
		ft_coor_z(&display, 5);
	if (key == 40)
		ft_coor_z(&display, -5);
	display_repere(display);
	fix_image(&display,0,0);
	if (key == 46)
		mlx_key_hook(display->win_ptr_s, deal_key, display);
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int		deal_key(int key, t_win *display)
{
	set_colour_info(display);
	if (key == 8)
		mlx_hook(display->win_ptr_s, 2, 0, deal_key_couleur, display);
	if (key == 6)
	{
		mlx_hook(display->win_ptr_s, 2, 0, deal_key_zoom, display);
		display->color->rotation = 0xff88ff;
		display_borne(display);
	}
	if (key == 15)
	{
		display->color->rotation = 0xff88ff;
		display_borne(display);
		mlx_hook(display->win_ptr_s, 2, 0,deal_key_rotation, display);
	}
	if (key == 4)
		mlx_hook(display->win_ptr_s, 2, 0,deal_key_change_z, display);
//	if (key == 2)
//		display_repere(display);
	if (key == 17) // ->
		mlx_hook(display->win_ptr_s, 2, 0, deal_key_translation, display);
	if (key == 34)
		mlx_hook(display->win_ptr_s, 2, 0, deal_key_ziso_menu, display);
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
