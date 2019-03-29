/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 03:25:03 by bebosson          #+#    #+#             */
/*   Updated: 2019/03/29 18:19:01 by bebosson         ###   ########.fr       */
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
// INCLURE display_max et display_min

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
		tmp->coor_x = x;
		tmp->coor_y = y;
		tmp->y = y;
		elem = (t_point*)malloc(sizeof(t_point));
		tmp->next = elem;
		tmp = tmp->next;
	}

	return (tmp);
	//tmp->next = NULL;
}
void		display_point(t_point *tmp)
{
	printf("x = %.5f / ", tmp->x);
	printf("y = %.5f / ", tmp->y);
	printf("z = %.5f / ", tmp->z);
	printf("coor_x = %d /", tmp->coor_x);
	printf("coor_y = %d / \n",tmp->coor_y);

}
void		display_repere(t_win *display)
{
	t_point *tmp;

	tmp = display->tpoint;
	while (tmp->next)
	{
		display_point(tmp);
		tmp = tmp->next;
	}
	display_max(&display);
	display_min(&display);
	printf("---------------------\n");
	printf("x_max = %.5f \n", display->x_max);
	printf("y_max = %.5f \n", display->y_max);
	printf("x_min = %.5f \n", display->x_min);
	printf("y_min = %.5f \n", display->y_min);
	printf("x_win = %.5f \n", display->x_win);
	printf("y_win = %.5f \n", display->y_win);
	printf("angle = %.5f \n", display->angle);
	printf("z = %.5f \n", display->z);
	printf("---------------------\n");
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

t_point	*read_to_list(char **av, t_win *display)
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
	
	return (list);
}
