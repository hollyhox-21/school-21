/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:16:08 by rjoella           #+#    #+#             */
/*   Updated: 2020/11/25 18:20:22 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_x(t_spec *obj, va_list *ap)
{
	unsigned int	nb;
	int				count;
	long int		tmp_nb;
	char			*res;
	char			*ch_nb;

	if (!(res = ft_strdup("")))
		return (0);
	nb = va_arg(*ap, unsigned int);
	tmp_nb = nb;
	ch_nb = ft_work_with_nb(&tmp_nb, obj, "Ox", 16);
	if (obj->precision >= 0 || obj->flags == '-')
		ft_check_precision(&res, &ch_nb, obj);
	if (obj->precision == -1 && obj->flags != '-' && !*res)
		ft_check_flags(&res, &ch_nb, obj);
	free(ch_nb);
	free(obj->signed_nb);
	if (obj->type == 'X')
		ft_toupper(&res);
	count = ft_putstr_fd(res, 1);
	free(res);
	return (count);
}
