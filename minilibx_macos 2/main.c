/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 06:09:09 by bebosson          #+#    #+#             */
/*   Updated: 2019/02/14 07:56:30 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

//int mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
//int		mlx_loop_hook( void *mlx_ptr, int (*funct_ptr)(), void *param );

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 2000, 2000, "mlx 42");
//	mlx_pixel_put(mlx_ptr, win_ptr, 1000, 1000, 0xFFFFFFF);
	mlx_string_put(mlx_ptr, win_ptr,200,200,0xFFD700,"coucou");
//	mlx_new_image(mlx_ptr, 300, 300);
	mlx_loop(mlx_ptr);
}