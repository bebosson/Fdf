/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   couleur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 19:47:31 by bebosson          #+#    #+#             */
/*   Updated: 2019/10/05 19:49:02 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fix_c(t_win **data)
{
	t_point	*tmp;

	tmp = (*data)->tpoint;
	while (tmp)
	{
		if (tmp->z_o <= -500)
			tmp->c = ft_rgb(&tmp, 0, 0, 255);
		if (tmp->z_o <= 0 && tmp->z_o > -500)
			tmp->c = ft_rgb(&tmp, 113, 171, 216);
		if (tmp->z_o < 10 && tmp->z_o > 0)
			tmp->c = ft_rgb(&tmp, 172, 208, 165);
		if (tmp->z_o >= 10 && tmp->z_o <= 20)
			tmp->c = ft_rgb(&tmp, 232, 225, 182);
		if (tmp->z_o > 20)
			tmp->c = ft_rgb(&tmp, 170, 135, 83);
		tmp = tmp->next;
	}
}

void	change_c_point(t_win **data, int r, int g, int b)
{
	t_point	*tmp;

	tmp = (*data)->tpoint;
	while (tmp->next)
	{
		tmp->r += r;
		tmp->g += g;
		tmp->b += b;
		tmp->c = ft_rgb(&tmp, tmp->r, tmp->g, tmp->b);
		tmp = tmp->next;
	}
}

int		ft_rgb(t_point **tmp, int r, int g, int b)
{
	(*tmp)->r = r;
	(*tmp)->g = g;
	(*tmp)->b = b;
	return ((r << 16) | (g << 8) | b);
}
