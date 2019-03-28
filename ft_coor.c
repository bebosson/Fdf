/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 19:05:50 by bebosson          #+#    #+#             */
/*   Updated: 2019/03/28 20:47:55 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fdf.h"

void	ft_echelle(t_win **display, float echelle)
{
	t_point *tmp;

	tmp = (*display)->tpoint;
	while (tmp->next)
	{
		tmp->x *= echelle;
		tmp->y *= echelle;
		tmp->z *= echelle;
		tmp = tmp->next;
	}
}


void	ft_coor_x(t_win **display, int trans)
{
	t_point *tmp;

	tmp = (*display)->tpoint;
	while (tmp->next)
	{
		tmp->x += trans;
		tmp = tmp->next;
	}
}
void	ft_coor_y(t_win **display, int trans)
{
	t_point *tmp;

	tmp = (*display)->tpoint;
	while (tmp->next)
	{
		tmp->y += trans;
		tmp = tmp->next;
	}
}
void	ft_coor_z(t_win **display, int trans)
{
	t_point *tmp;

	tmp = (*display)->tpoint;
	while (tmp->next)
	{
		tmp->z += trans;
		tmp = tmp->next;
	}
}


void	display_max(t_win **display)
{
	int x_max;
	int y_max;
	t_point *tmp;

	tmp = (*display)->tpoint;
//	x_max = 0;
//	y_max = 0;
	x_max = tmp->x;
	y_max = tmp->y;
	while (tmp->next)
	{
		if (x_max <= tmp->x && tmp->z == 0)
			x_max = tmp->x;
		if (y_max <= tmp->y && tmp->z == 0)
			y_max = tmp->y;
		tmp = tmp->next;
	}
	(*display)->x_max = x_max;
	(*display)->y_max = y_max;
}

void	display_min(t_win **display)
{
	int x_min;
	int y_min;
	t_point *tmp;

	tmp = (*display)->tpoint;
	x_min = tmp->x;
	y_min = tmp->y;
	while (tmp->next)
	{
		if (x_min >= tmp->x && tmp->z == 0)
			x_min = tmp->x;
		if (y_min >= tmp->y && tmp->z == 0)
			y_min = tmp->y;
		tmp = tmp->next;
	}
	(*display)->x_min = x_min;
	(*display)->y_min = y_min;
}

void	fix_display(t_win **display, int echelle, float angle)
{

	(*display)->angle = angle;
	ft_echelle(display, echelle);
//	rotation_list(*display,(*display)->angle);
//	iso_list(*display);
//	display_min(display);
//	display_max(display);
//	centrer(display);
	display_repere(*display);
}

void	centrer(t_win **display)
{
	int delta_x;
	int delta_y;
	int sym_x;
	int sym_y;

	display_min(display);
	display_max(display);
	sym_x = ((*display)->x_max + (*display)->x_min) / 2;

	sym_y = ((*display)->y_max + ((*display)->y_min)) / 2;
	delta_x = ((*display)->screen / 2) - sym_x;

	delta_y = ((*display)->screen/2) - sym_y;

	printf("avant\n");
	printf("----------------------\n");
	printf("screen = %d \n",(*display)->screen);
	printf("x_max = %d \n",(*display)->x_max);
	printf("x_min = %d \n",(*display)->x_min);
	printf("y_max = %d \n",(*display)->y_max);
	printf("y_min = %d \n",(*display)->y_min);
	printf("delta_y = %d \n",delta_y);
	printf("delta_x = %d \n",delta_x);
	printf("sym_x = %d \n",sym_x);
	printf("sym_y = %d \n",sym_y);
	printf("----------------------\n");
//	mlx_string_put((*display)->mlx,(*display)->win_ptr_s, 500, 500,0xFF0000,"0");
	ft_coor_y(display,delta_y);
	ft_coor_x(display,delta_x);
	display_min(display);
	display_max(display);
	sym_x = ((*display)->x_max) + ((*display)->x_min) / 2;

	sym_y = ((*display)->y_max + ((*display)->y_min)) / 2;

	printf("apres\n");
	printf("----------------------\n");
	printf("x_max = %d \n",(*display)->x_max);
	printf("x_min = %d \n",(*display)->x_min);
	printf("y_max = %d \n",(*display)->y_max);
	printf("y_min = %d \n",(*display)->y_min);
	printf("delta_y = %d \n",delta_y);
	printf("delta_x = %d \n",delta_x);
	printf("sym_x = %d \n",sym_x);
	printf("sym_y = %d \n",sym_y);
	printf("----------------------\n");

}
