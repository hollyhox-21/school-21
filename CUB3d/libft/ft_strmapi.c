/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:24:43 by rjoella           #+#    #+#             */
/*   Updated: 2020/10/30 18:19:11 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		k;
	char	*buf;

	if (s == NULL)
		return (NULL);
	k = ft_strlen(s);
	if ((buf = malloc(k + 1)) == NULL)
		return (NULL);
	ft_bzero(buf, k + 1);
	i = 0;
	while (s[i] != '\0')
	{
		buf[i] = f(i, s[i]);
		i++;
	}
	return (buf);
}
