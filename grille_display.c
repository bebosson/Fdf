/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grille_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:38:33 by bebosson          #+#    #+#             */
/*   Updated: 2019/06/01 20:13:41 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"


int		deal_key_rotation_z(int key, t_win *display)
{
	display->angle = 0;
	if (key == 0)
		display->angle += 0.25;
	if (key == 12)
		display->angle -= 0.25;
	rotation_list_z(display, display->angle);
	centrer(&display);
	fix_image(&display, display->screen, display->screen);
	if (key == 46)
		mlx_key_hook(display->win_ptr_s, deal_key, display);
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int		deal_key_rotation_x(int key, t_win *display)
{
	display->angle = 0;
	if (key == 1)
		display->angle += 0.25;
	if (key == 2)
		display->angle -= 0.25;
	rotation_list_x(display, display->angle);
	centrer(&display);
	fix_image(&display, display->screen, display->screen);
	if (key == 46)
		mlx_key_hook(display->win_ptr_s, deal_key, display);
	if (key == 53)
		exit(EXIT_SUCCESS);

	return (0);
}

int		deal_key_rotation_y(int key, t_win *display)
{
	display->angle = 0;
	if (key == 22)
		display->angle += 0.25;
	if (key == 26)
		display->angle -= 0.25;
	rotation_list_y(display, display->angle);
	centrer(&display);
	fix_image(&display, display->screen, display->screen);
	if (key == 46)
		mlx_key_hook(display->win_ptr_s, deal_key, display);
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}


int		deal_key_rotation(int key, t_win *display)
{
	
	if (key == 3)
		mlx_hook(display->win_ptr_s, 2, 0,deal_key_rotation_z, display);
	if (key == 7)
		mlx_hook(display->win_ptr_s, 2,0, deal_key_rotation_x, display);
	if (key == 16)
		mlx_hook(display->win_ptr_s, 2, 0, deal_key_rotation_y, display);
	if (key == 46)
		mlx_hook(display->win_ptr_s, 2, 0,deal_key, display);
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
int		deal_key_zoom(int key, t_win *display)
{
	if (key == 69) // ^
		ft_echelle(&display, 2);
	if (key == 78)// V
		ft_echelle(&display, 0.5);
	centrer(&display);
	fix_image(&display, display->screen, display->screen);
	display_borne(display);
	if (key == 2)
		display_repere(display);
	if (key == 46)
		mlx_key_hook(display->win_ptr_s, deal_key, display);
	if (key == 53)
		exit(EXIT_SUCCESS);

	return (0);
}

int		deal_key_ziso(int key, t_win *display)
{
	float ziso;
	if (key == 125)
	{
		ziso = -10;
		if (display->z > 0)
			display->z *= -1;
	}
	if (key == 126)
	{
		ziso = 10;
		if (display->z < 0)
			display->z *= -1;
	}
	display->z += ziso;
	ft_coor_z(&display, display->z);
	ft_origin(&display,25,display->angle, 1);
	fix_image(&display, display->screen, display->screen);

	if (key == 17) // ->
		mlx_hook(display->win_ptr_s, 2, 0,deal_key_translation, display);

	return (0);
}

int		deal_key_couleur(int key, t_win *display)
{
	int couleur;
	printf("couleur = %d\n",display->couleur);
	if (key == 9)
	{
		couleur = 1000;
//		if (display->couleur > 0)
//			display->couleur *= -1;
	}
	if (key == 12)
	{
		couleur = 10;
//		if (display->couleur < 0)
//			display->couleur *= -1;
	}
//	display->couleur += couleur;
	change_couleur_point(&display, couleur);
	ft_origin(&display,25,display->angle, 1);
	fix_image(&display, display->screen, display->screen);

	if (key == 17) // ->
		mlx_hook(display->win_ptr_s, 2, 0,deal_key_translation, display);
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
	fix_image(&display, display->screen, display->screen);
	if (key == 46)
		mlx_key_hook(display->win_ptr_s, deal_key, display);
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int		deal_key(int key, t_win *display)
{
	display_borne(display);
	if (key == 8)
		mlx_hook(display->win_ptr_s, 2, 0, deal_key_couleur, display);
	if (key == 6)
		mlx_hook(display->win_ptr_s, 2, 0, deal_key_zoom, display);
	if (key == 15)
		mlx_hook(display->win_ptr_s, 2, 0,deal_key_rotation, display);
	if (key == 17) // ->
		mlx_hook(display->win_ptr_s, 2,0, deal_key_translation, display);
	if (key == 34)
		mlx_hook(display->win_ptr_s, 2,0, deal_key_ziso, display);
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
