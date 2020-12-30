/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 17:40:54 by rjoella           #+#    #+#             */
/*   Updated: 2020/12/25 17:49:03 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	turn_left(t_all *all, float *old_dir_x, float *old_pln_x)
{
	*old_dir_x = all->plr.dir_x;
	all->plr.dir_x = all->plr.dir_x * cos(-RS) -
	all->plr.dir_y * sin(-RS);
	all->plr.dir_y = *old_dir_x * sin(-RS) + all->plr.dir_y * cos(-RS);
	*old_pln_x = all->plr.plane_x;
	all->plr.plane_x = all->plr.plane_x * cos(-RS) -
	all->plr.plane_y * sin(-RS);
	all->plr.plane_y = *old_pln_x * sin(-RS) + all->plr.plane_y * cos(-RS);
	if (!all->keys.w && !all->keys.s && !all->keys.a && !all->keys.d)
		render(all);
}

void	turn_right(t_all *all, float *old_dir_x, float *old_pln_x)
{
	*old_dir_x = all->plr.dir_x;
	all->plr.dir_x = all->plr.dir_x * cos(RS) -
	all->plr.dir_y * sin(RS);
	all->plr.dir_y = *old_dir_x * sin(RS) + all->plr.dir_y * cos(RS);
	*old_pln_x = all->plr.plane_x;
	all->plr.plane_x = all->plr.plane_x * cos(RS) -
	all->plr.plane_y * sin(RS);
	all->plr.plane_y = *old_pln_x * sin(RS) + all->plr.plane_y * cos(RS);
	if (!all->keys.w && !all->keys.s && !all->keys.a && !all->keys.d)
		render(all);
}

int		ft_mouse(int x, int y, t_all *all)
{
	float old_dir_x;
	float old_pln_x;

	mlx_mouse_move(all->win.win, 0, 0);
	if (x < 0)
		turn_left(all, &old_dir_x, &old_pln_x);
	if (x > 0)
		turn_right(all, &old_dir_x, &old_pln_x);
	mlx_mouse_get_pos(all->win.win, &x, &y);
	return (1);
}
