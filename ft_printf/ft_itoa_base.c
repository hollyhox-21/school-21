/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:51:11 by rjoella           #+#    #+#             */
/*   Updated: 2020/11/24 16:46:36 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_char_str(int simbol)
{
	char *buf;

	if (!(buf = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	buf[1] = '\0';
	if (simbol < 10)
		buf[0] = simbol + 48;
	else
		buf[0] = simbol + 87;
	return (buf);
}

int		convert_itoa(long long int *j, char **buf, int base)
{
	char	*tmp;
	char	*simbol;

	while (*j >= base)
	{
		tmp = *buf;
		simbol = convert_char_str(*j % base);
		if (!(*buf = ft_strjoin(simbol, *buf)))
			return (0);
		free(tmp);
		free(simbol);
		*j = *j / base;
	}
	tmp = *buf;
	simbol = convert_char_str(*j % base);
	if (!(*buf = ft_strjoin(simbol, *buf)))
		return (0);
	free(tmp);
	free(simbol);
	return (1);
}

char	*ft_itoa_base(long long int n, int base)
{
	long long int	j;
	char			*buf;
	char			*tmp;

	j = n;
	if (j < 0)
		j = j * -1;
	if (!(buf = ft_strdup("")))
		return (NULL);
	if (!(convert_itoa(&j, &buf, base)))
		return (NULL);
	if (n < 0)
	{
		tmp = buf;
		if (!(buf = ft_strjoin("-", buf)))
			return (NULL);
		free(tmp);
	}
	return (buf);
}
