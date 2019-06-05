/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grille_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:38:33 by bebosson          #+#    #+#             */
/*   Updated: 2019/06/05 04:52:27 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"



int		deal_key_zoom(int key, t_win *display)
{
	if (key == 69)
		ft_echelle(&display, 2);
	if (key == 78)// V// ^
		ft_echelle(&display, 0.5);

//	ft_echelle(&display, display->echelle);
//	printf("display->echelle = %.5f\n",display->echelle);
	centrer(&display);
	fix_image(&display, display->screen, display->screen);
//	display_repere(display);
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
		display->z = 0.99;
//		if (display->z > 0)
//			display->z *= -1;
	}
	if (key == 126)
	{
		display->z = 1.02;
//		if (display->z < 0)
//			display->z *= -1;
	}
	
	ft_coor_z(&display, display->z);
	ft_origin(&display);
	fix_display(&display,display->echelle,display->angle, display->z);
	fix_image(&display, display->screen, display->screen);
	display_repere(display);
	if (key == 46)
		mlx_key_hook(display->win_ptr_s, deal_key, display);

	if (key == 17) // ->
		mlx_hook(display->win_ptr_s, 2, 0,deal_key_translation, display);

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
/*	if (key == 49)
	{
		display->iso = 1;
//		ft_origin_z(&display);
		ft_origin(&display);
		fix_display(&display,25,display->angle, 1);
	//	iso_list(display);
		centrer(&display);
		fix_image(&display, display->screen, display->screen);
	}
	if (key == 50)
	{
		display->iso = 0;
//		ft_origin_z(&display);
		ft_origin(&display);
		fix_display(&display,25,display->angle, 1);
	//	iso_list(display);
		centrer(&display);
		fix_image(&display, display->screen, display->screen);

	}
*/	if (key == 17) // ->
		mlx_hook(display->win_ptr_s, 2,0, deal_key_translation, display);
	if (key == 34)
		mlx_hook(display->win_ptr_s, 2,0, deal_key_ziso, display);
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
