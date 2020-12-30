/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:28:35 by rjoella           #+#    #+#             */
/*   Updated: 2020/12/24 23:02:25 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		count;
	char	*buf;

	count = 0;
	if (s == NULL)
		return (0);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if ((int)start >= ft_strlen(s))
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
