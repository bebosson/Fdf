/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 06:09:09 by bebosson          #+#    #+#             */
/*   Updated: 2019/03/28 21:22:52 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fdf.h"


void	graphic(t_win *display)
{
	void	*mlx_ptr;
	void	*win_ptr;
	float x;
	int y;

	x = 0;
	y = 0;
	display->mlx = mlx_init();
	mlx_ptr = (display)->mlx;
	display->screen = 2000;
	(display)->win_ptr_s = mlx_new_window(mlx_ptr, display->screen, display->screen,"juepee");
	win_ptr = display->win_ptr_s;
	//	if (!(tclique =(t_point*)malloc(sizeof(t_point))))
//		return ;
//	display->tpoint = tclique;

//	rotation_list(display, -0.74);
//	rotation_list(display, -0.74);
//	display_max(&display);
//	display_min(&display);
//	display_repere(display);
//	set_display(display, x_win, y_win, 20);
//	ligne_oblique(display,list);
//	ligne (0,64,64,64, display);
//	ligne (64,0,128,0, display);
//	ligne (0,64,64,0, display);
//	ligne (64,64,128,0, display);
//	ligne_hor(display);
//	ligne_vert(display);


//	display_repere(list);
//rotation(3.14, 1, 0);
	printf("coucou \n");

//	fix_display(&display, 25, 4.2);
	//	display_repere(display);
	iso_list(display);
//	centrer(&display);
//	display_repere(display);
//	rotation_list(display,0.5);
//	display_repere(display);

	ft_trace(display);
//	ft_origin(&display);

	//	ft_trace(display);
	//while (x < 7)
	//{
	//	rotation_list(display,x);
	//	ft_trace(display);
	//	ft_origin(&display);
	//	x += 1;
//	}
	//display_repere(display);
	mlx_key_hook(win_ptr, deal_key,display);

//	mlx_mouse_hook(win_ptr, barre_pixel,display);
	if (mlx_ptr)
		mlx_loop(mlx_ptr);

}

int		coor_to_graph(char **av)
{
	t_win	*display;
	t_point *list;
	display =(t_win *)malloc(sizeof(t_win));
	display->tpoint = read_to_list(av, display); // faire sauter x_win et y_win
	//les renommer x_max et y_max
//	fix_display(&display);
//	display->x_win = display->x_max;
//	display->y_win = display->y_max;
	printf("W E S H \n");
	graphic(display);
	return (0);
}


int main(int ac, char **av)
{
	coor_to_graph(av);
		return (0);
}
