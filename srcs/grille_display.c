/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grille_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:38:33 by bebosson          #+#    #+#             */
/*   Updated: 2019/06/23 17:19:58 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

//expose hook and loop hook

int		deal_key_zoom(int key, t_win *display)
{
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
		display->echelle = 16;
//		ft_echelle(&display, display->echelle);
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
		display->echelle = 16;
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

int		deal_key(int key, t_win *display)
{
	if (key == 8)
		mlx_hook(display->win_ptr_s, 2, 0, deal_key_couleur, display);
	if (key == 6)
		mlx_hook(display->win_ptr_s, 2, 0, deal_key_zoom, display);
	if (key == 15)
		mlx_hook(display->win_ptr_s, 2, 0,deal_key_rotation, display);
	if (key == 17) // ->
		mlx_hook(display->win_ptr_s, 2, 0, deal_key_translation, display);
	if (key == 34)
		mlx_hook(display->win_ptr_s, 2, 0, deal_key_ziso_menu, display);
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
