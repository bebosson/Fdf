/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligne_juepee.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 23:19:37 by bebosson          #+#    #+#             */
/*   Updated: 2019/03/28 23:31:37 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"
void	inf(int dx, int dy, t_win *display, int i)
{
	int		xinc;
	int		yinc;
	int		cumul;
	int		xi;
	int		yi;

	xi = display->x_o;
	yi = display->y_o;
	xinc = ( dx > 0 ) ? 1 : -1;
	yinc = ( dy > 0 ) ? 1 : -1;
	cumul = dy / 2 ;
	while (i <= dy)
	{
		yi += yinc;
		cumul += dx;
		if (cumul >= dy)
		{
			cumul -= dy;
			xi += xinc;
		}
			mlx_pixel_put(display->mlx,display->win_ptr_s, xi, yi, 0xFF0000);
		i++;
	}
}

void	sup(int dx, int dy, t_win *display, int i)
{
	int		xinc;
	int		yinc;
	int		cumul;
	int		xi;
	int		yi;

	xinc = ( dx > 0 ) ? 1 : -1;
	yinc = ( dy > 0 ) ? 1 : -1;
	xi = display->x_o;
	yi = display->y_o;
	cumul = dx / 2 ;
	while (i <= dx)
	{
		xi += xinc ;
		cumul += dy ;
		if (cumul >= dx)
		{
			cumul -= dx;
			yi += yinc;
		}
		mlx_pixel_put(display->mlx,display->win_ptr_s, xi, yi, 0xFF0000);
		i++;
	}
}
