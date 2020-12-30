/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pars_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:40:08 by rjoella           #+#    #+#             */
/*   Updated: 2020/12/29 10:15:06 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_str(char **buf)
{
	if (!**buf)
	{
		free(*buf);
		return (1);
	}
	if (!(ft_strchr("RNWESFC", **buf)))
		return (-3);
	return (1);
}

int	ft_check_env(int x, int y, char **map, int i)
{
	if (i == 1)
	{
		if (ft_strchr("02NWES", map[y][x + 1]) ||
			ft_strchr("02NWES", map[y][x - 1]) ||
			ft_strchr("02NWES", map[y + 1][x]) ||
			ft_strchr("02NWES", map[y - 1][x]))
			return (0);
	}
	if (i == 2)
	{
		if (ft_strchr(" ", map[y][x + 1]) ||
			ft_strchr(" ", map[y][x - 1]) ||
			ft_strchr(" ", map[y + 1][x]) ||
			ft_strchr(" ", map[y - 1][x]))
			return (0);
	}
	return (1);
}

int	ft_null_struct(t_setting_map **res)
{
	if (!(*res = (t_setting_map *)malloc(sizeof(t_setting_map) * 1)))
		return (-1);
	(*res)->res_reso.hight = -1;
	(*res)->res_reso.width = -1;
	(*res)->res_tex.no = NULL;
	(*res)->res_tex.so = NULL;
	(*res)->res_tex.we = NULL;
	(*res)->res_tex.ea = NULL;
	(*res)->res_tex.s = NULL;
	(*res)->res_col.ceiling = -1;
	(*res)->res_col.floor = -1;
	return (1);
}

int	ft_check_rgb(char **str_rgb, int *str_nb)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strtrim(*str_rgb, " ");
	while (tmp[i])
	{
		if (ft_isdigit(tmp[i]))
			i++;
		else
			return (0);
	}
	if (!*tmp)
		return (0);
	*str_nb = ft_atoi(tmp);
	free(tmp);
	return (1);
}
