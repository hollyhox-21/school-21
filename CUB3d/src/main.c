/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:56:04 by rjoella           #+#    #+#             */
/*   Updated: 2020/12/26 13:32:04 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	int				fd_cub;
	int				screen;
	t_all			res_all;

	screen = 0;
	if (argc == 2 || argc == 3)
	{
		if (argc == 3)
			screen = 1;
		if ((g_error = ft_check_param(argv[1], argv[2])) < 0)
			ft_errors(g_error);
		if ((fd_cub = open(argv[1], O_RDONLY)) == -1)
			ft_errors(-10);
		if ((g_error = ft_parser(fd_cub, &res_all)) < 0)
			ft_errors(g_error);
		else
			write(1, "--->ALL RIGHT, LET'S GO\n", 24);
		ft_init_start_vars(&res_all);
		if ((g_error = init_head_win(&res_all, screen)) < 0)
			ft_errors(g_error);
	}
	ft_errors(-13);
	return (0);
}
