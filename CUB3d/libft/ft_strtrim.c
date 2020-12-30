/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:27:22 by rjoella           #+#    #+#             */
/*   Updated: 2020/11/14 12:46:59 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len_str;
	char	*res;
	int		start;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (*set == '\0')
		return (res = ft_strdup(s1));
	i = 0;
	start = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
	{
		start++;
		i++;
	}
	if ((*(s1 + start) == '\0'))
		return ((res = ft_strdup("")));
	len_str = ft_strlen(s1);
	while (len_str > 0 && ft_strchr(set, s1[len_str - 1]))
		len_str--;
	return ((res = ft_substr(s1, start, len_str - start)));
}
