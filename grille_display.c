/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grille_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:38:33 by bebosson          #+#    #+#             */
/*   Updated: 2019/02/20 16:10:49 by bebosson         ###   ########.fr       */
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

int		deal_key(int key, t_win *display)
{
	int i;
	
	i = 0;
//	vertical(display, 0);
//	horizontal(display,  0);
	display_display(display);
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
		ft_echelle(display, 0.5);
		//display->echelle /= 2;
		ft_display(display);
	}
	if (key == 13)
	{
		ft_echelle(display, 2);
		ft_display(display);
	}
	if (key == 14)
	{
		mlx_clear_window(display->mlx,display->win_ptr_s);
	}
//		while (y <= display->y_win)
	
//	printf("i = %d \n", i);
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
