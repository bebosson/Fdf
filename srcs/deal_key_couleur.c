/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key_couleur.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 03:52:53 by bebosson          #+#    #+#             */
/*   Updated: 2019/07/26 00:04:04 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

int		deal_key_couleur_r(int key, t_win *display)
{
	int delta_r;

	display->color->couleur_r = 0xff88ff;
	display_borne(display);
		if (key == 126 && display->tpoint->r < 255)
		delta_r = 5;
	else if (key == 125 && display->tpoint->r >= 1)
		delta_r = -5;
	else
		delta_r = 0;
	if (key == 46)
		mlx_key_hook(display->win_ptr_s,deal_key, display);
	change_couleur_point(&display, delta_r,0,0);
	fix_image(&display, display->screen, display->screen);
	if (key == 53)
		ft_free_list_and_exit(&display);

	return (0);
}

int		deal_key_couleur_g(int key, t_win *display)
{
	int delta_g;

	display->color->couleur_g = 0xff88ff;
	display_borne(display);
	if (key == 126 && display->tpoint->g < 255)
		delta_g = 5;
	else if (key == 125 && display->tpoint->g >= 1)
		delta_g = -5;
	else
		delta_g = 0;
	if (key == 8)
		mlx_hook(display->win_ptr_s, 2, 0, deal_key, display);
	change_couleur_point(&display, 0,delta_g,0);
	fix_image(&display, display->screen, display->screen);
	if (key == 46) // ->
		mlx_key_hook(display->win_ptr_s, deal_key_translation, display);
	if (key == 53)
		ft_free_list_and_exit(&display);

	return (0);
}

int		deal_key_couleur_b(int key, t_win *display)
{
	int delta_b;

	display->color->couleur_b = 0xff88ff;
	display_borne(display);
	if (key == 126 && display->tpoint->b < 255)
		delta_b = 5;
	else if (key == 125 && display->tpoint->b >= 1)
		delta_b = -5;
	else
		delta_b = 0;
	change_couleur_point(&display, 0,0,delta_b);
	fix_image(&display, display->screen, display->screen);
	if (key == 8)
		mlx_key_hook(display->win_ptr_s, deal_key, display);
	if (key == 17) // ->
		mlx_hook(display->win_ptr_s, 2, 0,deal_key_translation, display);
	if (key == 53)
		ft_free_list_and_exit(&display);
	return (0);
}

int		deal_key_couleur(int key, t_win *display)
{
	display->color->couleur = 0xff88ff;
	display_borne(display);
	if (key == 14) //r
		mlx_hook(display->win_ptr_s, 2, 0,deal_key_couleur_r, display);
	if (key == 5) //g
		mlx_hook(display->win_ptr_s, 2, 0,deal_key_couleur_g, display);
	if (key == 11) //b
		mlx_hook(display->win_ptr_s, 2, 0,deal_key_couleur_b, display);
	if (key == 17) // ->
		mlx_key_hook(display->win_ptr_s, deal_key, display);
	if (key == 53)
		ft_free_list_and_exit(&display);

	return (0);
}


