/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 04:02:26 by bebosson          #+#    #+#             */
/*   Updated: 2019/06/05 04:03:34 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

int		ft_error(int error)
{

	if (error == 0)
	{
		ft_putendl("error");
		return (0);
	}
	return (0);
}

int		ft_error_maps(int ac, char **av)
{
	int fd;

	if (ac != 2 || av[1] == NULL)
	{
		ft_putendl("error map");
		return (0);
	}
	else
	{
		fd = open(av[1], O_RDONLY);
		printf("%d \n",fd);
		return (fd);
	}
	return (0);
}
