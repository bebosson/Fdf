/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 03:25:03 by bebosson          #+#    #+#             */
/*   Updated: 2019/02/18 17:09:50 by bebosson         ###   ########.fr       */
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

// ratio < 1

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
	display->screen = 2000;
	(display)->win_ptr_s = mlx_new_window(mlx_ptr, 2000, 2000,"juepee");
	win_ptr = display->win_ptr_s;
//	printf("x_win(disply) = %d \n",display->x_win);
	if (!(tclique =(t_point*)malloc(sizeof(t_point))))
		return ;
	display->tpoint = tclique;
	tclique->prev = NULL;
	tclique->next = NULL;
	/////////////////////////////////////////
	display->x_win = x_win;
	display->y_win = y_win;
	display->x_o = 0;
	display->y_o = 0;


//	vertical(display, 0, 0);
//	horizontal(display, 0, 0);
//	display->x_o = 0;
//	display->y_o = 0;
	if (mlx_key_hook(win_ptr, deal_key,display) == 0)
		mlx_ptr = NULL;
//	mlx_key_hook(win_ptr, deal_mouse_display,(void *)0);
	
//	mlx_mouse_hook(win_ptr, deal_mouse_display,display);
//	mlx_mouse_hook(win_ptr, barre_pixel,display);
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
	display->x_o = 0;
	display->y_o = 0;

	graphic(display, x_win, y_win);
	return (0);
}


int main(int ac, char **av)
{
	coor_to_graph(av);
		return (0);
}
