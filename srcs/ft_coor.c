/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 19:05:50 by bebosson          #+#    #+#             */
/*   Updated: 2019/06/21 16:55:18 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fdf.h"

void	point_central(t_win **display)
{
	int coor_x;
	int coor_y;	
	t_point *tmp;
	t_point *tmp2;
	tmp = (*display)->tpoint;
	tmp2 = (*display)->tpoint;
	while (tmp->next)
	{
		coor_x = tmp->coor_x;
		coor_y = tmp->coor_y;
		tmp = tmp->next;
	}
	coor_x /= 2;
	coor_y /= 2;
	while (tmp2->coor_x != coor_x || tmp2->coor_y != coor_y)
		tmp2 = tmp2->next;
	(*display)->middle = tmp2;
}

void	ft_echelle(t_win **display, float echelle)
{
	t_point *tmp;

	if ((*display)->echelle == 0)
		(*display)->echelle = 1;
	(*display)->echelle *= echelle;
	tmp = (*display)->tpoint;
	while (tmp->next)
		{
			tmp->x *= echelle;
			tmp->y *= echelle;
			tmp = tmp->next;
		}
	//	free(tmp);
}

void	display_max(t_win **display)
{
	float	x_max;
	float	y_max;
	float	z_max;
	t_point *tmp;

	tmp = (*display)->tpoint;
	x_max = tmp->x;
	y_max = tmp->y;
	z_max = tmp->z;
	while (tmp->next)
	{
		if (x_max <= tmp->x && tmp->z)
			x_max = tmp->x;
		if (y_max <= tmp->y && tmp->z)
			y_max = tmp->y;
		if (z_max <= tmp->z)
			z_max = tmp->z;
		tmp = tmp->next;
	}
	(*display)->x_max = x_max;
	(*display)->y_max = y_max;
	(*display)->z_max = z_max;
}

void	display_min(t_win **display)
{
	float x_min;
	float y_min;
	t_point *tmp;

	tmp = (*display)->tpoint;
	x_min = tmp->x;
	y_min = tmp->y;
	while (tmp->next)
	{
		if (x_min >= tmp->x)
			x_min = tmp->x;
		if (y_min >= tmp->y)
			y_min = tmp->y;
		tmp = tmp->next;
	}
	(*display)->x_min = x_min;
	(*display)->y_min = y_min;
}

void		display_point(t_point *tmp)
{
		printf("x = %.5f / ", tmp->x);
		printf("y = %.5f / ", tmp->y);
		printf("z = %.5f \n ", tmp->z);
		printf("coor_x = %d /", tmp->coor_x);
		printf("coor_y = %d / \n",tmp->coor_y);
	//	printf("couleur = %d / \n", tmp->couleur);
	//	printf("r =  %d / \n", tmp->r);
	//	printf("g =  %d / \n", tmp->g);
	//	printf("b =  %d / \n", tmp->b);
}

void	set_win_info(t_win *display)
{
	char *r;
	mlx_string_put (display->mlx, display->win, 0, 0, 0xFF77FF,"z -> zoom");
	mlx_string_put (display->mlx, display->win, 0, 20, 0xFF99FF,"+ -> zoom avant -> - -> zoom arriere" );
	mlx_string_put (display->mlx, display->win, 0, 40, 0xFF99FF,"m -> menu" );
	mlx_string_put (display->mlx, display->win, 0, 60, 0xFF99FF,"t->translation (fleches)");
	mlx_string_put (display->mlx, display->win, 0, 80, 0xFF99FF,"rotation selon y (y)");
	mlx_string_put (display->mlx, display->win, 0, 100, 0xFF99FF,"6 -> avant");
	mlx_string_put (display->mlx, display->win, 0, 120, 0xFF99FF,"7 -> arriere");
	mlx_string_put (display->mlx, display->win, 0, 140, 0xFF99FF,"rotation selon x (x)");
	mlx_string_put (display->mlx, display->win, 0, 160, 0xFF99FF,"s -> avant");
	mlx_string_put (display->mlx, display->win, 0, 180, 0xFF99FF,"d -> arriere");
	mlx_string_put (display->mlx, display->win, 0, 200, 0xFF99FF,"rotation selon x (x)");
	mlx_string_put (display->mlx, display->win, 0, 220, 0xFF99FF,"s -> avant");
	mlx_string_put (display->mlx, display->win, 0, 240, 0xFF99FF,"d -> arriere");
	mlx_string_put (display->mlx, display->win, 0, 260, 0xFF99FF,"couleur (c) (fleches)");
	mlx_string_put (display->mlx, display->win, 0, 280, 0xFF99FF,"e -> rouge = ");
	mlx_string_put (display->mlx, display->win, 0, 320, 0xFF99FF,"g -> vert = ");
	mlx_string_put (display->mlx, display->win, 0, 340, 0xFF99FF,"b -> bleue = ");
}

void		display_borne(t_win *display)
{
	char *r;
	char *g;
	char *b;
//	printf("x_max = %.5f \n",display->x_max);
//	printf("y_max = %.5f \n",display->y_max);
	//	printf("x_min = %.5f \n",display->x_min);
	//	printf("y_min = %.5f \n",display->y_min);
	//	printf("couleur = %d \n",display->couleur);
//	printf("display->echelle = %.5f\n",display->echelle);
//	printf("display->iso = %d\n",display->iso);
	mlx_clear_window(display->mlx, display->win);
	set_win_info(display);
	r = ft_itoa(display->tpoint->r);
	mlx_string_put (display->mlx, display->win, 120, 280, 0xFF99FF,r);
	g = ft_itoa(display->tpoint->g);
	mlx_string_put (display->mlx, display->win, 120, 320, 0xFF99FF,g);
	b = ft_itoa(display->tpoint->b);
	mlx_string_put (display->mlx, display->win, 120, 340, 0xFF99FF,b);
	printf("r =  %d / \n", display->tpoint->r);
	printf("g =  %d / \n", display->tpoint->g);
	printf("b =  %d / \n", display->tpoint->b);
}

void		display_repere(t_win *display)
{
	t_point *tmp;

	tmp = display->tpoint;
	display_max(&display);
	display_min(&display);
//	while (tmp->next)
//	{
//		display_point(tmp);
//		tmp = tmp->next;
//	}
	display_borne(display);
}
