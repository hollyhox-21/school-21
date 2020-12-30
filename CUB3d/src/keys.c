/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:19:35 by rjoella           #+#    #+#             */
/*   Updated: 2020/12/27 17:44:16 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_up_down(t_all *all, int keycode)
{
	if (keycode == 13)
	{
		if (ft_strchr("0NEWS", all->setting->map[(int)all->plr.pos_y]
		[(int)(all->plr.pos_x + all->plr.dir_x * MS)]))
			all->plr.pos_x += all->plr.dir_x * MS;
		if (ft_strchr("0NEWS", all->setting->map[(int)(all->plr.pos_y +
		all->plr.dir_y * MS)][(int)(all->plr.pos_x)]))
			all->plr.pos_y += all->plr.dir_y * MS;
		all->keys.w = 1;
		render(all);
	}
	if (keycode == 1)
	{
		if (ft_strchr("0NEWS", all->setting->map[(int)all->plr.pos_y]
		[(int)(all->plr.pos_x - all->plr.dir_x * MS)]))
			all->plr.pos_x -= all->plr.dir_x * MS;
		if (ft_strchr("0NEWS", all->setting->map[(int)(all->plr.pos_y -
		all->plr.dir_y * MS)][(int)(all->plr.pos_x)]))
			all->plr.pos_y -= all->plr.dir_y * MS;
		all->keys.s = 1;
		render(all);
	}
}

void	ft_l_r(t_all *all, int keycode, float *old_dir_x, float *old_pln_x)
{
	if (keycode == 123)
	{
		*old_dir_x = all->plr.dir_x;
		all->plr.dir_x = all->plr.dir_x * cos(-RS) - all->plr.dir_y * sin(-RS);
		all->plr.dir_y = *old_dir_x * sin(-RS) + all->plr.dir_y * cos(-RS);
		*old_pln_x = all->plr.plane_x;
		all->plr.plane_x = all->plr.plane_x * cos(-RS) -
		all->plr.plane_y * sin(-RS);
		all->plr.plane_y = *old_pln_x * sin(-RS) + all->plr.plane_y * cos(-RS);
		all->keys.up = 1;
		render(all);
	}
	if (keycode == 124)
	{
		*old_dir_x = all->plr.dir_x;
		all->plr.dir_x = all->plr.dir_x * cos(RS) - all->plr.dir_y * sin(RS);
		all->plr.dir_y = *old_dir_x * sin(RS) + all->plr.dir_y * cos(RS);
		*old_pln_x = all->plr.plane_x;
		all->plr.plane_x = all->plr.plane_x * cos(RS) -
		all->plr.plane_y * sin(RS);
		all->plr.plane_y = *old_pln_x * sin(RS) + all->plr.plane_y * cos(RS);
		all->keys.down = 1;
		render(all);
	}
}

int		ft_release(int keycode, t_all *all)
{
	if (keycode == 13)
		all->keys.w = 0;
	if (keycode == 1)
		all->keys.s = 0;
	if (keycode == 0)
		all->keys.a = 0;
	if (keycode == 2)
		all->keys.d = 0;
	return (1);
}

void	ft_left_right(t_all *all, int keycode)
{
	if (keycode == 2)
	{
		if (ft_strchr("0NEWS", all->setting->map[(int)all->plr.pos_y]
		[(int)(all->plr.pos_x + all->plr.plane_x * MS)]))
			all->plr.pos_x += all->plr.plane_x * MS;
		if (ft_strchr("0NEWS", all->setting->map[(int)(all->plr.pos_y +
		all->plr.plane_y * MS)][(int)(all->plr.pos_x)]))
			all->plr.pos_y += all->plr.plane_y * MS;
		all->keys.d = 1;
		render(all);
	}
	if (keycode == 0)
	{
		if (ft_strchr("0NEWS", all->setting->map[(int)all->plr.pos_y]
		[(int)(all->plr.pos_x - all->plr.plane_x * MS)]))
			all->plr.pos_x -= all->plr.plane_x * MS;
		if (ft_strchr("0NEWS", all->setting->map[(int)(all->plr.pos_y -
		all->plr.plane_y * MS)][(int)(all->plr.pos_x)]))
			all->plr.pos_y -= all->plr.plane_y * MS;
		all->keys.a = 1;
		render(all);
	}
}

int		ft_move(int keycode, t_all *all)
{
	float old_dir_x;
	float old_pln_x;

	ft_up_down(all, keycode);
	ft_left_right(all, keycode);
	ft_l_r(all, keycode, &old_dir_x, &old_pln_x);
	if (keycode == 53)
		exit(1);
	return (1);
}
