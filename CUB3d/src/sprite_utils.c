/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:23:25 by rjoella           #+#    #+#             */
/*   Updated: 2020/12/25 00:18:13 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_swap_sprite(t_sprite_mas *a, t_sprite_mas *b)
{
	t_sprite_mas c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_sprite(t_sprite_mas arr[], int count)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < count)
	{
		j = count - 1;
		while (j > i)
		{
			if (arr[j - 1].dist < arr[j].dist)
				ft_swap_sprite(&arr[j], &arr[j - 1]);
			j--;
		}
		i++;
	}
}

int		ft_count_sprite(char **map)
{
	int x;
	int y;
	int count_sprite;

	count_sprite = 0;
	x = 0;
	y = 0;
	while (y < ft_count_token(map))
	{
		x = 0;
		while (x < ft_strlen(map[y]))
		{
			if (map[y][x] == '2')
				count_sprite++;
			x++;
		}
		y++;
	}
	return (count_sprite);
}

void	cast_sprite_mass(t_sprite_mas *sprite, char **map)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	while (y < ft_count_token(map))
	{
		x = 0;
		while (x < ft_strlen(map[y]))
		{
			if (map[y][x] == '2')
			{
				sprite[i].spr_x = x + 0.5;
				sprite[i].spr_y = y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}
