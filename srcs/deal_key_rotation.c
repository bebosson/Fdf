/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:13:23 by bebosson          #+#    #+#             */
/*   Updated: 2019/06/25 14:46:47 by bebosson         ###   ########.fr       */
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
	//variable angle
	float angle;
	//	display->angle_x = 0;
	if (key == 1)
		angle = 0.25;
	if (key == 2)
		angle = -0.25;
	display->angle_x += angle;
	if (display->angle_y != 0)
	{	
		rotation_list_y(display, -display->angle_y);
		centrer(&display);
		display->angle_y = 0;
	}
	rotation_list_x(display, angle);
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
	float angle;
	if (key == 22)
		angle = 0.25;
	if (key == 26)
		angle = -0.25;
	display->angle_y += angle;
	rotation_list_y(display, angle);
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

	set_colour_info(display);
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
