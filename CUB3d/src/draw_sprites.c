/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:42:41 by rjoella           #+#    #+#             */
/*   Updated: 2020/12/28 13:39:52 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_sprt_screen(t_all *all, t_sprite_mas sprt[], int sprt_ordr[], int i)
{
	all->sprt.sprite_x = sprt[sprt_ordr[i]].spr_x - all->plr.pos_x;
	all->sprt.sprite_y = sprt[sprt_ordr[i]].spr_y - all->plr.pos_y;
	all->sprt.inv_det = 1.0 / (all->plr.plane_x * all->plr.dir_y -
	all->plr.dir_x * all->plr.plane_y);
	all->sprt.transform_x = all->sprt.inv_det * (all->plr.dir_y *
	all->sprt.sprite_x - all->plr.dir_x * all->sprt.sprite_y);
	all->sprt.transform_y = all->sprt.inv_det * (-(all->plr.plane_y) *
	all->sprt.sprite_x + all->plr.plane_x * all->sprt.sprite_y);
	all->sprt.sprite_screen_x = (int)((all->setting->res_reso.width / 2) *
	(1 + all->sprt.transform_x / all->sprt.transform_y));
}

void	ft_sprite_w_h(t_all *all)
{
	all->sprt.sprite_hight = abs((int)(all->setting->res_reso.hight /
	all->sprt.transform_y));
	all->sprt.draw_start_y = -all->sprt.sprite_hight / 2 +
	all->setting->res_reso.hight / 2;
	if (all->sprt.draw_start_y < 0)
		all->sprt.draw_start_y = 0;
	all->sprt.draw_end_y = all->sprt.sprite_hight / 2 +
	all->setting->res_reso.hight / 2;
	if (all->sprt.draw_end_y >= all->setting->res_reso.hight)
		all->sprt.draw_end_y = all->setting->res_reso.hight - 1;
	all->sprt.sprite_width = abs((int)(all->setting->res_reso.width /
	all->sprt.transform_y));
	all->sprt.draw_start_x = -all->sprt.sprite_width / 2 +
	all->sprt.sprite_screen_x;
	if (all->sprt.draw_start_x < 0)
		all->sprt.draw_start_x = 0;
	all->sprt.draw_end_x = all->sprt.sprite_width / 2 +
	all->sprt.sprite_screen_x;
	if (all->sprt.draw_end_x >= all->setting->res_reso.width)
		all->sprt.draw_end_x = all->setting->res_reso.width - 1;
	all->sprt.stripe = all->sprt.draw_start_x;
}

void	ft_draw_sprite(t_all *all, float z_buffer[], int *clr)
{
	while (all->sprt.stripe < all->sprt.draw_end_x)
	{
		all->sprt.tex_x = (int)((256 * (all->sprt.stripe -
		(-all->sprt.sprite_width / 2 + all->sprt.sprite_screen_x)) *
		all->text.img_s.w / all->sprt.sprite_width) / 256);
		if (all->sprt.transform_y > 0 && all->sprt.stripe > 0 &&
		all->sprt.stripe < all->setting->res_reso.width &&
		all->sprt.transform_y < z_buffer[all->sprt.stripe])
		{
			all->sprt.y = all->sprt.draw_start_y;
			while (all->sprt.y < all->sprt.draw_end_y)
			{
				all->sprt.d = all->sprt.y * 256 - all->setting->
				res_reso.hight * 128 + all->sprt.sprite_hight * 128;
				all->sprt.tex_y = ((all->sprt.d * all->text.img_s.h)
				/ all->sprt.sprite_hight) / 256;
				*clr = get_color_sprite(all, all->sprt.tex_x, all->sprt.tex_y);
				if ((*clr & 0x00FFFFFF) != 0)
					my_mlx_pixel_put(all, all->sprt.stripe, all->sprt.y, *clr);
				(all->sprt.y)++;
			}
		}
		(all->sprt.stripe)++;
	}
}

void	sprits(t_all *all, float z_buffer[])
{
	t_sprite_mas	sprite[ft_count_sprite(all->setting->map)];
	int				sprite_order[ft_count_sprite(all->setting->map)];
	int				i;
	int				color;

	i = -1;
	cast_sprite_mass(sprite, all->setting->map);
	while (++i < ft_count_sprite(all->setting->map))
	{
		sprite_order[i] = i;
		sprite[i].num = i;
		sprite[i].dist = ((all->plr.pos_x - sprite[i].spr_x) * (all->plr.pos_x
		- sprite[i].spr_x) + (all->plr.pos_y - sprite[i].spr_y) *
		(all->plr.pos_y - sprite[i].spr_y));
	}
	ft_sort_sprite(sprite, ft_count_sprite(all->setting->map));
	i = -1;
	while (++i < ft_count_sprite(all->setting->map))
	{
		ft_sprt_screen(all, sprite, sprite_order, i);
		ft_sprite_w_h(all);
		ft_draw_sprite(all, z_buffer, &color);
	}
}
