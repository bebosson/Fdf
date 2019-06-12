/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 06:09:09 by bebosson          #+#    #+#             */
/*   Updated: 2019/06/12 21:14:19 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fdf.h"

void	fix_display(t_win **display, int echelle, float angle, float z)
{

	(*display)->angle = angle;
	(*display)->z = z;
//	ft_echelle(display, echelle);
	if ((*display)->iso == 1)
		iso_list(*display);
//	(*display)->couleur = 100;
	display_repere(*display);
	point_central(display);
	centrer(display);
}

void	graphic(t_win *display)
{
	int i;

	i = 0;

	display->mlx = mlx_init();
//	display->mlx_2 = mlx_init();
//	info->mlx = mlx_init();
//	info->screen = 1000;
//	(info)->win = mlx_new_window(info->mlx, info->screen, info->screen,"INFO");

	display->iso = 0;
	display->echelle = 1;
	display->screen = 2000;
	(display)->win_ptr_s = mlx_new_window(display->mlx, display->screen, display->screen,"FDF");
	fix_couleur(&display);
	fix_display(&display, 2, 4.2,1);
//	ft_echelle(&display, 50);
	fix_image(&display, display->screen, display->screen);
	mlx_hook(display->win_ptr_s,2, 0, deal_key, display);
//	mlx_loop_hook(display->mlx, deal_key,display);
//	if (display->mlx)
	
	mlx_loop(display->mlx);
//	mlx_loop(display->mlx_2);
//	mlx_loop(info->mlx);
}



int		coor_to_graph(int fd)
{
	t_win	*display;
	t_point	*list;
	
	if (!(display =(t_win *)malloc(sizeof(t_win))))
		return (0);
	display->tpoint = read_to_list(fd, display);
	if (display->tpoint == NULL)
	{
		ft_error(0);
		exit(EXIT_SUCCESS);
	}
//	display->screen = 1000;
//	fix_couleur(&display);
//	fix_display(&display, 2, 4.2,1);
//	fix_image(&display, display->screen, display->screen);
	graphic(display);
//	graphic_2(display, info);

//	display->mlx = mlx_init();
//	display->screen = 1000;
//	(display)->win = mlx_new_window(display->mlx, display->screen / 2, display->screen / 2,"coucou");
//	mlx_string_put(display->mlx_2, display->win, 300, 300, 0xFFFFFF, "YOOOOOOOOOOOOOOOO");
//	mlx_loop(display->mlx);
	return (0);
}


int main(int ac, char **av)
{
	int fd;
	
	fd = ft_error_maps(ac, av);
	if (fd != 0)
		coor_to_graph(fd);
	else
		return (0);
}
