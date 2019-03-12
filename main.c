/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 06:09:09 by bebosson          #+#    #+#             */
/*   Updated: 2019/03/12 19:24:04 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"
#define TILE_WIDTH_HALF 64
#define TILE_HEIGHT_HALF 32

//Try rotation 30 deg axe des x
//proto en int
void	rotation_x(float teta, int *x, int *y)
{
	float x_p;
	float y_p;

	printf("-------avant rotation-------\n");
	printf("x = %d\n",*x);
	printf("y = %d\n",*y);
	x_p = (*x) * cos(teta) - (*y) * sin(teta);
	y_p = (*x) * sin(teta) + (*y) * cos(teta);
	printf("-------apres rotation-------\n");
	//printf("x_p = %d\n",x_p);
	//printf("y_p = %d\n",y_p);
	*x = x_p * 10;
	*y = y_p * 10;

	printf("x = %d\n",*x);
	printf("y = %d\n",*y);
}
//Try rotation 30 deg axe des y

void	ligne_vert(t_win *display, t_point *list)
{
	int y_i;
	int x_i;
	int y_f;
	int x_f;

	int i;
	
	t_point *tmp;
	t_point *tmp2;
	tmp = list;
	tmp2 = list;
//	y = tmp->y;
	i = 0;
//	rotation_x(0.52,&display->x_win,&display->y_win);
	printf("display->y_win = %d \n",display->y_win);
	while (tmp2->y != display->y_win)
		tmp2 = tmp2->next;

	printf("display->y_win = %d \n",tmp2->y);

	printf("x = %d \n",tmp2->x);
	
	
	while (tmp->y == 0)
	{
		x_i = tmp->x * 20;
		y_i = tmp->y * 20;
		x_f = tmp2->x * 20;
		y_f = tmp2->y * 20;
	//	rotation_x(0.52, &tmp->x, &tmp->y);
	//	rotation_x(0.52, &tmp2->x, &tmp2->y);
		ligne(x_i,y_i,x_f,y_f,display);
		tmp = tmp->next;
		tmp2 = tmp2->next;
		i++;
	}
	printf("i = %d \n",i);
//	rotation(0.52,&(display->x_win),&(tmp->y));
//	rotation(0.52,&(tmp->x),&(display->y_win));

}

void	ligne_hor(t_win *display, t_point *list)
{
	int y_i;
	int x_i;
	int x_f;
	int y_f;
	t_point *tmp;
	
	tmp = list;
//	rotation_x(0.52,&display->x_win,&display->y_win);
	printf("display->y_win = %d \n",display->y_win);
	while (tmp->x != display->x_win && tmp->y != display->y_win)
	{
		x_i = tmp->x;
		y_i = tmp->y;
		while (tmp->x != display->x_win)
			tmp = tmp->next;
		x_f = tmp->x;
		y_f = tmp->y;

//		rotation_x(1.04, &x_i, &y_i);
//		rotation_x(1.04, &x_f, &y_f);
		ligne(x_i * 20,y_i * 20,x_f * 20,y_f * 20,display);
		tmp = tmp->next;
	}
		
	x_i = tmp->x;
	y_i = tmp->y;
		while (tmp->x != display->x_win)
			tmp = tmp->next;

	x_f = tmp->x;
	y_f = tmp->y;
	ligne(x_i * 20,y_i * 20,x_f * 20,y_f * 20,display);
//	printf("display->y_win = %d \n",tmp->y);

//	printf("x = %d \n",tmp->x);
//	printf("i = %d \n",i);
//	rotation(0.52,&(display->x_win),&(tmp->y));
//	rotation(0.52,&(tmp->x),&(display->y_win));

}

void	graphic(t_win *display, int x_win, int y_win, t_point *list)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int x;
	int y;

	display->mlx = mlx_init();
	mlx_ptr = (display)->mlx;
	display->screen = 1000;
	(display)->win_ptr_s = mlx_new_window(mlx_ptr, display->screen, display->screen,"juepee");
	win_ptr = display->win_ptr_s;
//	if (!(tclique =(t_point*)malloc(sizeof(t_point))))
//		return ;
//	display->tpoint = tclique;
	
//	display_repere(list);
	set_display(display, x_win, y_win, 20);
//	ligne_oblique(display,list);
//	ligne (0,64,64,64, display);
//	ligne (64,0,128,0, display);
//	ligne (0,64,64,0, display);
//	ligne (64,64,128,0, display);
	rotation_list(list, display);
//	ligne_hor(display, list);
//	ligne_vert(display, list);

	
	display_repere(list);
//rotation(3.14, 1, 0);
	printf("coucou \n");
		if (mlx_key_hook(win_ptr, deal_key,display) == 0)
		mlx_ptr = NULL;
//	mlx_mouse_hook(win_ptr, barre_pixel,display);
	if (mlx_ptr)
		mlx_loop(mlx_ptr);

}


int		coor_to_graph(char **av)
{
	int x_win;
	int y_win;
	t_win	*display;
	t_point *list;
	display =(t_win *)malloc(sizeof(t_win));
	list = read_to_list(av, &x_win, &y_win); // faire sauter x_win et y_win
	//les renommer x_max et y_max
	//

	graphic(display, x_win, y_win, list);
	return (0);
}


int main(int ac, char **av)
{
	coor_to_graph(av);
		return (0);
}
