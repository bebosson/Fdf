/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trait.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 21:13:22 by bebosson          #+#    #+#             */
/*   Updated: 2019/03/08 14:21:52 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	ft_swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

int	trait_up(int max, int min, float ratio, t_win *display, float toto)
{
	float e;
	float e2;
	int max_v;
	int min_v;
	
	printf("x = %d || y = %d \n", max,min);
	e = 0;
	e2 = -1;
	max_v = display->x_win;
	min_v = display->y_win;
	if (toto == -1 || toto == 2)
		ft_swap(&max_v,&min_v);
	while (max_v != max && max_v >= 0 && min_v >= 0)
	{
		if (toto == 1 || toto == -1)
			mlx_pixel_put(display->mlx, display->win_ptr_s, max_v,min_v, 0xFF0000);
		if (toto == 2)
			mlx_pixel_put(display->mlx, display->win_ptr_s, min_v, max_v, 0xFF0000);
		e = e + fabsf(ratio);
		if (e >= 0.5) //-0.5
		{
			min_v += (toto / fabsf(toto));
			e = e + e2;
		}
		printf("max_v = %d || min_v = %d \n",max_v,min_v);
		max_v += (toto / fabsf(toto));
	}
	return (0);
}

int	trait_down(int max, int min, float ratio, t_win *display, float toto)
{
	float e;
	float e2;
	int max_v;
	int min_v;
	int i;
	e = 0;
	e2 = 1; // 1
	i = 0;
	max_v = display->x_win;
	min_v = display->y_win;
	if (toto == -2 || toto == 2)
	{
		ft_swap(&max_v,&min_v);
		printf("AVANT : max_v = %d || min_v = %d \n : ",max_v,min_v);
	}
	
	printf("max = %d || min = %d \n", max,min);
//	printf("AVANT : max_v = %d || min_v = %d \n : ",max_v,min_v);
	while (max_v != max)
	{
	//	printf("toto %.5f\n",toto);
		printf("max_v = %d || min_v = %d \n",max_v,min_v);
		if (toto == -2 || toto == -1)
			mlx_pixel_put(display->mlx, display->win_ptr_s, max_v,min_v, 0xFF0000);
		if (toto == 2 || toto == 2)
			mlx_pixel_put(display->mlx, display->win_ptr_s, min_v, max_v, 0xFF0000);
		e = e + ratio;
	//	break ;
		if (e <= -0.5) //-0.5
		{
			min_v += (toto / fabsf(toto));
			e = e + e2;
		}
//		printf("max_v = %d || min_v = %d \n",max_v,min_v);
		max_v -= toto / fabsf(toto);
	//	break ;
	}

	printf("e =  %.5f \n",e);
	printf("toto %f \n",toto);
	printf("x = %d || y = %d \n", max,min);
	if (toto == 2)
		printf("coucou \n");
	printf("APRES max_v = %d || min_v = %d \n",max_v,min_v);
	printf("x_win = %d \n",display->x_win);
	printf("y_win = %d \n",display->y_win);
	printf("ratio %.5f \n", ratio);
	return (0);
}


int	barre_pixel(int button, int x, int y, t_win *display)
{
	float ratio;
	float dx;
	float dy;
	display->x_win = 50;
	display->y_win = 500;
	
	dx = (float)display->x_win - x;
	dy = (float)display->y_win - y;
	ratio = dy / dx;

	printf("ratio %.5f \n", ratio);
	printf("1 / ratio %.5f \n", 1 / ratio);
	printf("x = %d \n", x);
	printf("y =  %d \n", y);
	printf("dx = %.5f \n", dx);
	printf("dy = %.5f \n", dy);
	ft_putendl("----------------------");
	//	ratio = (float) y / x;
	if (fabsf(ratio) < 1 && ratio > 0) //
		trait_up(x , y,ratio, display,1);
	else if(fabsf(ratio) > 1 && ratio > 0)
		trait_up(y , x, 1 / ratio, display,2);
	else if(fabs(ratio) < 1 && ratio < 0)
		trait_down(x , y, ratio, display,-1);
	else if(fabs(ratio) > 1 && ratio < 0)
		trait_down(x , y, 1 / ratio, display,2);

	printf("ratio %.5f \n", ratio);
	printf("ratio %.5f \n", 1 / ratio);
	printf("x = %d \n", x);
	printf("y =  %d \n", y);

	return (0);
}

