/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs_xpm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:51:23 by rjoella           #+#    #+#             */
/*   Updated: 2020/12/26 17:51:27 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_init_images_two(t_all *all)
{
	if (!(all->text.img_ea.img = mlx_xpm_file_to_image(all->win.mlx,
	all->setting->res_tex.ea, &(all->text.img_ea.w),
	&(all->text.img_ea.h))))
		return (-10);
	all->text.img_ea.addr = mlx_get_data_addr(all->text.img_ea.img,
	&(all->text.img_ea.bpp), &(all->text.img_ea.line_l),
	&(all->text.img_ea.en));
	if (!(all->text.img_we.img = mlx_xpm_file_to_image(all->win.mlx,
	all->setting->res_tex.we, &(all->text.img_we.w),
	&(all->text.img_we.h))))
		return (-10);
	all->text.img_we.addr = mlx_get_data_addr(all->text.img_we.img,
	&(all->text.img_we.bpp), &(all->text.img_we.line_l),
	&(all->text.img_we.en));
	return (1);
}

int	ft_init_images(t_all *all)
{
	if (!(all->text.img_s.img = mlx_xpm_file_to_image(all->win.mlx,
	all->setting->res_tex.s, &(all->text.img_s.w),
	&(all->text.img_s.h))))
		return (-10);
	all->text.img_s.addr = mlx_get_data_addr(all->text.img_s.img,
	&(all->text.img_s.bpp), &(all->text.img_s.line_l),
	&(all->text.img_s.en));
	if (!(all->text.img_no.img = mlx_xpm_file_to_image(all->win.mlx,
	all->setting->res_tex.no, &(all->text.img_no.w),
	&(all->text.img_no.h))))
		return (-10);
	all->text.img_no.addr = mlx_get_data_addr(all->text.img_no.img,
	&(all->text.img_no.bpp), &(all->text.img_no.line_l),
	&(all->text.img_no.en));
	if (!(all->text.img_so.img = mlx_xpm_file_to_image(all->win.mlx,
	all->setting->res_tex.so, &(all->text.img_so.w),
	&(all->text.img_so.h))))
		return (-10);
	all->text.img_so.addr = mlx_get_data_addr(all->text.img_so.img,
	&(all->text.img_so.bpp), &(all->text.img_so.line_l),
	&(all->text.img_so.en));
	if (ft_init_images_two(all) < 0)
		return (-10);
	return (1);
}
