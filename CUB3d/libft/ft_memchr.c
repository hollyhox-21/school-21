/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:00:27 by rjoella           #+#    #+#             */
/*   Updated: 2020/11/07 19:20:25 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *src, int c, size_t n)
{
	int	k;

	k = 0;
	if ((unsigned char)c >= 0)
	{
		while (n > 0)
		{
			if (*((unsigned char *)src + k) == (unsigned char)c)
				return ((unsigned char *)src + k);
			n--;
			k++;
		}
		if (n == 0)
			return (NULL);
	}
	return ((unsigned char *)src + k);
}
