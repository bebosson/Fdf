/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 22:07:13 by bebosson          #+#    #+#             */
/*   Updated: 2019/07/26 00:59:03 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fdf.h"

void	ft_free_list_and_exit(t_win **display)
{
	t_point *tmp;
	t_color *tmp2;

	if (display)
		tmp2 = (*display)->color;
	if (tmp)
	{
		while ((*display)->tpoint != NULL)
		{
			tmp = (*display)->tpoint;
			(*display)->tpoint = (*display)->tpoint->next;
			free(tmp);
		}
		free((*display)->tpoint);
	}
	if (tmp2)
		free(tmp2);
	free(*display);
	display = NULL;
	while (1);
	exit(EXIT_SUCCESS);
}
