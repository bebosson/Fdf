/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 02:08:25 by bebosson          #+#    #+#             */
/*   Updated: 2019/10/05 19:57:10 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H
# include <stdlib.h>
# include "../libft/libft.h"
# include "mlx.h"
#include <math.h>

#define X_W 1000000
#define WIN 1000

typedef struct	s_point
{
	int coor_x;
	int coor_y;
	int r;
	int g;
	int b;
	float x;
	float y;
	float z;
	float	z_o;
	float	opp_z_o;
	int c;
	struct s_point *next;
}				t_point;
// Tout faire en float ? 
typedef struct	s_co
{
	int	menu;
	int	z;
	int	z_a;
	int	trans;
	int	r_y;
	int	r_x;
	int	r_z;
	int	c_r;
	int	c_g;
	int	c_b;
	int	c;
	int	r;
}				t_co;

typedef struct	s_win
{
	void	*mlx;
	void	*w;
	void	*win;
	void	*img;
	void	*img2;
	int		*addr;
	int		*addr2;
	int		scr;
	int		scr2;
	float x_o;
	float y_o;
	int			iso;
	float		x_win;
	float		y_win;
	float		x_max;
	float		y_max;
	float		x_min;
	float		y_min;
	float		z;
	float		z_max;
	int			xinc;
	int			yinc;
	float		echelle;
	float		echelle_max;
	float		echelle_min;
	float		angle;
	float		angle_x;
	float		angle_y;
	int			nb_p;
	int		c_on;
	//Couleur (en hexa)
	//scr en fonction de data->x_max et data->y_max
	t_point *tpoint;
	t_point *middle;
	t_co *c;
}				t_win;

void	ft_free_list_and_exit(t_win **data);
void	fix_nbr_pt(t_win *data);
void	fix_nbr_pt(t_win *data);
int		ft_change_z(t_win **data, float trans);
int		test_echelle(t_win *data);
void	get_image(t_win *data);
int		ft_error(int error);
int		ft_error_maps(int ac, char **av);
void	fix_c(t_win **data);
int		ft_rgb(t_point **tmp, int r, int g, int b);
void	change_c_point(t_win **data, int r, int g, int b);
void	ft_origin_z(t_win **data);
void	point_central(t_win **data);
void	data_borne(t_win *data);
void	fix_image(t_win **data, int largeur, int hauteur);
void	fill_image(t_win *data, int x, int y, int c);
void	ligne_2(t_point *pt1, t_point *pt2, t_win *data);
void	inf(int dx, int dy, t_win *data, int i);
void	sup(int dx, int dy, t_win *data, int i);
void	r_list_x(t_win *data, float angle);
void	centrer(t_win **data);
void	ft_coor_delta(t_win **data, int trans_x, int trans_y);
int		ft_coor_z(t_win *data, float trans);
void	iso_list(t_win *data);
void	trans_iso(float *x, float *y, int z);

int		deal_key_ziso_plane(int key, t_win *data);
int		deal_key_zoom(int key, t_win *data);
int		deal_key_translation(int key, t_win *data);
int		deal_key(int key, t_win *data);
int		deal_key_c(int key, t_win *data);
int		deal_key_r(int key, t_win *data);
int		deal_key_ziso_menu(int key, t_win *data);

void	ft_trace(t_win *data);
void	ligne_vert(t_win *data);
void	ligne_hor(t_win *data);
void	data_min(t_win **data);
void	data_max(t_win **data);
void	r_z(float teta, float *x, float *y, t_win *data);
void	r_x(float teta, float *x, float *y, t_win *data);
void	r_list_z(t_win *data, float angle);
void ligne(int xi,int yi,int xf,int yf, t_win *data);
void	ft_print_tables(char **tab_pts);
t_point		*init_repere(char **tab_pts, t_point *list, int y);
void		data_repere(t_win *data);
int		ft_x_max(t_point *list);
t_point	*read_to_list(int fd, t_win *data);
void	ft_data(t_win *data);
void	set_data(t_win *data, int x_win, int y_win, float echelle);
void	ft_echelle(t_win **data, float echelle);
void	data_data(t_win *data);
void	data_point(t_point *tpoint);
void	ft_origin(t_win **data);
void	ft_relier_v(t_win *data);
void	ft_relier_h(t_win *data);
int		ft_relier_halid(t_win *data);
void	ft_relier_h2(t_win *data);
void	ft_relier_v2(t_win *data);
int		ft_relier_valid(t_win *data);

void	r_y(float teta, float *x, float *z, t_win *data);
void	r_list_y(t_win *data, float angle);
void	set_colour_info(t_win *data);
void	ft_set_to_zero(t_win *data, int angle_y, int angle_x);

#endif
