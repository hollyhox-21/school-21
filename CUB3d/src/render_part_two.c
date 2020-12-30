/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_part_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:36:01 by rjoella           #+#    #+#             */
/*   Updated: 2020/12/28 13:53:58 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_distance_for_side(t_all *all)
{
	all->plr.hit = 0;
	if (all->plr.ray_dir_x < 0)
	{
		all->plr.step_x = -1;
		all->plr.side_dist_x = (all->plr.pos_x - all->plr.map_x) *
		all->plr.delta_dist_x;
	}
	else
	{
		all->plr.step_x = 1;
		all->plr.side_dist_x = (all->plr.map_x + 1.0 - all->plr.pos_x) *
		all->plr.delta_dist_x;
	}
	if (all->plr.ray_dir_y < 0)
	{
		all->plr.step_y = -1;
		all->plr.side_dist_y = (all->plr.pos_y - all->plr.map_y) *
		all->plr.delta_dist_y;
	}
	else
	{
		all->plr.step_y = 1;
		all->plr.side_dist_y = (all->plr.map_y + 1.0 - all->plr.pos_y) *
		all->plr.delta_dist_y;
	}
}

void	ft_found_side(t_all *all)
{
	while (all->plr.hit == 0)
	{
		if (all->plr.side_dist_x < all->plr.side_dist_y)
		{
			all->plr.side_dist_x += all->plr.delta_dist_x;
			all->plr.map_x += all->plr.step_x;
			if (all->plr.pos_x > all->plr.map_x)
				all->plr.side = 1;
			else
				all->plr.side = 3;
		}
		else
		{
			all->plr.side_dist_y += all->plr.delta_dist_y;
			all->plr.map_y += all->plr.step_y;
			if (all->plr.pos_y > all->plr.map_y)
				all->plr.side = 2;
			else
				all->plr.side = 4;
		}
		if (!ft_strchr("02NEWS",
		all->setting->map[all->plr.map_y][all->plr.map_x]))
			all->plr.hit = 1;
	}
}

void	ft_draw_s_draw_e(t_all *all)
{
	all->plr.line_height = (int)(all->setting->res_reso.hight /
	all->plr.perp_wall_dist);
	all->plr.draw_start = -all->plr.line_height / 2 +
	all->setting->res_reso.hight / 2;
	if (all->plr.draw_start < 0)
		all->plr.draw_start = 0;
	all->plr.draw_end = all->plr.line_height / 2 +
	all->setting->res_reso.hight / 2;
	if (all->plr.draw_end >= all->setting->res_reso.hight)
		all->plr.draw_end = all->setting->res_reso.hight - 1;
	if (all->plr.side == 1 || all->plr.side == 3)
	{
		all->plr.perp_wall_dist = (all->plr.map_x - all->plr.pos_x +
		(1 - all->plr.step_x) / 2) / all->plr.ray_dir_x;
		all->plr.wall_x = all->plr.pos_y + all->plr.perp_wall_dist *
		all->plr.ray_dir_y;
	}
	if (all->plr.side == 2 || all->plr.side == 4)
	{
		all->plr.perp_wall_dist = (all->plr.map_y - all->plr.pos_y +
		(1 - all->plr.step_y) / 2) / all->plr.ray_dir_y;
		all->plr.wall_x = all->plr.pos_x + all->plr.perp_wall_dist *
		all->plr.ray_dir_x;
	}
	all->plr.wall_x -= floor(all->plr.wall_x);
}

void	ft_tex_x(t_all *all)
{
	if (all->plr.side == 1)
	{
		all->plr.tex_x = (int)(all->plr.wall_x *
		(double)(all->text.img_no.w));
		all->plr.tex_x = all->text.img_no.w - all->plr.tex_x - 1;
		all->plr.step = 1.0 * all->text.img_no.h /
		all->plr.line_height;
	}
	if (all->plr.side == 3)
	{
		all->plr.tex_x = (int)(all->plr.wall_x *
		(double)(all->text.img_so.w));
		all->plr.tex_x = all->text.img_so.w - all->plr.tex_x - 1;
		all->plr.step = 1.0 * all->text.img_so.h /
		all->plr.line_height;
	}
}

void	ft_tex_y(t_all *all)
{
	if (all->plr.side == 2)
	{
		all->plr.tex_x = (int)(all->plr.wall_x *
		(double)(all->text.img_we.w));
		all->plr.tex_x = all->text.img_ea.w - all->plr.tex_x - 1;
		all->plr.step = 1.0 * all->text.img_ea.h /
		all->plr.line_height;
	}
	if (all->plr.side == 4)
	{
		all->plr.tex_x = (int)(all->plr.wall_x *
		(double)(all->text.img_ea.w));
		all->plr.tex_x = all->text.img_we.w - all->plr.tex_x - 1;
		all->plr.step = 1.0 * all->text.img_we.h /
		all->plr.line_height;
	}
}
