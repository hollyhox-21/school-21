/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:01:31 by rjoella           #+#    #+#             */
/*   Updated: 2020/10/30 18:18:58 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	int		k;
	int		len_dest;
	int		len_src;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	k = 0;
	i = 0;
	if ((size_t)len_dest >= dstsize)
		return (len_src + dstsize);
	while (dest[i] != '\0' && i < (dstsize - 1))
		i++;
	while (src[k] != '\0' && i < (dstsize - 1))
	{
		dest[i] = src[k];
		k++;
		i++;
	}
	dest[i] = '\0';
	return (len_dest + len_src);
}
