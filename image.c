/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:57:56 by bebosson          #+#    #+#             */
/*   Updated: 2019/06/13 23:30:15 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	fix_image(t_win **display, int largeur, int hauteur)
{
	int		bpp;
	int		s_l;
	int		endian;
	void	*image;

//	largeur += 50;
//	hauteur += 50;
	image = mlx_new_image((*display)->mlx, largeur, hauteur);
	(*display)->addr = (int*)mlx_get_data_addr(image, &(bpp), &(s_l), &(endian));
//	ft_bzero((*display)->addr,sizeof(int) * 1000 * 1000 + 1000);
	ft_trace(*display);
	mlx_put_image_to_window((*display)->mlx, (*display)->win_ptr_s, image , 0,0);
	free(image);
}

/*
void	fix_info(t_win **display, int largeur, int hauteur)
{
	int		bpp;
//	int		s_l;
//	int		endian;
//	void	*image;

	
//	image = mlx_new_image((*display)->mlx, largeur, hauteur);
//	(*display)->addr = (int*)mlx_get_data_addr(image, &(bpp), &(s_l), &(endian));
//	ft_trace(*display);
//	mlx_put_image_to_window((*display)->mlx, (*display)->win_ptr_s, image , 0,0);
//	free(image);
	
}


void	fill_image(t_win *display, int x_o, int y_o, int color)
{
	int y;
	int x;

	y = 0;
	printf("coucou = %d \n", ft_atoi_base("00BFFF", 16));
	while(y < display->screen)
	{

		x = -1;
		while (++x < display->screen)
		{
			if (y == y_o && x == x_o)
				display->addr[y * display->screen + x] = 49151;
		}
//		printf("%d \n", 1 << 30);
//		printf("%d \n", 1 << 8);
//		printf("%d \n", (1 << 30) - (1 << 8));
		display->addr[i + 1] = 255;
		display->addr[i + 2] = 255;
		display->addr[i + 3] = 1;
		(*display)->addr[1] = 0xff;
		y++;
	}
}
*/
