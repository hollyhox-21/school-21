/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:47:49 by rjoella           #+#    #+#             */
/*   Updated: 2020/10/30 18:18:24 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int count;

	count = 0;
	if (s != NULL)
	{
		while (*(s + count) != '\0')
		{
			write(fd, (s + count), 1);
			count++;
		}
	}
}
