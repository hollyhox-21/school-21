/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:46:09 by rjoella           #+#    #+#             */
/*   Updated: 2020/10/30 18:19:24 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int count;

	count = 0;
	while (*(s + count) != '\0')
		count++;
	while (*(s + count) != c)
	{
		if (count == 0)
		{
			return (NULL);
		}
		count--;
	}
	s = (s + count);
	return ((char *)s);
}
