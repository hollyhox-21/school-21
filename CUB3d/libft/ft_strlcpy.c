/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:23:45 by rjoella           #+#    #+#             */
/*   Updated: 2020/10/30 18:19:02 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t count)
{
	int i;

	i = 0;
	if (dest == NULL || src == NULL)
		return (0);
	while (src[i] != '\0')
		i++;
	if (count != 0)
	{
		while (--count > 0 && *src)
			*dest++ = *src++;
		*dest = '\0';
	}
	return (i);
}
