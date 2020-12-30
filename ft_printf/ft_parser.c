/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:27:11 by rjoella           #+#    #+#             */
/*   Updated: 2020/11/25 18:29:28 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_obj(t_spec *obj, va_list *ap)
{
	if (obj->type == '%')
		return (ft_print_percent(obj));
	if (obj->type == 'c')
		return (ft_print_c(obj, &(*ap)));
	if (obj->type == 's')
		return (ft_print_s(obj, &(*ap)));
	if (obj->type == 'd' || obj->type == 'i')
		return (ft_print_d_i(obj, &(*ap)));
	if (obj->type == 'u')
		return (ft_print_u(obj, &(*ap)));
	if (obj->type == 'p')
		return (ft_print_p(obj, &(*ap)));
	if (obj->type == 'x' || obj->type == 'X')
		return (ft_print_x(obj, &(*ap)));
	return (-1);
}

void	ft_check_flag_obj(char **piese_str, t_spec *obj, int *i)
{
	if (ft_strchr("-0", (*piese_str)[*i]))
	{
		obj->flags = (*piese_str)[*i];
		(*i)++;
	}
	else
		obj->flags = 0;
}

void	ft_check_width_obj(char **piese_str, t_spec *obj, int *i, va_list *ap)
{
	obj->width = ft_atoi(&(*piese_str)[*i]);
	if ((*piese_str)[*i] == '*')
		obj->width = va_arg(*ap, int);
	if (obj->width < 0)
	{
		obj->flags = '-';
		obj->width = obj->width * -1;
	}
}

void	ft_check_pr_obj(char **piese_str, t_spec *obj, int *i, va_list *ap)
{
	if ((*piese_str)[*i] == '.')
	{
		(*i)++;
		if ((*piese_str)[*i] == '*')
			obj->precision = va_arg(*ap, int);
		else
			obj->precision = ft_atoi(&(*piese_str)[*i]);
		if (obj->precision < 0)
			obj->precision = -1;
	}
	else
		obj->precision = -1;
}

int		ft_parser(char **piese_str, va_list *ap)
{
	int		i;
	int		count;
	t_spec	*obj;

	obj = (t_spec *)malloc(sizeof(t_spec) * 1);
	i = 0;
	ft_check_flag_obj(piese_str, obj, &i);
	ft_check_width_obj(piese_str, obj, &i, &(*ap));
	while (!ft_strchr(".%cspdiuxX", (*piese_str)[i]))
		i++;
	ft_check_pr_obj(piese_str, obj, &i, &(*ap));
	while (!ft_strchr("%cspdiuxX", (*piese_str)[i]))
		i++;
	obj->type = (*piese_str)[i];
	count = ft_print_obj(obj, &(*ap));
	free(obj);
	return (count);
}
