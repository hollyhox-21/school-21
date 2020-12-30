/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:35:41 by rjoella           #+#    #+#             */
/*   Updated: 2020/11/24 19:24:50 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*buf;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (!(buf = (char *)malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s2[j] != '\0' || s1[i] != '\0')
	{
		while (s1[i] != '\0')
		{
			buf[i] = s1[i];
			i++;
		}
		if (s2[j] == '\0')
			break ;
		buf[i + j] = s2[j];
		j++;
	}
	buf[i + j] = '\0';
	return (buf);
}
