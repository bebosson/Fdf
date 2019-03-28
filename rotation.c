/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:05:55 by bebosson          #+#    #+#             */
/*   Updated: 2019/03/28 20:53:52 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

//Try rotation 30 deg axe des x
//proto en int
void	round_value(float x_p, float y_p, int *x, int *y)
{
	int rest_x;
	int rest_y;
	int cast_x;
	int cast_y;
//	printf("x_p = %.5f \n",x_p);
//	printf("y_p = %.5f \n",y_p);
	cast_x = (int)x_p;
	cast_y = (int)y_p;
	rest_x = (int)(x_p * 1000) % 1000;
	rest_y = (int)(y_p * 1000) % 1000;
//	printf("cast_x = %d \n",cast_x);
//	printf("cast_y = %d \n",cast_y);
//	printf("rest_x = %d \n",rest_x);
//	printf("rest_y = %d \n",rest_y);
	if (rest_x > 499)
		*x = (int)x_p + 1;
	else if (abs(rest_x) > 499 && rest_x < 0)
		*x = (int)x_p - 1;
	else
		*x = (int)x_p;
	if (rest_y > 499)
		*y = (int)y_p + 1;
	else if (abs(rest_y) > 499 && rest_y < 0)
		*y = (int)y_p - 1;
	else
		*y = (int)y_p;
//	printf("x = %d \n", *x);
//	printf("y = %d \n", *y);
}

void	rotation_z(float teta, float *x, float *y, t_win *display)
{
	float x_p;
	float y_p;
	int sym_x;
	int sym_y;
//	printf("x = %d\n",*x);
//	printf("y = %d\n",*y);
	display_min(&display);
	display_max(&display);
//	sym_x = ((display)->x_max - (display)->x_min) / 2;

//	sym_y = ((display)->y_max - (display)->y_min) / 2;
	x_p = ((*x)) * cos(teta) - ((*y)) * sin(teta);
	y_p = ((*x)) * sin(teta) + ((*y)) * cos(teta);
	//x_p += 500;
	//y_p += 500;
	//	printf("-------apres rotation-------\n");
//	printf("x_p = %.5f\n",x_p);
//	printf("y_p = %.5f\n",y_p);
//	round_value(x_p,y_p,x,y);
	*x = x_p;
	*y = y_p;
//	printf("x = %d\n",*x);
//	printf("y = %d\n",*y);
}

void	rotation_list_z(t_win *display, float angle)
{
	t_point *tmp;

	tmp = display->tpoint;
	while (tmp->next)
	{
		rotation_z(angle,&tmp->x,&tmp->y, display);
		tmp = tmp->next;
	}
}

void	rotation_x(float teta, float *y, float *z, t_win *display)
{
	float y_p;
	float z_p;
	int sym_x;
	int sym_y;
//	printf("x = %d\n",*x);
//	printf("y = %d\n",*y);
	display_min(&display);
	display_max(&display);
//	sym_x = ((display)->x_max - (display)->x_min) / 2;

//	sym_y = ((display)->y_max - (display)->y_min) / 2;
	y_p = ((*y)) * cos(teta) + ((*z)) * sin(teta);
	z_p = ((*z)) * cos(teta) - ((*y)) * sin(teta);
	//x_p += 500;
	//y_p += 500;
	//	printf("-------apres rotation-------\n");
//	printf("x_p = %.5f\n",x_p);
//	printf("y_p = %.5f\n",y_p);
//	round_value(x_p,y_p,x,y);
	*y = y_p;
	*z = z_p;
//	printf("x = %d\n",*x);
//	printf("y = %d\n",*y);
}

void	rotation_list_x(t_win *display, float angle)
{
	t_point *tmp;

	tmp = display->tpoint;
	while (tmp->next)
	{
		rotation_z(angle,&tmp->y,&tmp->z, display);
		tmp = tmp->next;
	}
}

void	rotation_y(float teta, float *x, float *z, t_win *display)
{
	float x_p;
	float z_p;
//	printf("x = %d\n",*x);
//	printf("y = %d\n",*y);
//	sym_x = ((display)->x_max - (display)->x_min) / 2;

//	sym_y = ((display)->y_max - (display)->y_min) / 2;
	x_p = ((*x)) * cos(teta) - ((*z)) * sin(teta);
	z_p = ((*x)) * sin(teta) + ((*z)) * cos(teta);
	//x_p += 500;
	//y_p += 500;
	//	printf("-------apres rotation-------\n");
//	printf("x_p = %.5f\n",x_p);
//	printf("y_p = %.5f\n",y_p);
//	round_value(x_p,y_p,x,y);
	*x = x_p;
	*z = z_p;
//	printf("x = %d\n",*x);
//	printf("y = %d\n",*y);
}

void	rotation_list_y(t_win *display, float angle)
{
	t_point *tmp;

	tmp = display->tpoint;
	while (tmp->next)
	{
		rotation_z(angle,&tmp->x,&tmp->z, display);
		tmp = tmp->next;
	}
}

