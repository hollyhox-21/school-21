/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:08:03 by rjoella           #+#    #+#             */
/*   Updated: 2020/10/30 18:18:02 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	k;

	k = 0;
	while (k < n)
	{
		*((char *)s + k) = c;
		k++;
	}
	return (s);
}
