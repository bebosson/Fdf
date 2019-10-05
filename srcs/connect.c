/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:58:20 by bebosson          #+#    #+#             */
/*   Updated: 2019/10/05 17:05:02 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

static int		relier_v(t_point *pt1, t_point *pt2, t_win *data)
{
	if (pt1->x > data->scr || pt1->y > data->scr)
		return (0);
	else if (pt2->x > data->scr || pt2->y > data->scr)
		return (0);
	else if (pt1->x < 0 || pt2->x < 0 || pt1->y < 0 || pt2->y < 0)
		return (0);
	else
		return (1);
}

int				ft_relier_halid(t_win *data)
{
	int		nbr_print;
	t_point	*tmp_1;
	t_point	*tmp_2;

	nbr_print = 0;
	tmp_1 = data->tpoint;
	tmp_2 = data->tpoint->next;
	while (tmp_2->next)
	{
		if (tmp_1->coor_y == tmp_2->coor_y && relier_v(tmp_1, tmp_2, data))
			nbr_print++;
		tmp_2 = tmp_2->next;
		tmp_1 = tmp_1->next;
	}
	tmp_1 = NULL;
	tmp_2 = NULL;
	return (nbr_print);
}

int				ft_relier_valid(t_win *data)
{
	int		nbr_print;
	t_point	*tmp_1;
	t_point	*tmp_2;

	nbr_print = 0;
	tmp_1 = data->tpoint;
	tmp_2 = data->tpoint->next;
	while (tmp_2->coor_x != tmp_1->coor_x)
		tmp_2 = tmp_2->next;
	while (tmp_2->next)
	{
		if (tmp_1->coor_x == tmp_2->coor_x && relier_v(tmp_1, tmp_2, data))
			nbr_print++;
		tmp_2 = tmp_2->next;
		tmp_1 = tmp_1->next;
	}
	return (nbr_print);
}

void			ft_relier_h2(t_win *data)
{
	t_point	*tmp_1;
	t_point	*tmp_2;

	tmp_1 = data->tpoint;
	tmp_2 = data->tpoint->next;
	while (tmp_2->next)
	{
		if (tmp_1->coor_y == tmp_2->coor_y && relier_v(tmp_1, tmp_2, data))
			ligne_2(tmp_1, tmp_2, data);
		tmp_2 = tmp_2->next;
		tmp_1 = tmp_1->next;
	}
	tmp_1 = NULL;
	tmp_2 = NULL;
}

void			ft_relier_v2(t_win *data)
{
	t_point	*tmp_1;
	t_point	*tmp_2;

	tmp_1 = data->tpoint;
	tmp_2 = data->tpoint->next;
	while (tmp_2->coor_x != tmp_1->coor_x)
		tmp_2 = tmp_2->next;
	while (tmp_2->next)
	{
		if (tmp_1->coor_x == tmp_2->coor_x && relier_v(tmp_1, tmp_2, data))
			ligne_2(tmp_1, tmp_2, data);
		tmp_2 = tmp_2->next;
		tmp_1 = tmp_1->next;
	}
}
