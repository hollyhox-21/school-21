/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:41:16 by rjoella           #+#    #+#             */
/*   Updated: 2020/11/24 19:59:21 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_c(t_spec *obj, va_list *ap)
{
	char	res;
	int		count;

	count = 0;
	res = va_arg(*ap, int);
	if (obj->flags == 0)
	{
		while (--obj->width > 0)
		{
			write(1, " ", 1);
			count++;
		}
		write(1, &res, 1);
	}
	if (obj->flags == '-')
	{
		write(1, &res, 1);
		while (--obj->width > 0)
		{
			write(1, " ", 1);
			count++;
		}
	}
	count++;
	return (count);
}
