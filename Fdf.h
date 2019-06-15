/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 02:08:25 by bebosson          #+#    #+#             */
/*   Updated: 2019/06/15 18:36:44 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H
# include <stdlib.h>
# include "get_next_line.h"
# include "libft/libft.h"
# include "mlx.h"
#include <math.h>
//Tout faire en float ? 
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
	int couleur;
	struct s_point *next; 
}				t_point;
// Tout faire en float ? 
typedef struct	s_win
{
	void	*mlx;
	void	*mlx_2;
	void	*win_ptr_s;
	void	*win;
	void	*img;
	int *addr;
	//castablen en int
	int		screen;
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
	int			nbr_print;
	int		couleur;
	int		couleur_on;
	//Couleur (en hexa)
	//screen en fonction de display->x_max et display->y_max
	t_point *tpoint;
	t_point *middle;
}				t_win;

typedef struct	s_fen
{
	void	*mlx;
	void	*win;
	void	*img;
	int		screen;
	int *addr;
}				t_fen;


int		test_echelle(t_win *display);
int		ft_relier_halid(t_win *display);
int		ft_relier_valid(t_win *display);
void	get_image(t_win		*display);
int		ft_error(int error);
int		ft_error_maps(int ac, char **av);
void	fix_couleur(t_win **display);
int		ft_rgb(int r, int g, int b);
void	change_couleur_point(t_win **display, int r, int g, int b);
void	ft_origin_z(t_win **display);
void	point_central(t_win **display);
void	display_borne(t_win *display);
void	fix_image(t_win **display, int largeur, int hauteur);
void	fill_image(t_win *display, int x, int y, int color);
int		ft_atoi_base(const char *str, int str_base);
void	ligne_2(t_point *pt1, t_point *pt2, t_win *display);
void	inf(int dx, int dy, t_win *display, int i);
void	sup(int dx, int dy, t_win *display, int i);
void	rotation_list_x(t_win *display, float angle);
void	centrer(t_win **display);
void	round_value(float x_p, float y_p, int *x, int *y);
void	ft_coor_delta(t_win **display, int trans_x, int trans_y);
int		ft_coor_z(t_win **display, float trans);
void	iso_list(t_win *display);
void	trans_iso(float *x, float *y, int z);
void	fix_display(t_win **display, int echelle, float angle, float z);
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
t_point		*init_repere(char **tab_pts, t_point *list, int y);
void		display_repere(t_win *display);
int		ft_x_max(t_point *list);
t_point	*read_to_list(int fd, t_win *display);
void	ft_display(t_win *display);
void	set_display(t_win *display, int x_win, int y_win, float echelle);
void	ft_echelle(t_win **display, float echelle);
void	display_display(t_win *display);
void	ft_relier_h(t_win *display);
void	display_point(t_point *tpoint);
void	ft_origin(t_win **display);
void	ft_relier_v(t_win *display);
void	rotation_y(float teta, float *x, float *z, t_win *display);
void	rotation_list_y(t_win *display, float angle);
int		deal_toto(int key, t_win *display);
int		deal_key_couleur(int key, t_win *display);
#endif
