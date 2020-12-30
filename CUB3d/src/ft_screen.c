/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 18:54:33 by rjoella           #+#    #+#             */
/*   Updated: 2020/12/25 00:17:55 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	make_head(unsigned char *bmp_head, unsigned char *bmp_fhead, t_all *all)
{
	int		size;

	size = 14 + 40 + all->setting->res_reso.width * all->setting->res_reso.hight
			* all->win.bpp / 8;
	bmp_head[0] = 'B';
	bmp_head[1] = 'M';
	bmp_head[2] = (unsigned char)(size);
	bmp_head[3] = (unsigned char)(size >> 8);
	bmp_head[4] = (unsigned char)(size >> 16);
	bmp_head[5] = (unsigned char)(size >> 24);
	bmp_head[10] = (unsigned char)(54);
	bmp_fhead[0] = (unsigned char)(40);
	bmp_fhead[4] = (unsigned char)(all->setting->res_reso.width);
	bmp_fhead[5] = (unsigned char)(all->setting->res_reso.width >> 8);
	bmp_fhead[6] = (unsigned char)(all->setting->res_reso.width >> 16);
	bmp_fhead[7] = (unsigned char)(all->setting->res_reso.width >> 24);
	bmp_fhead[8] = (unsigned char)(-all->setting->res_reso.hight);
	bmp_fhead[9] = (unsigned char)(-all->setting->res_reso.hight >> 8);
	bmp_fhead[10] = (unsigned char)(-all->setting->res_reso.hight >> 16);
	bmp_fhead[11] = (unsigned char)(-all->setting->res_reso.hight >> 24);
	bmp_fhead[12] = (unsigned char)(1);
	bmp_fhead[14] = (unsigned char)(all->win.bpp);
	return (1);
}

int	make_file_scr(unsigned char *bmp_head, unsigned char *bmp_fhead, t_all *all)
{
	int		fd;
	char	*filename;
	int		i;
	int		size;

	i = 0;
	filename = "screen.bmp";
	if ((fd = open(filename, O_RDWR | O_CREAT, 0777)) < 0)
		return (0);
	write(fd, bmp_head, 14);
	write(fd, bmp_fhead, 40);
	size = all->win.bpp / 8 * all->setting->res_reso.width;
	while (i < all->setting->res_reso.hight)
	{
		write(fd, all->win.addr + i * all->win.line_l, size);
		i++;
	}
	return (1);
}

int	ft_creat_screen(t_all *all)
{
	unsigned char	bmp_head[14];
	unsigned char	bmp_fhead[40];

	write(1, "Saving screenshot\n", 18);
	ft_bzero(bmp_head, 14);
	ft_bzero(bmp_fhead, 40);
	make_head(bmp_head, bmp_fhead, all);
	make_file_scr(bmp_head, bmp_fhead, all);
	mlx_destroy_window(all->win.mlx, all->win.win);
	exit(0);
	return (0);
}
