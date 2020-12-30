/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:28:35 by rjoella           #+#    #+#             */
/*   Updated: 2020/11/24 16:20:48 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(char const *s, int start, int len)
{
	int		count;
	char	*buf;

	count = 0;
	if (s == NULL)
		return (0);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
	{
		buf = malloc(1);
		buf[count] = '\0';
		return (buf);
	}
	if ((buf = malloc(len + 1)) == NULL)
		return (NULL);
	while (len > 0)
	{
		buf[count++] = s[start++];
		len--;
	}
	buf[count] = '\0';
	return (buf);
}
