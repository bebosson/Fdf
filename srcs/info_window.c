/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 20:09:35 by bebosson          #+#    #+#             */
/*   Updated: 2019/07/29 22:31:18 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_win_info(t_win *d, int (*f) (void *, void *, int, int, int, char *))
{
	char	*r;
	int		c_txt;

	c_txt = 0xffffff;
	f(d->mlx, d->win, 0, 0, d->c->menu, "(1) m -> menu");
	f(d->mlx, d->win, 20, 20, d->c->z, "(2) z -> zoom");
	f(d->mlx, d->win, 40, 40, d->c->z_a, "(3) + -> avant -> - -> arriere");
	f(d->mlx, d->win, 20, 60, d->c->trans, "(2) t->translation ((3) fleches)");
	f(d->mlx, d->win, 20, 80, d->c->r, "(2)rotation(R)");
	f(d->mlx, d->win, 40, 100, d->c->r_y, "(3)selon y");
	f(d->mlx, d->win, 60, 120, c_txt, "(4) 6 -> avant");
	f(d->mlx, d->win, 60, 140, c_txt, "(4) 7 -> arriere");
	f(d->mlx, d->win, 40, 160, d->c->r_x, "(3)selon x");
	f(d->mlx, d->win, 60, 180, c_txt, "(4)s -> avant");
	f(d->mlx, d->win, 60, 200, c_txt, "(4)d -> arriere");
	f(d->mlx, d->win, 40, 220, d->c->r_z, "(3) r selon z (f)");
	f(d->mlx, d->win, 60, 240, c_txt, "(4) q -> avant");
	f(d->mlx, d->win, 60, 260, c_txt, "(4) a -> arriere");
	f(d->mlx, d->win, 40, 280, d->c->c, "(2)couleur(c)(fleches)");
	f(d->mlx, d->win, 60, 300, d->c->c_r, "(3)e->rouge=");
	f(d->mlx, d->win, 60, 320, d->c->c_g, "(3)g->vert=");
	f(d->mlx, d->win, 60, 340, d->c->c_b, "(3)b->bleue=");
	f(d->mlx, d->win, 0, 360, c_txt, "Presser l'ordre:");
	f(d->mlx, d->win, 80, 380, c_txt, "(1)+(2)+(3)+(4)");
}

void	set_colour_info(t_win *data)
{
	data->c->menu = 0xFFFFFF;
	data->c->trans = 0xFFFFFF;
	data->c->z = 0xFFFFFF;
	data->c->z_a = 0xFFFFFF;
	data->c->r = 0xFFFFFF;
	data->c->r_x = 0xFFFFFF;
	data->c->r_y = 0xFFFFFF;
	data->c->r_z = 0xFFFFFF;
	data->c->c_r = 0xFFFFFF;
	data->c->c_g = 0xFFFFFF;
	data->c->c_b = 0xFFFFFF;
	data->c->c = 0xFFFFFF;
}

void	data_borne(t_win *data)
{
	char	*r;
	char	*g;
	char	*b;
	int		c_txt;

	c_txt = 0xFFFFFF;
	mlx_clear_window(data->mlx, data->win);
	ft_win_info(data, &mlx_string_put);
	r = ft_itoa(data->tpoint->r);
	free(r);
	mlx_string_put(data->mlx, data->win, 230, 300, data->c->c_r, r);
	g = ft_itoa(data->tpoint->g);
	mlx_string_put(data->mlx, data->win, 230, 320, data->c->c_g, g);
	free(g);
	b = ft_itoa(data->tpoint->b);
	mlx_string_put(data->mlx, data->win, 230, 340, data->c->c_b, b);
	free(b);
}
