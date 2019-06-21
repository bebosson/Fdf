/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 06:09:09 by bebosson          #+#    #+#             */
/*   Updated: 2019/06/21 16:50:18 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fdf.h"

void	fix_nbr_pt(t_win *display)
{
	int	max;
	int	min;
	int echelle;

	max = ft_relier_halid(display);
	min = ft_relier_valid(display);
	display->echelle = 1;
	if (max < min)
		max = min;
	if (max > 10000)
	{
		display->nbr_print = 4000;
		display->echelle_max = 1;
		echelle = 1;
		if (display->iso == 1)
		{
			echelle = 4;
			display->echelle_max = 4;
		}
	}
	else
	{
		display->nbr_print = max;
		display->echelle_max = 1;
		echelle = 1;
	}
	ft_echelle(&display, echelle);
	//	fix_image(&display, display->screen, display->screen); // on cree l'image puis detruit
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



void	set_wireframe(t_win *display, char *av)
{

	display->iso = ft_atoi(av); // atoi(av[2]) ? 
	if (display->iso == 1)
		iso_list(display);
	//	display->echelle = 16; //definir une echelle de zoom adapte a la maps
	display->screen = 1000; //define header
	display->mlx = mlx_init();
	(display)->win_ptr_s = mlx_new_window(display->mlx, display->screen, display->screen,"FDF");
	display->screen2 = 500; //define header
	(display)->win = mlx_new_window(display->mlx, display->screen2, display->screen2,"info");

}

void	graphic(t_win *display, char *av)
{
	set_wireframe(display,av);
	fix_couleur(&display); // & ?
	fix_display(&display, 8, 4.2,1);
	get_image(display);
	test_echelle(display);
	fix_nbr_pt(display);
	centrer(&display);
	fix_image(&display, display->screen, display->screen); // on cree l'image puis detruit

	printf("nbr_print = %d \n",display->nbr_print);
	mlx_hook(display->win_ptr_s,2, 0, deal_key, display); //ft hook
	mlx_loop(display->mlx);
}



int		coor_to_graph(int fd, char *av)
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
	graphic(display, av);
	// refaire une fenetre pour l'info ou print en sortie standart	
	return (0);
}


int main(int ac, char **av)
{
	int fd;

	if (ft_error_maps(ac, av) > 0)
	{
		fd = open(av[1], O_RDONLY);
		coor_to_graph(fd, av[2]);
	}
	else
		return (0);
}
