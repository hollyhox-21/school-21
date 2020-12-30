/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:09:28 by rjoella           #+#    #+#             */
/*   Updated: 2020/10/30 20:19:50 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int k;

	k = 0;
	if (n == 0 || (dest == NULL && src == NULL))
		return (dest);
	while (n > 0)
	{
		*((char *)(dest + k)) = *((char *)(src + k));
		k++;
		n--;
	}
	return (dest);
}
