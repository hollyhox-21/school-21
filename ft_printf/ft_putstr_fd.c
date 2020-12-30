/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:47:49 by rjoella           #+#    #+#             */
/*   Updated: 2020/11/24 16:16:51 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int count;

	count = 0;
	if (s)
	{
		while (s[count])
		{
			write(fd, &s[count], 1);
			count++;
		}
	}
	return (count);
}
