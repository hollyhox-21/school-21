/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:52:36 by rjoella           #+#    #+#             */
/*   Updated: 2020/11/02 18:38:39 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int res;
	int i;

	res = 0;
	i = 0;
	while (n != 0)
	{
		res = *((unsigned char *)s1 + i) - *((unsigned char *)s2 + i);
		if (res != 0)
			return (res);
		i++;
		n--;
	}
	return (res);
}
