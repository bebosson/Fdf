/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 03:25:03 by bebosson          #+#    #+#             */
/*   Updated: 2019/02/15 22:50:05 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	ft_print_tables(char **tab_pts)
{
	int x;

	x = -1;
	while (tab_pts[++x])
		printf("%s",tab_pts[x]);

}

t_point		*init_repere(char **tab_pts, t_point **list, int y)
{
	int x;
	t_point *tmp;
	t_point *elem;

	tmp = *list;
	x = -1;
	while (tab_pts[++x])
	{
		tmp->z = ft_atoi(tab_pts[x]);
		tmp->x = x;
		tmp->y = y;
		elem = (t_point*)malloc(sizeof(t_point));
		tmp->next = elem;
		tmp = tmp->next;
	}

	return (tmp);
	//tmp->next = NULL;
}

void		display_repere(t_point *list)
{
	t_point *tmp;

	tmp = list;
	while (tmp->next)
	{
		printf("x = %d / ", tmp->x);
		printf("y = %d / ", tmp->y);
		printf("z = %d / \n", tmp->z);
		tmp = tmp->next;
	}
}

int		ft_x_max(t_point *list)
{
	int x_max;
	t_point *tmp;
	
	tmp = list;
	x_max = tmp->x;
	while (tmp->next)
	{
		if (x_max < tmp->x)
			x_max = tmp->x;
		tmp = tmp->next;
	}
	return (x_max);

}
void	ft_echelle(int *x_win, int *y_win)
{
	int echelle;

	echelle = 100;
	*x_win = echelle * (*x_win);
	*y_win = echelle * (*y_win);
}
void	read_to_list(char **av, int *x_max, int *y_max)
{
	int y;
	char **tab_pts;
	int fd = open(av[1] ,O_RDONLY);
	char *line;
	t_point *list;
	t_point *tmp;

	y = -1;
	list = (t_point *)malloc(sizeof(t_point));
	tmp = list;
	while (get_next_line(fd, &line) > 0)
	{
		tab_pts = ft_strsplit(line, ' ');
		tmp = init_repere(tab_pts,&tmp,++y);
	}
	display_repere(list);
	*x_max = ft_x_max(list);
	*y_max = y;

}
void	vertical(void *mlx_ptr, void *win_ptr, int x_win, int y_win)
{
	int x;
	int y;

	x = 0;
	while (x < x_win)
	{
		y = -1;
		while (++y < y_win)
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);
		x += 100;
	}
	y = -1;
		while (++y < y_win)
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);

}

void	horizontal(void *mlx_ptr, void *win_ptr, int x_win, int y_win)
{
	int x;
	int y;

	y = 0;
	while (y < y_win)
	{
		x = -1;
		while (++x < x_win)
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);
		y += 100;
	}
	x = -1;
	while (++x < x_win)
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);

}

int		deal_key(int key, t_win *display)
{
	void	*mlx;
	void	*win;

	printf("key = %d \n", key);
	mlx = display->mlx;
	win = display->win_ptr_s;
	if (key == 12)
	{
		mlx_destroy_window(mlx, win);
		return (0);
	}
//	printf("[%c] \n", key);
//	printf("%d",'b');
	return (0);
}

int	barre_pixel(int button, int x, int y, t_win *display)
{
	void	*mlx_ptr;
	void	*win_ptr;
	float ratio; //e1
	float e,e2;
	int x_v;
	int y_v;
	mlx_ptr = display->mlx;
	win_ptr = display->win_ptr_s;
//	int i;
	//SIGNE <=> SENS
	//
	ratio = (float) y / x;
//	printf("ratio %.6f \n",ratio);
//	if (ratio < 1)
//		printf("1/ratio = %6.f \n",(float) 1/ratio);
//	if (ratio < 0)
//		return (0);
	printf("x = %d || y = %d \n", x,y);
//	while ((float)i * ratio < 1)
//		i++;
//	printf("i = %d \n", i);
	// on part de 0
	e = 0;
	e2 = -1;
	x_v = 0;
	y_v = 0;
	while (x_v < x)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x_v, y_v, 0xFF0000);
		e = e + ratio;
		printf("e = %3.f \n",e);
		if (e >= 0.5)
		{
			y_v++;
			e = e + e2;
		}
		printf("x_v = %d || y_v = %d \n",x_v,y_v);
		x_v++;
	}

/*
	while ( < )
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);
*/
	return (0);

}


int		deal_mouse_display(int button, int x, int y, t_win *display)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int x_o;
	int y_o;

	mlx_ptr = display->mlx;
	win_ptr = display->win_ptr_s;
	printf("button = %d \n", button);
	x_o = x + 400;
	x = x - 400;
	while (++x < x_o)
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);
	y_o = y + 400;
	y = y - 400;
	x = x - 400;
	while (++y < y_o)
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);

	return (0);
}

/*
void	draw_r_hrz(t_win *display, int ratio, int x_orig)
{
	int x;
	int y;

	x = 0;
	while (x < x_win)
	{
		y = -1;
		while (++y < ratio)
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);
		x += 100;
	}
	y = -1;
		while (++y < y_win)
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);

}


void	get_ratio(t_win *display)
{
	int x_o_o;
	int x;
	int y_o_o;
	int y;
	double r;

	x_o_o = display->tpoint->prev->x;
	x = display->tpoint->x;
	y_o_o = display->tpoint->prev->y;
	y = display->tpoint->y;
	r = abs(x - x_o_o) / (y - y_o_o);
	r > 1 ? draw_line(r, 1) : draw_line(1, 1 / r);
}
*/
int		deal_mouse_list(int button, int x, int y, t_win *display)
{
	t_point *elem;

	if (!(elem =(t_point*)malloc(sizeof(t_point))))
		return (0);

	display->tpoint->x = x;
	display->tpoint->y = y;
	
	printf("x = %d || y = %d \n",display->tpoint->x,display->tpoint->y);
	display->tpoint->next = elem;
	elem->prev = display->tpoint;
	display->tpoint = display->tpoint->next;
	
	if (display->tpoint->prev)

	printf("x = %d || y = %d \n", x,y);

	return (0);
}



void	graphic(t_win *display, int x_win, int y_win)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int x;
	int y;
	t_point *tclique;

	display->mlx = mlx_init();
	mlx_ptr = (display)->mlx;
//	mlx_ptr = mlx_init();
	(display)->win_ptr_s = mlx_new_window(mlx_ptr, 200, 200,"juepee");
	win_ptr = display->win_ptr_s;
	printf("x_win(disply) = %d \n",display->x_win);
	if (!(tclique =(t_point*)malloc(sizeof(t_point))))
		return ;
	display->tpoint = tclique;
	tclique->prev = NULL;
	tclique->next = NULL;
	/////////////////////////////////////////

//	vertical(mlx_ptr, win_ptr, x_win, y_win);
//	horizontal(mlx_ptr, win_ptr, x_win, y_win);
//	if (mlx_key_hook(win_ptr, deal_key,display) == 0)
//		mlx_ptr = NULL;
//	mlx_key_hook(win_ptr, deal_mouse_display,(void *)0);
	
	mlx_mouse_hook(win_ptr, deal_mouse_display,display);
	mlx_mouse_hook(win_ptr, barre_pixel,display);
	//		mlx_string_put(mlx_ptr, win_ptr,x,200,0xFFD700,"ox");
	//	mlx_new_image(mlx_ptr, 300, 300);
	if (mlx_ptr)
		mlx_loop(mlx_ptr);

}


int		coor_to_graph(char **av)
{
	int x_win;
	int y_win;
	t_win	*display;

	display =(t_win *)malloc(sizeof(t_win));
	read_to_list(av, &x_win, &y_win);
	ft_echelle(&x_win, &y_win);
	display->x_win = x_win;
	graphic(display, x_win, y_win);
	return (0);
}


int main(int ac, char **av)
{
	coor_to_graph(av);
		return (0);
}
