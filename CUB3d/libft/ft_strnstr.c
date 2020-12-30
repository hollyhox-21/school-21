/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:25:53 by rjoella           #+#    #+#             */
/*   Updated: 2020/11/04 14:42:50 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	wall;

	wall = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	if (ft_strlen(haystack) >= ft_strlen(needle))
	{
		while (*haystack && n >= wall)
		{
			if (!ft_strncmp(haystack, needle, wall) && *haystack == *needle)
				return ((char *)haystack);
			haystack++;
			n--;
		}
	}
	return (NULL);
}
