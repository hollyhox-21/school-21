/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:50:56 by rjoella           #+#    #+#             */
/*   Updated: 2020/10/30 18:17:58 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int i;

	i = 0;
	if (n > 0)
	{
		while (n != 0)
		{
			if (src < dest && (char *)(dest + i) != NULL)
				*((char *)dest + n - 1) = *((char *)src + n - 1);
			if (src > dest && (char *)(dest + i) != NULL)
				*((char *)dest + i) = *((char *)src + i);
			n--;
			i++;
		}
	}
	return (dest);
}
