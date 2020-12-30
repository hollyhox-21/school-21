/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 18:58:24 by rjoella           #+#    #+#             */
/*   Updated: 2020/12/27 22:05:22 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_errors(int err)
{
	write(1, "Error\n", 6);
	(err == -1) ? write(1, "error malloc\n", 13) : 0;
	(err == -2) ? write(1, "error read file\n", 16) : 0;
	(err == -3) ? write(1, "bad string in config fail\n", 26) : 0;
	(err == -4) ? write(1, "bad resolution\n", 15) : 0;
	(err == -5) ? write(1, "miss path to file\n", 18) : 0;
	(err == -6) ? write(1, "bad color FLOOR and CEILING\n", 28) : 0;
	(err == -7) ? write(1, "invalid simbol on the map\n", 26) : 0;
	(err == -8) ? write(1, "extra player on the map\n", 24) : 0;
	(err == -9) ? write(1, "invalid the map, try once more\n", 31) : 0;
	(err == -10) ? write(1, "error opening file\n", 19) : 0;
	(err == -11) ? write(1, "invalid resolution, give me \".CUB\"\n", 35) : 0;
	(err == -12) ? write(1, "invalid second argument, give me \"--save\"\n", 42)
	: 0;
	(err == -13) ? write(1, "invalid count argument. Need 2 or 3 arguments\n",
	46) : 0;
	write(1, "cub3d exit... LOL;D\n", 20);
	exit(1);
}
