/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 04:02:26 by bebosson          #+#    #+#             */
/*   Updated: 2019/06/15 21:20:14 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

//Check fd directory
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

	if (ac != 3 || av[1] == NULL || av[2] == NULL)
	{
		if (av[1] == NULL)
		{
			ft_putendl("error map");
			return (0);
		}
		if (av[2] == NULL)
		{
			ft_putendl("error projection");
			ft_putendl("rappel :");
			ft_putendl("0 => parallele");
			ft_putendl("1 => conique");
			return (0);
		}
	}
	else
		return (1);
	return (0);
}

int		check_fd(char *av)
{

}
