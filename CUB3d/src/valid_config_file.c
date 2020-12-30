/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_config_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 12:11:04 by rjoella           #+#    #+#             */
/*   Updated: 2020/12/26 15:52:24 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_validator3000(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if ((g_error = ft_check_valid_simbol(map, x, y)) < 0)
		return (g_error);
	if ((g_error = ft_add_spaces(&map)) < 0)
		return (g_error);
	if ((g_error = ft_check_outline(x, y, map)) < 0)
		return (g_error);
	if ((g_error = ft_check_spaces(++x, ++y, map)))
		return (g_error);
	return (1);
}

char	**ft_make_map(t_list **head_map, int size)
{
	char	**map;
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *head_map;
	if (!(map = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (tmp)
	{
		map[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}

int		ft_valid_setting(t_setting_map *set_strc)
{
	if (set_strc->res_reso.width <= 0 || set_strc->res_reso.hight <= 0)
		return (-4);
	if (set_strc->res_reso.width > 2500)
		set_strc->res_reso.width = 2500;
	if (set_strc->res_reso.hight > 1300)
		set_strc->res_reso.hight = 1300;
	if (!set_strc->res_tex.no || !set_strc->res_tex.we ||
		!set_strc->res_tex.ea || !set_strc->res_tex.so ||
		!set_strc->res_tex.s)
		return (-5);
	if (set_strc->res_col.floor > 0xFFFFFF || set_strc->res_col.floor < 0 ||
		set_strc->res_col.ceiling > 0xFFFFFF || set_strc->res_col.ceiling < 0)
		return (-6);
	return (1);
}

int		ft_close(void)
{
	exit(1);
}
