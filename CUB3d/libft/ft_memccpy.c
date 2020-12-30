/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:04:09 by rjoella           #+#    #+#             */
/*   Updated: 2020/10/30 18:17:36 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int k;

	k = 0;
	if (n == 0 || (dest == NULL && src == NULL))
		return (NULL);
	while (--n >= 0)
	{
		*((char *)(dest + k)) = *((char *)(src + k));
		if (*(unsigned char *)(src + k) != (unsigned char)c && n == 0)
			return (NULL);
		if (*(unsigned char *)(src + k) == (unsigned char)c)
			return ((unsigned char *)dest + k + 1);
		k++;
	}
	return (NULL);
}
