/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:24:35 by rjoella           #+#    #+#             */
/*   Updated: 2020/11/25 18:22:56 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_percent(const char *str, int *total, int *count, va_list *ap)
{
	char	*pars_str;
	int		i;

	pars_str = NULL;
	i = 1;
	while (!(ft_strchr("%cspdiuxX", str[i])))
		i++;
	pars_str = ft_substr(str, 1, i);
	if ((*count = *count + ft_parser(&pars_str, &(*ap))) == -1)
		return (-1);
	*total = *total + ft_strlen(pars_str) + 1;
	free(pars_str);
	return (i + 1);
}

int		ft_printf(const char *str, ...)
{
	va_list ap;
	int		i;
	int		count;
	int		total;

	i = 0;
	count = 0;
	total = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
			if ((i = i + ft_check_percent(&str[i], &total, &count, &ap)) == -1)
				break ;
		if (str[i] == '\0')
			break ;
		if (str[i] == '%')
			continue ;
		write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (ft_strlen(str) - total + count);
}
