/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 03:25:03 by bebosson          #+#    #+#             */
/*   Updated: 2019/04/01 19:13:20 by bebosson         ###   ########.fr       */
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
		if (test_digit(tab_pts[x]) == 1)
			tmp->z = ft_atoi(tab_pts[x]);
		else 
			return (0);
		tmp->x = x;
		tmp->coor_x = x;
		tmp->coor_y = y;
		tmp->y = y;
		tmp->couleur = 0xFFFFFF;
		elem = (t_point*)malloc(sizeof(t_point));
		tmp->next = elem;
		tmp = tmp->next;
	}
	return (tmp);
	//tmp->next = NULL;
}

t_point		*init_repere_couleur(char **tab_pts, t_point **list, int y, int x)
{
	int i;
	t_point *tmp;
	t_point *elem;

	tmp = *list;
	i = -1;
	if (test_digit(tab_pts[i]) == 1)
		tmp->z = ft_atoi(tab_pts[i]);
	else 
		return (0);
	tmp->x = x;
	tmp->coor_x = x;
	tmp->coor_y = y;
	tmp->y = y;
	if (tab_pts[++i] != NULL)
	{
		tab_pts[i] = ft_strsub(tab_pts[i], 2, ft_strlen(tab_pts[i]) - 2);
		tmp->couleur = ft_atoi_base(tab_pts[i], 16);
		printf("couleur ! = %s \n",tab_pts[i]);
		printf("tmp = %d ", tmp->couleur);
	}
	else
		tmp->couleur = 0xFFFFFF;
	return (tmp);
}

void		display_point(t_point *tmp)
{
	printf("x = %.5f / ", tmp->x);
	printf("y = %.5f / ", tmp->y);
	printf("z = %.5f / ", tmp->z);
	printf("coor_x = %d /", tmp->coor_x);
	printf("coor_y = %d / ",tmp->coor_y);
	printf("couleur = %d / \n", tmp->couleur);
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
		tmp->next = elem;
		tmp = tmp->next;
	}
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
	list = (t_point *)malloc(sizeof(t_point));
	tmp = list;
	while (get_next_line(fd, &line) > 0)
	{
		tab_pts = ft_strsplit(line, ' ');
		if (ft_strchr(line, ',') != NULL)
		{
			tmp = read_couleur(tab_pts, &tmp, ++y);
			if (tmp == NULL)
				return (0);
		}
		else
		{
			tmp = init_repere(tab_pts,&tmp,++y);
			if (tmp == NULL)
				return (0);
		}

	}
	return (list);
}
