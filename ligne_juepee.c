/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligne_juepee.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 23:19:37 by bebosson          #+#    #+#             */
/*   Updated: 2019/04/01 17:26:23 by bebosson         ###   ########.fr       */
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

	mlx_pixel_put(display->mlx,display->win_ptr_s, x, y, 0xFF0000);
	if ( dx > dy )
	{
		cumul = dx / 2 ;
		for ( i = 1 ; i <= dx ; i++ ) 
		{
			x += xinc ;
			cumul += dy ;
			if ( cumul >= dx ) 
			{
				cumul -= dx ;
				y += yinc ; 
			}
			mlx_pixel_put(display->mlx,display->win_ptr_s, x, y, 0xFF0000);
			 ; 
		}
	}
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

void	sup(int dx, int dy, t_win *display, int i)
{
	int		cumul;
	int		xi; //display->x_o?
	int		yi; //display->y_o?
//	int couleur;

	xi = display->x_o;
	yi = display->y_o;
	cumul = dx / 2 ;
	while (i <= dx)
	{
		xi += display->xinc ;
		cumul += dy ;
		if (cumul >= dx)
		{
			cumul -= dx;
			yi += display->yinc;
		}
		mlx_pixel_put(display->mlx,display->win_ptr_s, xi, yi, display->couleur);
		i++;
	}
}

void	inf(int dx, int dy, t_win *display, int i)
{
	int		cumul;
	int		xi;
	int		yi;

	xi = display->x_o;
	yi = display->y_o;
	cumul = dy / 2 ;
	while (i <= dy)
	{
		yi += display->yinc;
		cumul += dx;
		if (cumul >= dy)
		{
			cumul -= dy;
			xi += display->xinc;
		}
			mlx_pixel_put(display->mlx,display->win_ptr_s, xi, yi, display->couleur);
		i++;
	}
}

void	ligne_2(t_point *pt1, t_point *pt2, t_win *display)
{

	int		dx;
	int		dy;
	int		i;

	i = 1;
	dx = pt2->x - pt1->x;
	dy = pt2->y - pt1->y;
	display->x_o = pt1->x;
	display->y_o = pt1->y;
	mlx_pixel_put(display->mlx,display->win_ptr_s, display->x_o, display->y_o, pt1->couleur);
	display->xinc = (dx > 0) ? 1 : -1;
	display->yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
//	display->couleur = ft_atoi_base("FFFFFF","0123456789ABCDEF");
//	printf("couleur = %d \n", display->couleur);
	
	display->couleur = pt1->couleur;
	if (dx > dy)
		sup(dx, dy, display, 1);
	else
		inf(dx, dy, display, 1);
}
/*
int main(int ac, char **av)
{
	t_win	*display;
	t_point *list;
	display =(t_win *)malloc(sizeof(t_win));
	display->tpoint = read_to_list(av, display);
	display->mlx = mlx_init();
	display->screen = 2000;
	(display)->win_ptr_s = mlx_new_window(display->mlx, display->screen, display->screen,"FDF");
	
	t_point *tmp_1 = display->tpoint;
	t_point *tmp_2 = display->tpoint->next;
	tmp_2->x = 1000;
	tmp_2->y = 1000;
	ligne_2(tmp_1, tmp_2, display);
	ligne(tmp_1->x, tmp_1->y, tmp_2->x, tmp_2->y, display);
	if (display->mlx)
		mlx_loop(display->mlx);

}

*/
