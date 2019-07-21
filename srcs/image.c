/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:57:56 by bebosson          #+#    #+#             */
/*   Updated: 2019/07/20 20:39:25 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"
// get_addresse c'est tout
#define X_W 1000

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

void	get_image(t_win		*display)
{
	int		bpp;
	int		s_l;
	int		endian;
	int i;

	display->img = mlx_new_image(display->mlx, X_W, X_W);
	display->addr = (int*)mlx_get_data_addr(display->img, &(bpp), &(s_l), &(endian));
//	while (display->addr[i])
//	{
//		((unsigned int *)display->addr)[i] = 0;
//		i++;
//	}

}

void	get_new_image(t_win		*display)
{
	int		bpp;
	int		s_l;
	int		endian;

	display->img = mlx_new_image(display->mlx, X_W, X_W);

	display->addr = (int*)mlx_get_data_addr(display->img, &(bpp), &(s_l), &(endian));
	display->img2 = mlx_new_image(display->mlx, X_W/2, X_W/2);
	display->addr2 = (int*)mlx_get_data_addr(display->img, &(bpp), &(s_l), &(endian));
}

void	fix_image(t_win **display, int largeur, int hauteur)
{
	int i;

	(*display)->addr = ft_bzero_int((*display)->addr, 1000000);
	mlx_clear_window((*display)->mlx, (*display)->win_ptr_s);
//	display_repere(*display);
	ft_trace(*display);
	mlx_put_image_to_window((*display)->mlx, (*display)->win_ptr_s, (*display)->img, 0,0);
}

//Fonction ft_trace  clear_window
