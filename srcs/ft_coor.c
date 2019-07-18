/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:44:16 by bebosson          #+#    #+#             */
/*   Updated: 2019/07/18 13:15:02 by bebosson         ###   ########.fr       */
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
		printf("coor_y = %d /",tmp->coor_y);
		printf("z_o = %.0f \n",tmp->z_o); 
	//	printf("couleur = %d / \n", tmp->couleur);
	//	printf("r =  %d / \n", tmp->r);
	//	printf("g =  %d / \n", tmp->g);
	//	printf("b =  %d / \n", tmp->b);
}

void	set_win_info(t_win *display)
{
	char	*r;
	int		couleur_txt;

	couleur_txt = 0xffffff;
	mlx_string_put (display->mlx, display->win, 0, 0, display->color->menu,"(1) m -> menu" );
	mlx_string_put (display->mlx, display->win, 20, 20, display->color->zoom,"(2) z -> zoom");
	mlx_string_put (display->mlx, display->win, 40, 40, display->color->zoom_action,"(3) + -> zoom avant -> - -> zoom arriere" );
	mlx_string_put (display->mlx, display->win, 20, 60, display->color->translation,"(2) t->translation ((3) fleches)");
	mlx_string_put (display->mlx, display->win, 20, 80, display->color->rotation,"(2) rotation (R)");
	mlx_string_put (display->mlx, display->win, 40, 100, display->color->rotation_y,"(3) rotation selon y (y)");
	mlx_string_put (display->mlx, display->win, 60, 120, couleur_txt,"(4) 6 -> avant");
	mlx_string_put (display->mlx, display->win, 60, 140, couleur_txt,"(4) 7 -> arriere");
	mlx_string_put (display->mlx, display->win, 40, 160, display->color->rotation_x,"(3) rotation selon x (x)");
	mlx_string_put (display->mlx, display->win, 60, 180, couleur_txt,"(4) s -> avant");
	mlx_string_put (display->mlx, display->win, 60, 200, couleur_txt,"(4) d -> arriere");
	mlx_string_put (display->mlx, display->win, 40, 220, display->color->rotation_z,"(3) rotation selon z (f)");
	mlx_string_put (display->mlx, display->win, 60, 240, couleur_txt,"(4) q -> avant");
	mlx_string_put (display->mlx, display->win, 60, 260, couleur_txt,"(4) a -> arriere");
	mlx_string_put (display->mlx, display->win, 40, 280, display->color->couleur,"(2) couleur (c) (fleches)");
	mlx_string_put (display->mlx, display->win, 60, 300, display->color->couleur_r,"(3) e -> rouge = ");
	mlx_string_put (display->mlx, display->win, 60, 320, display->color->couleur_g,"(3) g -> vert  = ");
	mlx_string_put (display->mlx, display->win, 60, 340, display->color->couleur_b,"(3) b -> bleue = ");
	mlx_string_put (display->mlx, display->win, 0, 360, couleur_txt,"*Pour toute action, veuillez presser dans l'ordre: ");
	mlx_string_put (display->mlx, display->win, 80, 380, couleur_txt,"(1)+(2)+(3)+(4)");
}

void	set_colour_info(t_win *display)
{
	display->color->menu = 0xFFFFFF;
	display->color->translation = 0xFFFFFF;
	display->color->zoom = 0xFFFFFF;
	display->color->zoom_action = 0xFFFFFF;
	display->color->rotation = 0xFFFFFF;
	display->color->rotation_x = 0xFFFFFF;
	display->color->rotation_y = 0xFFFFFF;
	display->color->rotation_z = 0xFFFFFF;
	display->color->couleur_r = 0xFFFFFF;
	display->color->couleur_g = 0xFFFFFF;
	display->color->couleur_b = 0xFFFFFF;
	display->color->couleur = 0xFFFFFF;
}

void		display_borne(t_win *display)
{
	char *r;
	char *g;
	char *b;
	int couleur_txt = 0xFFFFFF;

	mlx_clear_window(display->mlx, display->win);
	set_win_info(display);
	r = ft_itoa(display->tpoint->r);
	free(r);
	mlx_string_put (display->mlx, display->win, 230, 300, display->color->couleur_r,r);
	g = ft_itoa(display->tpoint->g);
	mlx_string_put (display->mlx, display->win, 230, 320, display->color->couleur_g,g);
	free(g);
	b = ft_itoa(display->tpoint->b);
	mlx_string_put (display->mlx, display->win, 230, 340, display->color->couleur_b,b);
	free(b);
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
//	display_borne(display);
}
