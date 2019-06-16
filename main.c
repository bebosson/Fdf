/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 06:09:09 by bebosson          #+#    #+#             */
/*   Updated: 2019/06/16 19:08:29 by bebosson         ###   ########.fr       */
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

void	set_win_info(t_win *display)
{
	display->screen2 = 500; //define header
	(display)->win = mlx_new_window(display->mlx, display->screen2, display->screen2,"info");
	mlx_string_put (display->mlx, display->win, 0, 0, 0xFF77FF,"z -> zoom");
	mlx_string_put (display->mlx, display->win, 0, 20, 0xFF99FF,"+ -> zoom avant -> - -> zoom arriere" );
	mlx_string_put (display->mlx, display->win, 0, 40, 0xFF99FF,"m -> menu" );
	mlx_string_put (display->mlx, display->win, 0, 60, 0xFF99FF,"t->translation (fleches)");
	mlx_string_put (display->mlx, display->win, 0, 80, 0xFF99FF,"rotation selon y (y)");
	mlx_string_put (display->mlx, display->win, 0, 100, 0xFF99FF,"6 -> avant");
	mlx_string_put (display->mlx, display->win, 0, 120, 0xFF99FF,"7 -> arriere");
	mlx_string_put (display->mlx, display->win, 0, 140, 0xFF99FF,"rotation selon x (x)");
	mlx_string_put (display->mlx, display->win, 0, 160, 0xFF99FF,"s -> avant");
	mlx_string_put (display->mlx, display->win, 0, 180, 0xFF99FF,"d -> arriere");
	mlx_string_put (display->mlx, display->win, 0, 200, 0xFF99FF,"rotation selon x (x)");
	mlx_string_put (display->mlx, display->win, 0, 220, 0xFF99FF,"s -> avant");
	mlx_string_put (display->mlx, display->win, 0, 240, 0xFF99FF,"d -> arriere");
	mlx_string_put (display->mlx, display->win, 0, 260, 0xFF99FF,"couleur (c) (fleches)");
	mlx_string_put (display->mlx, display->win, 0, 280, 0xFF99FF,"e -> rouge");
	mlx_string_put (display->mlx, display->win, 0, 300, 0xFF99FF,"g -> vert");
	mlx_string_put (display->mlx, display->win, 0, 320, 0xFF99FF,"b -> bleue");
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
}

void	graphic(t_win *display, char *av)
{
	set_wireframe(display,av);
	set_win_info(display);
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
