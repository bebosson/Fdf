/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 06:09:09 by bebosson          #+#    #+#             */
/*   Updated: 2019/05/28 09:35:17 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fdf.h"

int		ft_error(int error)
{

	if (error == 0)
	{
		ft_putendl("error");
		return (0);
	}
	return (0);
}

int		ft_error_maps(int ac, char **av)
{
	int fd;

	if (ac != 2 || av[1] == NULL)
	{
		ft_putendl("error map");
		return (0);
	}
	else
	{
		fd = open(av[1], O_RDONLY);
		return (fd);
	}
	return (0);
}

void	fix_display(t_win **display, int echelle, float angle, float z)
{

	(*display)->angle = angle;
	(*display)->z = z;
	ft_echelle(display, echelle);
	iso_list(*display);
	display_min(display);
	display_max(display);
	centrer(display);
}


void	graphic(t_win *display)
{
	display->mlx = mlx_init();

//	mlx_do_key_autorepeaton(display->mlx);
	display->screen = 1000;
	(display)->win_ptr_s = mlx_new_window(display->mlx, display->screen, display->screen,"FDF");
	fix_display(&display, 2, 4.2,1);
	fix_image(&display, display->screen, display->screen);
//	mlx_do_key_autorepeaton(display->mlx);
	mlx_hook(display->win_ptr_s,2, 0, deal_key, display);
//	mlx_loop_hook(display->mlx, deal_key,display);
	if (display->mlx)
		mlx_loop(display->mlx);

}

int		coor_to_graph(int fd)
{
	t_win	*display;
	t_point *list;
	
	if (!(display =(t_win *)malloc(sizeof(t_win))))
		return (0);
	display->tpoint = read_to_list(fd, display);
	if (display->tpoint == NULL)
	{
		ft_error(0);
		exit(EXIT_SUCCESS);
	}
	graphic(display);
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
