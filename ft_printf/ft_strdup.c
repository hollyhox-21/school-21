/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:21:02 by rjoella           #+#    #+#             */
/*   Updated: 2020/11/24 16:16:56 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *str)
{
	int		count;
	char	*buf;

	count = 0;
	while (*(str + count) != '\0')
		count++;
	if ((buf = malloc(count + 1)) == NULL)
		return (NULL);
	count = 0;
	while (*(str + count) != '\0')
	{
		*(buf + count) = *(str + count);
		count++;
	}
	*(buf + count) = '\0';
	return (buf);
}
