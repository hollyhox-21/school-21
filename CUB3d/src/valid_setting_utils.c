/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_setting_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:29:28 by rjoella           #+#    #+#             */
/*   Updated: 2020/12/27 17:43:06 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_add_spaces(char ***map)
{
	int		max_size_line;
	int		y;
	char	*tmp;

	max_size_line = 0;
	y = -1;
	while ((*map)[++y])
	{
		if (max_size_line < ft_strlen((*map)[y]))
			max_size_line = ft_strlen((*map)[y]);
	}
	y = -1;
	while ((*map)[++y])
	{
		while (ft_strlen((*map)[y]) < max_size_line)
		{
			tmp = (*map)[y];
			if (!((*map)[y] = ft_strjoin((*map)[y], " ")))
				return (-1);
			free(tmp);
		}
	}
	return (1);
}

int		ft_check_spaces(int x, int y, char **map)
{
	while (y < (ft_count_token(map) - 1))
	{
		x = 1;
		while (x < (ft_strlen(map[y]) - 1))
		{
			if (map[y][x] == ' ')
			{
				if (!(ft_check_env(x, y, map, 1)))
					return (-9);
			}
			if (map[y][x] == '0')
			{
				if (!(ft_check_env(x, y, map, 2)))
					return (-9);
			}
			if (map[y][x] == '2')
			{
				if (!(ft_check_env(x, y, map, 2)))
					return (-9);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int		ft_check_outline(int x, int y, char **map)
{
	while (y < ft_count_token(map))
	{
		x = 0;
		while (x < ft_strlen(map[y]))
		{
			if (y == 0 || y == (ft_count_token(map) - 1))
			{
				if (ft_strchr("02NWES", map[y][x]))
					return (-9);
				x++;
			}
			if (y != 0 || y != (ft_count_token(map) - 1))
			{
				if (ft_strchr("02NWES", map[y][0]) ||
					ft_strchr("02NWES", map[y][ft_strlen(map[y]) - 1]))
					return (-9);
				x++;
			}
		}
		y++;
	}
	return (1);
}

int		ft_chr_start(int *x, int *y, char **map, int *simb)
{
	while (*y < ft_count_token(map))
	{
		(*x) = 0;
		while (*x < ft_strlen(map[*y]))
		{
			if (ft_strchr("NWES", map[*y][*x]))
			{
				*simb = map[*y][*x];
				return (1);
			}
			(*x)++;
		}
		(*y)++;
	}
	return (0);
}

int		ft_check_valid_simbol(char **map, int x, int y)
{
	int count;

	count = 0;
	while (y < ft_count_token(map))
	{
		x = 0;
		while (x < ft_strlen(map[y]))
		{
			if (ft_strchr("NEWS", map[y][x]))
				count++;
			if (!(ft_strchr("012NEWS ", map[y][x])))
				return (-7);
			x++;
		}
		y++;
	}
	if (count == 1)
		return (1);
	return (-8);
}
