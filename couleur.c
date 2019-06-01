/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   couleur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 19:20:33 by bebosson          #+#    #+#             */
/*   Updated: 2019/06/01 20:00:59 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	change_couleur_point(t_win **display, int couleur)
{
	t_point	*tmp;
	
	tmp = (*display)->tpoint;
	while(tmp->next)
	{
		tmp->couleur += couleur;
		tmp = tmp->next;
	}
}
