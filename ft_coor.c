/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 19:05:50 by bebosson          #+#    #+#             */
/*   Updated: 2019/06/15 20:17:16 by bebosson         ###   ########.fr       */
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
	int echelle_max;
	int echelle_min;

	if ((*display)->echelle == 0)
		(*display)->echelle = 1;
	(*display)->echelle *= echelle;
//	if ((*display)->echelle > 32 || (*display)->echelle < 2)
//	{
//		(*display)->echelle = 4;
//		echelle = (*display)->echelle;
//		ft_origin(display);
//		if ((*display)->iso == 1)
//			iso_list(*display);
//		ft_origin_z(display);
//	}
		
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

void		display_borne(t_win *display)
{
//	printf("x_max = %.5f \n",display->x_max);
//	printf("y_max = %.5f \n",display->y_max);
	//	printf("x_min = %.5f \n",display->x_min);
	//	printf("y_min = %.5f \n",display->y_min);
	//	printf("couleur = %d \n",display->couleur);
//	printf("display->echelle = %.5f\n",display->echelle);
//	printf("display->iso = %d\n",display->iso);
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
