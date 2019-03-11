/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 02:08:25 by bebosson          #+#    #+#             */
/*   Updated: 2019/03/09 19:54:13 by bebosson         ###   ########.fr       */
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
	int		screen;
	int		x_win;
	int		y_win;
	int		x_o;
	int		y_o;
	float		echelle;
	t_point *tpoint;
}				t_win;


void ligne(int xi,int yi,int xf,int yf, t_win *display);
void	ft_print_tables(char **tab_pts);
t_point		*init_repere(char **tab_pts, t_point **list, int y);
void		display_repere(t_point *list);
int		ft_x_max(t_point *list);
t_point	*read_to_list(char **av, int *x_max, int *y_max);
void	ft_display(t_win *display);
void	set_display(t_win *display, int x_win, int y_win, float echelle);
void	vertical(t_win *display, int trans);
void	horizontal(t_win *display,  int trans);
int		deal_key(int key, t_win *display);
void	ft_echelle(t_win *display, float echelle);
int	barre_pixel(int button, int x, int y, t_win *display);
int	trait(int max, int min, float ratio, t_win *display, float toto);
void	set_display_oblique(t_win *display, int x, int y, float echelle);
void	display_display(t_win *display);
#endif
