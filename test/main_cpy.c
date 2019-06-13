/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 00:29:17 by bebosson          #+#    #+#             */
/*   Updated: 2019/06/14 00:56:39 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
