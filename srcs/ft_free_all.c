/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 22:07:13 by bebosson          #+#    #+#             */
/*   Updated: 2019/10/05 20:00:03 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_list_and_exit(t_win **data)
{
	t_point	*tmp;
	t_co	*tmp2;

	if (data)
		tmp2 = (*data)->c;
	if (tmp)
	{
		while ((*data)->tpoint != NULL)
		{
			tmp = (*data)->tpoint;
			(*data)->tpoint = (*data)->tpoint->next;
			free(tmp);
		}
		free((*data)->tpoint);
	}
	if (tmp2)
		free(tmp2);
	if (data)
		free(*data);
	data = NULL;
	exit(EXIT_SUCCESS);
}
