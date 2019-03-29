/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 06:09:09 by bebosson          #+#    #+#             */
/*   Updated: 2019/03/29 19:33:18 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fdf.h"

void	fix_display(t_win **display, int echelle, float angle, float z)
{

	(*display)->angle = angle;
	(*display)->z = z;
	ft_echelle(display, echelle);
	iso_list(*display);
	display_min(display);
	display_max(display);
	centrer(display);
	//display_repere(*display);
//	ft_trace(&display);
}


void	graphic(t_win *display)
{
	display->mlx = mlx_init();
	display->screen = 2000;
	(display)->win_ptr_s = mlx_new_window(display->mlx, display->screen, display->screen,"FDF");
	fix_display(&display, 25, 4.2, 1);
	mlx_key_hook(display->win_ptr_s, deal_key,display);

	if (display->mlx)
		mlx_loop(display->mlx);

}

int		coor_to_graph(char **av)
{
	t_win	*display;
	t_point *list;
	display =(t_win *)malloc(sizeof(t_win));
	display->tpoint = read_to_list(av, display);
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
