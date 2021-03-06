/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 03:25:03 by bebosson          #+#    #+#             */
/*   Updated: 2019/10/05 18:04:11 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			test_digit(char *a)
{
	char	t;
	int		i;

	i = 0;
	while (a[i])
	{
		t = '0';
		while (t < ':')
		{
			if (a[i] - t == 0)
				return (1);
			t++;
		}
		i++;
	}
	return (0);
}

t_point		*init_repere(char **tab_pts, t_point *list, int y)
{
	int		x;
	t_point *tmp;
	t_point *elem;

	tmp = list;
	x = -1;
	while (tab_pts[++x])
	{
		if (test_digit(tab_pts[x]) == 1)
			tmp->z = ft_atoi(tab_pts[x]);
		else
			return (0);
		tmp->z_o = tmp->z;
		tmp->x = x;
		tmp->coor_x = x;
		tmp->coor_y = y;
		tmp->y = y;
		if (!(elem = (t_point*)malloc(sizeof(t_point))))
			return (NULL);
		ft_bzero(elem, sizeof(t_point));
		free(tab_pts[x]);
		tmp->next = elem;
		tmp = tmp->next;
	}
	return (tmp);
}

t_point		*read_to_list(int fd, t_win *data)
{
	int		y;
	char	**tab_pts;
	char	*line;
	t_point *list;
	t_point *tmp;

	y = -1;
	if (!(list = (t_point *)malloc(sizeof(t_point))))
		return (0);
	ft_bzero(list, sizeof(t_point));
	tmp = list;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(tab_pts = ft_strsplit(line, ' ')))
			return (0);
		if (!(tmp = init_repere(tab_pts, tmp, ++y)) || tab_pts == NULL)
			return (0);
		free(tab_pts);
		free(line);
	}
	if (y == -1 && ft_strlen(line) == 0)
		return (0);
	free(line);
	return (list);
}
