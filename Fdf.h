/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 02:08:25 by bebosson          #+#    #+#             */
/*   Updated: 2019/03/28 20:54:23 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H
# include "get_next_line.h"
# include "libft/libft.h"
# include "mlx.h"
#include <math.h>
//Tout faire en float ? 
typedef struct	s_point
{
	int coor_x;
	int coor_y;
	float x;
	float y;
	float z;
	struct s_point *next; // pas besoin
	struct s_point *prev; // pas besoin
}				t_point;
// Tout faire en float ? 
typedef struct	s_win
{
	void	*mlx;
	void	*win_ptr_s;
	int		screen;
	int		x_win;
	int		y_win;
	int		x_max;
	int		y_max;
	int		x_min;
	int		y_min;
//	int		x_o;
//	int		y_o;
	float		echelle;
	float		angle;
	t_point *tpoint;
	t_point *t_zpoint;
}				t_win;


void	rotation_list_x(t_win *display, float angle);
void	centrer(t_win **display);
void	round_value(float x_p, float y_p, int *x, int *y);
void	ft_coor_x(t_win **display, int trans);
void	ft_coor_y(t_win **display, int trans);
void	ft_coor_z(t_win **display, int trans);
void	iso_list(t_win *display);
void	trans_iso(float *x, float *y, int z);
void	fix_display(t_win **display, int echelle, float angle);
int		deal_key_translation(int key, t_win *display);
int		deal_key(int key, t_win *display);
void	ft_trace(t_win *display);
int		deal_key_rotation(int key, t_win *display);
void	ligne_vert(t_win *display);
void	ligne_hor(t_win *display);
void	display_min(t_win **display);
void	display_max(t_win **display);

void	rotation_z(float teta, float *x, float *y, t_win *display);
void	rotation_x(float teta, float *x, float *y, t_win *display);
void	rotation_list_z(t_win *display, float angle);
void ligne(int xi,int yi,int xf,int yf, t_win *display);
void	ft_print_tables(char **tab_pts);
t_point		*init_repere(char **tab_pts, t_point **list, int y);
void		display_repere(t_win *display);
int		ft_x_max(t_point *list);
t_point	*read_to_list(char **av, t_win *display);
void	ft_display(t_win *display);
void	set_display(t_win *display, int x_win, int y_win, float echelle);
void	ft_echelle(t_win **display, float echelle);
int	barre_pixel(int button, int x, int y, t_win *display);
int	trait(int max, int min, float ratio, t_win *display, float toto);
void	display_display(t_win *display);

void	ft_relier_h(t_win *display);
void	display_point(t_point *tpoint);

void	ft_origin(t_win **display, int echelle, float angle);
void	ft_relier_v(t_win *display);

void	rotation_y(float teta, float *x, float *z, t_win *display);

void	rotation_list_y(t_win *display, float angle);
#endif
