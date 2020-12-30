/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_part_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:00:10 by rjoella           #+#    #+#             */
/*   Updated: 2020/12/28 15:27:18 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_draw_celling(t_all *all, int x, int *y)
{
	while (++(*y) < all->plr.draw_start)
		my_mlx_pixel_put(all, x, *y, all->setting->res_col.ceiling);
}

void	ft_draw_world(t_all *all, int x, int *y, int color)
{
	all->plr.draw_start--;
	while (all->plr.draw_start++ < all->plr.draw_end)
	{
		if (all->plr.side == 1)
			all->plr.tex_y = (int)all->plr.tex_pos & (all->text.img_no.h - 1);
		if (all->plr.side == 3)
			all->plr.tex_y = (int)all->plr.tex_pos & (all->text.img_so.h - 1);
		if (all->plr.side == 2)
			all->plr.tex_y = (int)all->plr.tex_pos & (all->text.img_ea.h - 1);
		if (all->plr.side == 4)
			all->plr.tex_y = (int)all->plr.tex_pos & (all->text.img_we.h - 1);
		all->plr.tex_pos += all->plr.step;
		if (all->plr.side == 2)
			color = get_color_north(all, all->plr.tex_x, all->plr.tex_y);
		if (all->plr.side == 4)
			color = get_color_south(all, all->plr.tex_x, all->plr.tex_y);
		if (all->plr.side == 1)
			color = get_color_west(all, all->plr.tex_x, all->plr.tex_y);
		if (all->plr.side == 3)
			color = get_color_east(all, all->plr.tex_x, all->plr.tex_y);
		my_mlx_pixel_put(all, x, all->plr.draw_start, color);
		(*y)++;
	}
}

void	ft_draw_floor(t_all *all, int x, int *y)
{
	while (++(*y) < all->setting->res_reso.hight)
		my_mlx_pixel_put(all, x, *y, (*all).setting->res_col.floor);
}

void	ft_fov(t_all *all, int x)
{
	all->plr.camera_x = 2 * (x) / (float)all->setting->res_reso.width - 1;
	all->plr.ray_dir_x = all->plr.dir_x + all->plr.plane_x * all->plr.camera_x;
	all->plr.ray_dir_y = all->plr.dir_y + all->plr.plane_y * all->plr.camera_x;
	all->plr.map_x = (int)all->plr.pos_x;
	all->plr.map_y = (int)all->plr.pos_y;
	if (all->plr.ray_dir_x == 0)
		all->plr.delta_dist_y = 0;
	else
		all->plr.delta_dist_y = (all->plr.ray_dir_y == 0) ? 1 :
		fabs(1 / all->plr.ray_dir_y);
	if (all->plr.ray_dir_y == 0)
		all->plr.delta_dist_x = 0;
	else
		all->plr.delta_dist_x = (all->plr.ray_dir_x == 0) ? 1 :
		fabs(1 / all->plr.ray_dir_x);
}

void	render(t_all *all)
{
	int		x;
	int		y;
	int		color;
	float	z_buffer[all->setting->res_reso.width];

	color = 0;
	x = -1;
	while (++x < all->setting->res_reso.width)
	{
		ft_fov(all, x);
		ft_distance_for_side(all);
		ft_found_side(all);
		ft_draw_s_draw_e(all);
		ft_tex_x(all);
		ft_tex_y(all);
		all->plr.tex_pos = (all->plr.draw_start - all->setting->res_reso.hight
		/ 2 + all->plr.line_height / 2) * all->plr.step;
		y = -1;
		ft_draw_celling(all, x - 0.5, &y);
		ft_draw_world(all, x - 0.5, &y, color);
		ft_draw_floor(all, x - 0.5, &y);
		z_buffer[x] = all->plr.perp_wall_dist;
	}
	sprits(all, z_buffer);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->win.img, 0, 0);
}
