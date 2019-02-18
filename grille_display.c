/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grille_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:38:33 by bebosson          #+#    #+#             */
/*   Updated: 2019/02/18 18:50:37 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

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

/*
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
			mlx_pixel_put(display->mlx,display->win_ptr_s, x+trans, y+trans, 0xFF0000);
		y += 100;
	}
	display->y_o += trans;
	display->y_o = y_ref + trans;
		while (++display->y_o < display->y_win)
			mlx_pixel_put(display->mlx,display->win_ptr_s, display->x_o,display->y_o, 0xFF0000);

}



void	horizontal(t_win *display, int y_ref, int x_ref, int trans)
{
	int x;
	int y;

	display->x_win += trans;
	display->x_o += trans;
	while (display->y_o < display->y_win)
	{
		display->x_o = x_ref + trans;
		while (++display->x_o < display->x_win)
			mlx_pixel_put(display->mlx,display->win_ptr_s, display->x_o, display->y_o, 0xFF0000);
		display->y_o += 100;
	}
	display->x_o = x_ref + trans;
		while (++display->x_o < display->x_win)
			mlx_pixel_put(display->mlx,display->win_ptr_s, display->x_o,display->y_o, 0xFF0000);

	display->y_o = y_ref;
	display->x_o = x_ref + trans;
}
*/
int		deal_key(int key, t_win *display)
{
	int i;
	
	i = 0;
	printf("y_o(disply) = %d \n",display->y_o);
	printf("y_win(disply) = %d \n",display->y_win);
	printf("x_o(disply) = %d \n",display->x_o);
	printf("x_win(disply) = %d \n",display->x_win);

	printf("screen(display) = %d \n",display->screen);
//	vertical(display, 0);
//	horizontal(display,  0);

	printf("key = %d \n", key);
	if (key == 124 && display->x_win < display->screen) // ->
		vertical(display, 10);
	if (key == 123 && display->x_o > 0) // <-
		vertical(display, -10);
	if (key == 125 && display->y_win < display->screen)
		horizontal(display,  10);
	if (key == 126 && display->y_o > 0)
		horizontal(display, -10);
	if (key == 116)
		horizontal(display,50);
	if (key == 12)
	{
		display->echelle /= 2;
		ft_display(display);
	}
	if (key == 13)
	{
		display->echelle *= 2;
		ft_display(display);
	}
	printf("i = %d \n", i);
	//	printf("[%c] \n", key);
//	printf("%d",'b');
	return (0);
}
void	ft_display(t_win *display)
{
	vertical(display,0);
	horizontal(display,0);

}
int		translation(t_win	**display, int transl, int chx)
{
	if (chx == 0)
		(*display)->x_win += transl;
	if (chx == 1)
		(*display)->y_win += transl;
	
	return (0);
}

void	ft_echelle(int *x_win, int *y_win)
{
	int echelle;

	echelle = 50;
	*x_win = echelle * (*x_win);
	*y_win = echelle * (*y_win);
}

void	set_display(t_win *display, int x_win, int y_win, int echelle)
{
	display->x_win = x_win * echelle;
	display->y_win = y_win * echelle;
	display->x_o = 0;
	display->y_o = 0;
	display->echelle = echelle;
}
