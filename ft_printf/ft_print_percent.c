/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:15:53 by rjoella           #+#    #+#             */
/*   Updated: 2020/11/25 18:21:07 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flag_percent(t_spec *obj, int *count, int *res)
{
	if (obj->flags == '0')
	{
		while (--obj->width > 0)
		{
			write(1, "0", 1);
			(*count)++;
		}
		write(1, &(*res), 1);
	}
	if (obj->flags == '-')
	{
		write(1, &(*res), 1);
		while (--obj->width > 0)
		{
			write(1, " ", 1);
			(*count)++;
		}
	}
}

int		ft_print_percent(t_spec *obj)
{
	int		res;
	int		count;

	count = 0;
	res = '%';
	if (obj->flags == 0)
	{
		while (--obj->width > 0)
		{
			write(1, " ", 1);
			count++;
		}
		write(1, &res, 1);
	}
	if (obj->flags)
		ft_check_flag_percent(obj, &count, &res);
	count++;
	return (count);
}
