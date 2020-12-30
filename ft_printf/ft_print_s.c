/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:58:46 by rjoella           #+#    #+#             */
/*   Updated: 2020/11/25 18:18:46 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cutstr(char **res, int presion)
{
	char	*str_ready;
	int		i;
	char	*tmp;

	i = 0;
	str_ready = (char *)malloc(sizeof(char) * (presion + 1));
	while (presion > 0)
	{
		str_ready[i] = (*res)[i];
		i++;
		presion--;
	}
	str_ready[i] = '\0';
	tmp = *res;
	*res = str_ready;
	free(tmp);
}

int		ft_print_s(t_spec *obj, va_list *ap)
{
	char	*str;
	int		count;
	char	*res;

	str = va_arg(*ap, char *);
	if (!str)
		res = ft_strdup("(null)");
	else
		res = ft_strdup(str);
	if (obj->precision >= 0)
		ft_cutstr(&res, obj->precision);
	if (obj->flags == 0)
	{
		while (obj->width - ft_strlen(res) > 0)
			ft_join_simbol_two(&res, 4);
	}
	if (obj->flags == '-')
	{
		while (obj->width - ft_strlen(res) > 0)
			ft_join_simbol_one(&res, obj, 2);
	}
	count = ft_putstr_fd(res, 1);
	free(res);
	return (count);
}
