/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   couleur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 19:20:33 by bebosson          #+#    #+#             */
/*   Updated: 2019/07/21 20:35:51 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	fix_couleur(t_win **display)
{
	t_point	*tmp;

	tmp = (*display)->tpoint;
	while(tmp)
	{
		if (tmp->z_o < 0)
			tmp->couleur = ft_rgb(&tmp, 113, 171, 216);
		if (tmp->z_o < 10 && tmp->z_o >= 0)
			tmp->couleur = ft_rgb(&tmp, 172, 208, 165);
		if (tmp->z_o >= 10 && tmp->z_o <= 20)
			tmp->couleur = ft_rgb(&tmp, 232, 225, 182);
		if (tmp->z_o > 20)
			tmp->couleur = ft_rgb(&tmp, 170, 135, 83);
		tmp = tmp->next;
	}
}


void	change_couleur_point(t_win **display, int r, int g, int b)
{
	t_point	*tmp;

	tmp = (*display)->tpoint;
	while(tmp->next)
	{
		tmp->r += r;
		tmp->g += g;
		tmp->b += b;
		tmp->couleur = ft_rgb(&tmp, tmp->r,tmp->g,tmp->b);
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
