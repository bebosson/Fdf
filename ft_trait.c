/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trait.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 21:13:22 by bebosson          #+#    #+#             */
/*   Updated: 2019/02/16 22:13:02 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	barre_pixel(int button, int x, int y, t_win *display)
{
	float ratio;
	float dx;
	float dy;
	display->x_win = 500;
	display->y_win = 0;
	
	dx = (float)display->x_win - x;
	dy = (float)display->y_win - y;
	ratio = dy / dx;

	printf("ratio %.5f \n", ratio);
//	ratio = (float) y / x;
	if (fabsf(ratio) < 1 && ratio > 0) //
		trait(x , y,ratio, display,0);
	else if(fabsf(ratio) > 1 && ratio > 0)
		trait(y , x, 1 / ratio, display,1);
/*	else if(fabsf(ratio) < 1 && ratio < 0)
	{
		if (dx < 0)

	}
*/	//else if (ratio == 1 && x == y)
		//trait
	

	return (0);
}

int	trait(int max, int min, float ratio, t_win *display, int toto)
{
	float e;
	float e2;
	int max_v;
	int min_v;
	
	printf("x = %d || y = %d \n", max,min);
	e = 0;
	e2 = -1; // 1
	max_v = display->x_win;
	min_v = display->y_win;
	while (max_v < max)
	{
		if (toto == 0)
			mlx_pixel_put(display->mlx, display->win_ptr_s, max_v,min_v, 0xFF0000);
		if (toto != 0)
			mlx_pixel_put(display->mlx, display->win_ptr_s, min_v, max_v, 0xFF0000);
		e = e + ratio;
		if (e >= 0.5) //-0.5
		{
			min_v++;
			e = e + e2;
		}
		printf("max_v = %d || min_v = %d \n",max_v,min_v);
		max_v++;
	}
	printf("toto %d \n",toto);
	printf("x = %d || y = %d \n", max,min);
	printf("max_v = %d || min_v = %d \n",max_v,min_v);
	printf("x_win = %d \n",display->x_win);
	printf("y_win = %d \n",display->y_win);
	printf("ratio %.5f \n", ratio);
	return (0);

}
