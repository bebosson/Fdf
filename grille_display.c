/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grille_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:38:33 by bebosson          #+#    #+#             */
/*   Updated: 2019/02/17 00:58:04 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	vertical(t_win *display, int x_ref, int y_ref)
{
	int x;
	int y;

//	display->x_o = 0;
	printf("toto \n");
	printf("x_o(disply) = %d \n",display->x_o);
	printf("x_win(disply) = %d \n",display->x_win);
	while (display->x_o < display->x_win)
	{
		display->y_o = y_ref;
		while (++display->y_o < display->y_win)
			mlx_pixel_put(display->mlx,display->win_ptr_s, display->x_o, display->y_o, 0xFF0000);
		display->x_o += 100;
	}
	display->y_o = y_ref;
		while (++display->y_o < display->y_win)
			mlx_pixel_put(display->mlx,display->win_ptr_s, display->x_o,display->y_o, 0xFF0000);

	display->x_o = x_ref;
	display->y_o = y_ref;
}

void	horizontal(t_win *display, int y_ref, int x_ref)
{
	int x;
	int y;

//	display->x_o = 0;
	printf("toto \n");
	printf("y_o(disply) = %d \n",display->y_o);
	printf("y_win(disply) = %d \n",display->y_win);
	while (display->y_o < display->y_win)
	{
		display->x_o = x_ref;
		while (++display->x_o < display->x_win)
			mlx_pixel_put(display->mlx,display->win_ptr_s, display->x_o, display->y_o, 0xFF0000);
		display->y_o += 100;
	}
	display->x_o = x_ref;
		while (++display->x_o < display->x_win)
			mlx_pixel_put(display->mlx,display->win_ptr_s, display->x_o,display->y_o, 0xFF0000);

	display->y_o = y_ref;
	display->x_o = x_ref;
}
int		deal_key(int key, t_win *display)
{
	int		stat_x_o;
	int		stat_y_o;
	int i;
	
	i = 0;
;
//	printf("y_o(disply) = %d \n",display->y_o);
//	printf("y_win(disply) = %d \n",display->y_win);
//	printf("x_o(disply) = %d \n",display->x_o);
//	printf("x_win(disply) = %d \n",display->x_win);

	stat_x_o = display->x_o;
	stat_y_o = display->y_o;
	vertical(display, stat_x_o, stat_y_o);
	horizontal(display, stat_y_o, stat_x_o);

	printf("key = %d \n", key);
	if (key == 124) // ->
	{
		display->x_win += 50;
		display->x_o += 50;
//		stat_x_o = display->x_o;
		i++;
		printf("i = %d", display->x_win);
	}

	if (key == 123) // <-
	{
		display->x_o -= 50;
		display->x_win -= 50;
//		stat_x_o = display->x_o;
		i++;
		printf("i = %d", display->x_win);
	}

	if (key == 125)
	{
		display->y_win += 50;
		display->y_o += 50;
//		stat_y_o = display->y_o;
		i++;
		printf("i = %d", display->x_win);
		printf("i = %d", display->y_win);
	}
	if (key == 126)
	{
		display->y_win -= 50;
		display->y_o -= 50;
//		stat_y_o = display->y_o;
		i++;
		printf("i = %d", display->y_win);
	}
	if (key == 49)
	{

//		ft_echelle(&display->x_win,&display->y_win);
	}

	printf("i = %d \n", i);
	mlx_clear_window(display->mlx,display->win_ptr_s);
	//	printf("[%c] \n", key);
//	printf("%d",'b');
	return (0);
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

	echelle = 100;
	*x_win = echelle * (*x_win);
	*y_win = echelle * (*y_win);
}
