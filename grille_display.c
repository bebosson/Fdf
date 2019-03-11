/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grille_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:38:33 by bebosson          #+#    #+#             */
/*   Updated: 2019/03/11 16:16:30 by bebosson         ###   ########.fr       */
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
	;
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

void	vertical(t_win *display, int trans)
{
	int x;
	int y;

	display->x_win += trans;
	x = display->x_o + trans;
	mlx_clear_window(display->mlx,display->win_ptr_s);
	while (x <= display->x_win)
	{
		y = display->y_o;
		while (++y <= display->y_win)
			mlx_pixel_put(display->mlx,display->win_ptr_s, x, y, 0xFF0000);
		x += display->echelle;
	}
	display->x_o += trans;
	if (trans != 0)
		horizontal(display, 0);
}

void	horizontal(t_win *display, int trans)
{
	int x;
	int y;

	display->y_win += trans;
	y = display->y_o + trans;
	mlx_clear_window(display->mlx,display->win_ptr_s);
	while (y <= display->y_win)
	{
		x = display->x_o;
		while (++x <= display->x_win)
			mlx_pixel_put(display->mlx,display->win_ptr_s, x, y, 0xFF0000);
		y += display->echelle;
	}
	display->y_o += trans;
	if (trans != 0)
		vertical(display, 0);
}

int		deal_key(int key, t_win *display)
{
	int i;

	i = 0;
	display_display(display);
	printf("key = %d \n", key);
	if (key == 124 && display->x_win < display->screen) // ->
		vertical(display, 10);
	if (key == 123 && display->x_o > 0) // <-
		vertical(display, -10);
	if (key == 125 && display->y_win < display->screen) // haut
		horizontal(display, 10);
	if (key == 126 && display->y_o > 0) // bas
		horizontal(display, -10);
	if (key == 116)
		horizontal(display, 50);
	if (key == 12)
	{
		ft_echelle(display, 0.5);
		ft_display(display);
	}
	if (key == 13)
	{
		ft_echelle(display, 2);
		ft_display(display);
	}
	if (key == 14)
		mlx_clear_window(display->mlx,display->win_ptr_s);
	return (0);
}
void	ft_display(t_win *display)
{
	vertical(display,0);
	horizontal(display,0);

}

void	ft_echelle(t_win *display, float echelle)
{
	display->echelle *= echelle;
}

void	set_display(t_win *display, int x_win, int y_win, float echelle)
{
	display->x_win = x_win * echelle;
	display->y_win = y_win * echelle;
	display->x_o = 0;
	display->y_o = 0;
	display->echelle = echelle;
}

void	set_display_oblique(t_win *display, int x, int y, float echelle)
{
	display->x_win = (x - y) * 64;
	display->y_win = (x + y) * 32;
	display->x_o = 0;
	display->y_o = 0;
	display->echelle = echelle;
}
void	display_display(t_win *display)
{
	printf("----------------------------\n");
	printf("y_o(disply) = %d \n",display->y_o);
	printf("x_o(disply) = %d  \n",display->x_o);
	printf("y_win(disply) = %d  \n",display->y_win);
	printf("x_win(disply) = %d \n",display->x_win);
	printf("screen(display) = %d \n",display->screen);
	printf("echelle (display) = %.5f \n", display->echelle);
	printf("----------------------------\n");
}
/*
   int		try_iso(t_win *display)
   {
   float ratio;
   float dx;
   float dy;
   int x;
   int y;

   x = 30;
   y = 30;

   dx = (float)display->x_win - x;
   dy = (float)display->y_win - y;
   ratio = dy / dx;


   }
   */
