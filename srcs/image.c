/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:57:56 by bebosson          #+#    #+#             */
/*   Updated: 2019/10/05 18:17:05 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	*ft_bzero_int(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned int *)s)[i] = 0;
		i++;
	}
	return (s);
}

void	get_image(t_win *data)
{
	int		bpp;
	int		s_l;
	int		endian;
	int		i;

	data->img = mlx_new_image(data->mlx, WIN, WIN);
	data->addr = (int*)mlx_get_data_addr(data->img, &(bpp), &(s_l), &(endian));
}

void	get_new_image(t_win *data)
{
	int		bpp;
	int		s_l;
	int		endian;

	data->img = mlx_new_image(data->mlx, WIN, WIN);
	data->addr = (int*)mlx_get_data_addr(data->img, &(bpp), &(s_l), &(endian));
	data->img2 = mlx_new_image(data->mlx, WIN / 2, WIN / 2);
	data->addr2 = (int*)mlx_get_data_addr(data->img, &(bpp), &(s_l), &(endian));
}

void	fix_image(t_win **data, int largeur, int hauteur)
{
	int i;

	(*data)->addr = ft_bzero_int((*data)->addr, WIN);
	mlx_clear_window((*data)->mlx, (*data)->win_ptr_s);
	ft_trace(*data);
	mlx_put_image_to_window((*data)->mlx, (*data)->win_ptr_s, (*data)->img, 0, 0);
}
