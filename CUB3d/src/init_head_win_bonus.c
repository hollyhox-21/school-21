/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_head_win_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:38:00 by rjoella           #+#    #+#             */
/*   Updated: 2020/12/25 22:26:16 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_check_param(char *param_one, char *param_two)
{
	char	*resol;
	int		i;
	int		count;

	resol = ".cub";
	count = ft_strlen(param_one);
	i = 0;
	if (ft_strlen(param_one) >= 4)
	{
		while (i - ft_strlen(resol) &&
		param_one[ft_strlen(param_one) - i] == resol[ft_strlen(resol) - i])
			i++;
		if (i < 4)
			return (-11);
	}
	if (param_two)
	{
		if (ft_strncmp("--save", param_two, 6) || ft_strlen(param_two) != 6)
			return (-12);
	}
	return (1);
}

void	ft_init_start_vars(t_all *all)
{
	all->point.x = 0;
	all->point.y = 0;
	ft_chr_start(&(all->point.x), &(all->point.y), all->setting->map,
	&(all->point.simb));
	all->plr.pos_x = all->point.x + 0.001;
	all->plr.pos_y = all->point.y + 0.001;
	all->plr.dir_x = 1;
	all->plr.dir_y = 0;
	all->plr.plane_x = 0;
	all->plr.plane_y = 0.66;
}

void	ft_turn_plr(t_all *all, char p)
{
	float rotation;
	float old_dir_x;
	float old_plane_x;

	rotation = 3.14159265359;
	if (p == 'N')
		rotation = 0.5 * rotation;
	if (p == 'S')
		rotation = 1.5 * rotation;
	if (p == 'E')
		rotation = 2 * rotation;
	old_dir_x = all->plr.dir_x;
	all->plr.dir_x = all->plr.dir_x * cos(-rotation) -
	all->plr.dir_y * sin(-rotation);
	all->plr.dir_y = old_dir_x * sin(-rotation) + all->plr.dir_y *
	cos(-rotation);
	old_plane_x = all->plr.plane_x;
	all->plr.plane_x = all->plr.plane_x * cos(-rotation) -
	all->plr.plane_y * sin(-rotation);
	all->plr.plane_y = old_plane_x * sin(-rotation) + all->plr.plane_y *
	cos(-rotation);
}

int		init_head_win(t_all *all, int screen)
{
	ft_turn_plr(all, all->point.simb);
	all->win.mlx = mlx_init();
	all->win.win = mlx_new_window(all->win.mlx, all->setting->res_reso.width,
	all->setting->res_reso.hight, "LOVE CUB3D");
	all->win.img = mlx_new_image(all->win.mlx, all->setting->res_reso.width,
	all->setting->res_reso.hight);
	all->win.addr = mlx_get_data_addr(all->win.img, &(all->win.bpp),
	&(all->win.line_l), &(all->win.en));
	if ((g_error = ft_init_images(all)) < 0)
		return (g_error);
	render(all);
	if (screen)
		ft_creat_screen(all);
	mlx_hook(all->win.win, 2, (1L << 0), ft_move, all);
	mlx_hook(all->win.win, 3, (1L << 1), ft_release, all);
	mlx_hook(all->win.win, 17, 0, ft_close, all);
	mlx_mouse_hide();
	mlx_hook(all->win.win, 6, 1L << 6, ft_mouse, all);
	mlx_loop(all->win.mlx);
	return (1);
}
