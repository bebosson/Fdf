/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 02:08:25 by bebosson          #+#    #+#             */
/*   Updated: 2019/02/17 00:51:12 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H
# include "get_next_line.h"
# include "libft/libft.h"
# include "mlx.h"
#include <math.h>
typedef struct	s_point
{
	int x;
	int y;
	int z;
	struct s_point *next;
	struct s_point *prev;
}				t_point;

typedef struct	s_win
{
	void	*mlx;
	void	*win_ptr_s;
	int		x_win;
	int		x_o;
	int		y_o;
	int		y_win;
	int		echelle;
	t_point *tpoint;
}				t_win;

void	vertical(t_win *display, int x_ref, int y_ref);
void	horizontal(t_win *display, int y_ref, int x_ref);
int		deal_key(int key, t_win *display);
void	ft_echelle(int *x_win, int *y_win);

#endif
