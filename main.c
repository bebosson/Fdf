/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 06:09:09 by bebosson          #+#    #+#             */
/*   Updated: 2019/06/15 20:03:19 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fdf.h"

void	fix_nbr_pt(t_win *display)
{
	int	max;
	int	min;

	max = ft_relier_halid(display);
	min = ft_relier_valid(display);
	if (max < min)
		max = min;
	if (max > 10000)
		display->nbr_print = 4000;
	else
		display->nbr_print = max;
}

int		test_echelle(t_win *display)
{

	printf("relier_halid %d \n",ft_relier_halid(display));
	printf("relier_valid %d \n",ft_relier_valid(display));
	if (ft_relier_halid(display) < display->nbr_print && ft_relier_valid(display) < display->nbr_print)
		return (0);
	else
		return (1);
}

void	fix_display(t_win **display, int echelle, float angle, float z)
{
	(*display)->angle = angle;
	(*display)->z = z;
	point_central(display);
	centrer(display);
}
void	set_wireframe(t_win *display)
{

	display->iso = 0; // atoi(av[2]) ? 
	display->echelle = 16; //definir une echelle de zoom adapte a la maps
	display->screen = 1000; //define header
	display->mlx = mlx_init();
	(display)->win_ptr_s = mlx_new_window(display->mlx, display->screen, display->screen,"FDF");
}

void	graphic(t_win *display)
{
	set_wireframe(display);
	fix_couleur(&display); // & ?
	fix_display(&display, 8, 4.2,1);
	get_image(display);
	fix_image(&display, display->screen, display->screen); // on cree l'image puis detruit
	test_echelle(display);
	fix_nbr_pt(display);
	printf("nbr_print = %d \n",display->nbr_print);
	mlx_hook(display->win_ptr_s,2, 0, deal_key, display); //ft hook
	mlx_loop(display->mlx);
}



int		coor_to_graph(int fd)
{
	t_win	*display;

	if (!(display =(t_win *)malloc(sizeof(t_win))))
		return (0);
	display->tpoint = read_to_list(fd, display);
	if (display->tpoint == NULL)
	{
		ft_error(0);
		exit(EXIT_SUCCESS);
	}
	graphic(display);
// refaire une fenetre pour l'info ou print en sortie standart	
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
