/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:49:57 by bede-fre          #+#    #+#             */
/*   Updated: 2018/06/29 15:07:35 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_scene		*ft_find_link(t_scene *scene, char name[], int i)
{
	t_scene	*tp;

	tp = scene;
	while (tp)
	{
		if (ft_strequ(tp->name, name) && --i == 0)
			return (tp);
		tp = tp->next;
	}
	return (NULL);
}

static void	ft_init_values(t_all *all)
{
	t_scene		*cam;

	cam = ft_find_link(&all->scene, "cam", 1);
	all->campos.x = (double)cam->px;
	all->campos.y = (double)cam->py;
	all->campos.z = (double)cam->pz;

}

static void	ft_find_coord_pixel(t_all *all, int x, int y)
{
	all->pointpos.x = all->campos.x - 1.0 * (PLAN_W / 2.0);
	all->pointpos.y = all->campos.y + 1.0 * (PLAN_H / 2.0);
	all->pointpos.z = all->campos.z + 1.0 * PLAN_D;
	all->pointpos.x = all->pointpos.x + (double)x * INCR_X;
	all->pointpos.y = all->pointpos.y - (double)y * INCR_Y;
}

void		ft_ray_tracing(t_all *all, int x, int y)
{
	ft_init_values(all);
	ft_find_coord_pixel(all, x, y);
	printf("[%.4f %.4f %.4f]\n", all->pointpos.x, all->pointpos.y, all->pointpos.z);
}
