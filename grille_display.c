/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grille_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:38:33 by bebosson          #+#    #+#             */
/*   Updated: 2019/03/29 19:49:53 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"
void ligne(int xi,int yi,int xf,int yf, t_win *display)
{
//	printf("xi = %d \n",xi);
//	printf("yi = %d \n",yi);
//	printf("xf = %d \n",xf);
//	printf("yf = %d \n",yf);
	int dx,dy,i,xinc,yinc,cumul,x,y;
	x = xi ;
	y = yi ;
	dx = xf - xi ;
	dy = yf - yi ;
	xinc = ( dx > 0 ) ? 1 : -1 ;
	yinc = ( dy > 0 ) ? 1 : -1 ;
	dx = abs(dx) ;
	dy = abs(dy) ;
	
	//printf("x_i = %d\n",xi);
//	printf("y_i = %d\n",yi);
//	printf("x_f= %d\n",xf);
//	printf("y_f = %d\n",yf);

	mlx_pixel_put(display->mlx,display->win_ptr_s, x, y, 0xFF0000);
	if ( dx > dy ) {
		cumul = dx / 2 ;
		for ( i = 1 ; i <= dx ; i++ ) {
			x += xinc ;
			cumul += dy ;
			if ( cumul >= dx ) {
				cumul -= dx ;
				y += yinc ; }
			mlx_pixel_put(display->mlx,display->win_ptr_s, x, y, 0xFF0000);
			 ; } }
	else {
		cumul = dy / 2 ;
		for ( i = 1 ; i <= dy ; i++ ) {
			y += yinc ;
			cumul += dx ;
			if ( cumul >= dy ) {
				cumul -= dy ;
				x += xinc ; }
			mlx_pixel_put(display->mlx,display->win_ptr_s, x, y, 0xFF0000);
			 } }
}

int		deal_key_rotation_z(int key, t_win *display)
{
	display->angle = 0;
	if (key == 124) // ->
	{
		display->angle += 0.25;
		rotation_list_z(display, display->angle);
		centrer(&display);
		ft_trace(display);
	}
	if (key == 123)// <-
	{
		display->angle -= 0.25;
		rotation_list_z(display, display->angle);
		centrer(&display);
		ft_trace(display);
	}
	if (key == 31)
		ft_trace(display);
	if (key == 2)
		display_repere(display);
	if (key == 17)
		mlx_key_hook(display->win_ptr_s, deal_key_translation, display);
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int		deal_key_rotation_x(int key, t_win *display)
{
//	float angle;

	display->angle = 0;
	printf("%.5f \n",display->angle);
	if (key == 124) // ->
	{
		display->angle += 0.25;
		rotation_list_x(display, display->angle);
		centrer(&display);
		ft_trace(display);
	}
	if (key == 123)// <-
	{
		display->angle -= 0.25;
		rotation_list_x(display, display->angle);
		centrer(&display);
		ft_trace(display);
	}
	if (key == 31)
	{
//		ft_origin(&display);
		ft_trace(display);
	}
	if (key == 2)
		display_repere(display);
	if (key == 17)
		mlx_key_hook(display->win_ptr_s, deal_key_translation, display);

	return (0);
}

int		deal_key_rotation_y(int key, t_win *display)
{
//	float angle;

	display->angle = 0;
	printf("%.5f \n",display->angle);
	if (key == 124) // ->
	{
//		if (display->angle < 0)
//			display->angle *= -1;
		display->angle += 0.25;
		rotation_list_y(display, display->angle);
		centrer(&display);
		ft_trace(display);
//		centrer(&display);
//		ft_origin(&display, 25, display->angle);
//		iso_list(display);
//		angle = 0;
	}
	if (key == 123)// <-
	{
//		if (display->angle > 0)
//			display->angle *= -1;
		display->angle -= 0.25;
		rotation_list_y(display, display->angle);
		centrer(&display);
		ft_trace(display);
//		ft_origin(&display, 25, display->angle);
//		iso_list(display);
	}
	if (key == 31)
	{
//		ft_origin(&display);
		ft_trace(display);
	}
	if (key == 2)
		display_repere(display);
	if (key == 17)
		mlx_key_hook(display->win_ptr_s, deal_key_translation, display);

	return (0);
}


int		deal_key_rotation(int key, t_win *display)
{
	if (key == 6)
		mlx_key_hook(display->win_ptr_s, deal_key_rotation_z, display);
	if (key == 7)
		mlx_key_hook(display->win_ptr_s, deal_key_rotation_x, display);
	if (key == 16)
		mlx_key_hook(display->win_ptr_s, deal_key_rotation_y, display);
	
	mlx_string_put(display->mlx, display->win_ptr_s, 750,0, 0XFFFFF0, "Rot X pour X\nY pour Y\nZ pour Z");
	return (0);
}
int		deal_key_zoom(int key, t_win *display)
{
	if (key == 126) // ^
	{
		ft_echelle(&display, 2);
		centrer(&display);
		ft_trace(display);
	}
	if (key == 125)// V
	{
		ft_echelle(&display, 0.5);
		centrer(&display);
		ft_trace(display);
	}
	if (key == 2)
		display_repere(display);
	if (key == 17)
		mlx_key_hook(display->win_ptr_s, deal_key_translation, display);
	mlx_string_put(display->mlx, display->win_ptr_s, 750,0, 0XFFFFF0, "ZOOM");
	return (0);
}

int		deal_key_ziso(int key, t_win *display)
{
	float ziso;
	if (key == 125)
	{
		ziso = -0.25;
		display->z += ziso;
		ft_coor_z(&display, display->z);
		ft_origin(&display,25,display->angle, 1);
		ft_trace(display);
	}
	if (key == 126)
	{
		ziso = 0.25;
		display->z += ziso;
		ft_coor_z(&display, display->z);
		ft_origin(&display,25,display->angle, 1);
		ft_trace(display);
	}
	if (key == 17) // ->
		mlx_key_hook(display->win_ptr_s, deal_key_translation, display);

	return (0);
}


int		deal_key_translation(int key, t_win *display)
{
	if (key == 124) // ->
	{
		ft_coor_x(&display, 100);
		ft_trace(display);
	}
	if (key == 123)// <-
	{
		ft_coor_x(&display, -20);
		ft_trace(display);
	}
	if (key == 125)
	{
		ft_coor_y(&display, 100);
		ft_trace(display);
	}
	if (key == 126)
	{
		ft_coor_y(&display, -20);
		ft_trace(display);
	}
	if (key == 15)
		mlx_key_hook(display->win_ptr_s, deal_key_rotation, display);
	if (key == 6)
		mlx_key_hook(display->win_ptr_s, deal_key_zoom, display);
	if (key == 34)
		mlx_key_hook(display->win_ptr_s, deal_key_ziso, display);
	if (key == 8)
	{
		centrer(&display);
		ft_trace(display);
	}
		 
	mlx_string_put(display->mlx, display->win_ptr_s, 750,0, 0XFFFFF0, "DEPLACEMENT");

	return (0);
}

int		deal_key(int key, t_win *display)
{

	if (key == 6)
		mlx_key_hook(display->win_ptr_s, deal_key_zoom, display);

	if (key == 15)
		mlx_key_hook(display->win_ptr_s, deal_key_rotation, display);
	
	if (key == 17) // ->
		mlx_key_hook(display->win_ptr_s, deal_key_translation, display);
	if (key == 34)
		mlx_key_hook(display->win_ptr_s, deal_key_ziso, display);
	if (key == 53)
		exit(EXIT_SUCCESS);

	return (0);
}

