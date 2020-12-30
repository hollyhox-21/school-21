/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:03:16 by rjoella           #+#    #+#             */
/*   Updated: 2020/12/29 11:56:36 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		get_color_sprite(t_all *all, int x, int y)
{
	int	color;

	color = 0;
	x = abs(x);
	y = abs(y);
	if (!all->text.img_s.w || !all->text.img_s.h)
		return (0);
	if (x > all->text.img_s.w || y > all->text.img_s.h)
		return (0);
	color = (*(int *)(all->text.img_s.addr + ((x + (y *
	all->text.img_s.w)) * (all->text.img_s.bpp / 8))));
	return (color);
}

int		get_color_north(t_all *all, int x, int y)
{
	int color;

	color = 0;
	x = abs(x);
	y = abs(y);
	if (!all->text.img_no.w || !all->text.img_no.h)
		return (0);
	if (x > all->text.img_no.w || y > all->text.img_no.h)
		return (0);
	color = (*(int *)(all->text.img_no.addr + ((x + (y *
	all->text.img_no.w)) * (all->text.img_no.bpp / 8))));
	return (color);
}

int		get_color_south(t_all *all, int x, int y)
{
	int color;

	color = 0;
	x = abs(x);
	y = abs(y);
	if (!all->text.img_so.w || !all->text.img_so.h)
		return (0);
	if (x > all->text.img_so.w || y > all->text.img_so.h)
		return (0);
	color = (*(int *)(all->text.img_so.addr + ((x + (y *
	all->text.img_so.w)) * (all->text.img_so.bpp / 8))));
	return (color);
}

int		get_color_west(t_all *all, int x, int y)
{
	int color;

	color = 0;
	x = abs(x);
	y = abs(y);
	if (!all->text.img_we.w || !all->text.img_we.h)
		return (0);
	if (x > all->text.img_we.w || y > all->text.img_we.h)
		return (0);
	color = (*(int *)(all->text.img_we.addr + ((x + (y *
	all->text.img_we.w)) * (all->text.img_we.bpp / 8))));
	return (color);
}

int		get_color_east(t_all *all, int x, int y)
{
	int color;

	color = 0;
	x = abs(x);
	y = abs(y);
	if (!all->text.img_ea.w || !all->text.img_ea.h)
		return (0);
	if (x > all->text.img_ea.w || y > all->text.img_ea.h)
		return (0);
	color = (*(int *)(all->text.img_ea.addr + ((x + (y *
	all->text.img_ea.w)) * (all->text.img_ea.bpp / 8))));
	return (color);
}
