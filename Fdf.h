/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 02:08:25 by bebosson          #+#    #+#             */
/*   Updated: 2019/05/28 18:35:46 by bebosson         ###   ########.fr       */
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
	float x;
	float y;
	float z;
	int couleur;
	struct s_point *next; 
}				t_point;
// Tout faire en float ? 
typedef struct	s_win
{
	void	*mlx;
	void	*win_ptr_s;
	void	*img;
	int *addr;
	//castablen en int
	int		screen;
	float x_o;
	float y_o;
	float		x_win;
	float		y_win;
	float		x_max;
	float		y_max;
	float		x_min;
	float		y_min;
	float		z;
	int			xinc;
	int			yinc;
	float		echelle;
	float		angle;
	int		couleur;
	//Couleur (en hexa)
	//screen en fonction de display->x_max et display->y_max
	t_point *tpoint;
//	t_point *t_zpoint;
}				t_win;

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
void	ft_coor_x(t_win **display, int trans);
void	ft_coor_y(t_win **display, int trans);
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
t_point		*init_repere(char **tab_pts, t_point **list, int y);
void		display_repere(t_win *display);
int		ft_x_max(t_point *list);
t_point	*read_to_list(int fd, t_win *display);
void	ft_display(t_win *display);
void	set_display(t_win *display, int x_win, int y_win, float echelle);
void	ft_echelle(t_win **display, float echelle);
int	barre_pixel(int button, int x, int y, t_win *display);
int	trait(int max, int min, float ratio, t_win *display, float toto);
void	display_display(t_win *display);
void	ft_relier_h(t_win *display);
void	display_point(t_point *tpoint);
void	ft_origin(t_win **display, int echelle, float angle, int iso);
void	ft_relier_v(t_win *display);
void	rotation_y(float teta, float *x, float *z, t_win *display);
void	rotation_list_y(t_win *display, float angle);
int		deal_toto(int key, t_win *display);
#endif
