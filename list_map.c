/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 03:25:03 by bebosson          #+#    #+#             */
/*   Updated: 2019/03/09 15:16:33 by bebosson         ###   ########.fr       */
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

t_point	*read_to_list(char **av, int *x_max, int *y_max)
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
	return (list);
}
