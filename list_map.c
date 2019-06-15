/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 03:25:03 by bebosson          #+#    #+#             */
/*   Updated: 2019/06/15 20:54:20 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

int		test_digit(char *a)
{
	char t;
	int i;

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

void	ft_print_tables(char **tab_pts)
{
	int x;

	x = -1;
	while (tab_pts[++x])
		printf("%s",tab_pts[x]);
}

t_point		*init_repere(char **tab_pts, t_point *list, int y)
{
	int x;
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
		tmp->couleur = ft_rgb(155, 30, 50);
		elem = (t_point*)malloc(sizeof(t_point));
		ft_bzero(elem, sizeof(t_point));
		free(tab_pts[x]);
		tmp->next = elem;
		tmp = tmp->next;
	}
	return (tmp);
}

t_point		*init_repere_couleur(char **tab_pts, t_point **list, int y, int x)
{
	int i;
	t_point *tmp;
	t_point *elem;

	tmp = *list;
	i = 0;
	if (test_digit(tab_pts[i]) == 1)
		tmp->z = ft_atoi(tab_pts[i]);
	else 
		return (0);
	tmp->z_o = tmp->z;
	tmp->x = x;
	tmp->coor_x = x;
	tmp->coor_y = y;
	tmp->y = y;
	if (tab_pts[++i] != NULL)
	{
		tab_pts[i] = ft_strsub(tab_pts[i], 2, ft_strlen(tab_pts[i]) - 2);
		tmp->couleur = ft_atoi_base(tab_pts[i], 16);
	}
	else
		tmp->couleur = 0xB222222;
	return (tmp);
}




t_point	*read_couleur(char **tab_pts, t_point **list, int y)
{
	int x;
	char **tab_pts2;
	t_point *tmp;
	t_point *elem;
	
	tmp = *list;
	x = -1;
	while (tab_pts[++x])
	{
		tab_pts2 = ft_strsplit(tab_pts[x], ',');
		init_repere_couleur(tab_pts2, &tmp, y, x);
		if (tmp == NULL)
			return (0);
		if (!(elem = (t_point*)malloc(sizeof(t_point))))
				return (0);
		ft_bzero(elem, sizeof(t_point));
		tmp->next = elem;
		tmp = tmp->next;
	}
//	free();
	return (tmp);
}


t_point	*read_to_list(int fd, t_win *display)
{
	int y;
	char **tab_pts;
	char *line;
	t_point *list;
	t_point *tmp;

	y = -1;
	if (!(list = (t_point *)malloc(sizeof(t_point))))
		return (0);
	ft_bzero(list, sizeof(t_point));
	tmp = list;
	while (get_next_line(fd, &line) > 0)
	{
		tab_pts = ft_strsplit(line, ' ');
//		if (ft_strchr(line, ',') != NULL)
//		{
//			tmp = read_couleur(tab_pts, &tmp, ++y);
//			if (tmp == NULL)
//				return (0);
//		}
//		else
//		{
			tmp = init_repere(tab_pts,tmp,++y);
			free(tab_pts);
			if (tmp == NULL)
				return (0);
		free(line);
//		}
	}
	free(line);
	return (list);
}
