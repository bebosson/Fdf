/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:21:59 by bebosson          #+#    #+#             */
/*   Updated: 2019/06/05 04:02:10 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

int		relier_valide(t_point *pt1, t_point *pt2, t_win *display)
{
	if (pt1->x > display->screen || pt1->y > display->screen)
 		return (0);
	else if (pt2->x > display->screen || pt2->y > display->screen)
		return (0);
	else if (pt1->x < 0 || pt2->x < 0)
		return (0);
	else
		return (1);

}

void	ft_relier_h2(t_win *display)
{
	t_point	*tmp_1;
	t_point	*tmp_2;

	tmp_1 = display->tpoint;
	tmp_2 = display->tpoint->next;
	while (tmp_2->next)
	{
		if ((tmp_1->coor_y == tmp_2->coor_y && relier_valide(tmp_1, tmp_2, display) == 1) || display->echelle <= 1)
			ligne_2(tmp_1,tmp_2,display);
		tmp_2 = tmp_2->next;
		tmp_1 = tmp_1->next;
	}
//	free(tmp_1);
//	free(tmp_2);
	tmp_1 = NULL;
	tmp_2 = NULL;
}

void	ft_relier_v2(t_win *display)
{
	t_point	*tmp_1;
	t_point	*tmp_2;

	tmp_1 = display->tpoint;
	tmp_2 = display->tpoint->next;
	while (tmp_2->coor_x != tmp_1->coor_x)
		tmp_2 = tmp_2->next;
	while (tmp_2->next)
	{
//		printf("%d \n",relier_valide(tmp_1, tmp_2, display));
		if (tmp_1->coor_x ==  tmp_2->coor_x && relier_valide(tmp_1, tmp_2, display) == 1)
			ligne_2(tmp_1,tmp_2,display);
//		else
//		{
//			printf("ligne_v2 = %d \n",relier_valide(tmp_1,tmp_2,display));
//			display_point(tmp_1);
//			display_point(tmp_2);
//		}
		tmp_2 = tmp_2->next;
		tmp_1 = tmp_1->next;
	}
}
void	ft_trace(t_win *display)
{
	mlx_clear_window(display->mlx,display->win_ptr_s);
	ft_relier_h2(display);
	ft_relier_v2(display);
//	display_repere(display);
}



