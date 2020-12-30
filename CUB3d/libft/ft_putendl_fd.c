/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:51:58 by rjoella           #+#    #+#             */
/*   Updated: 2020/10/30 18:18:12 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
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
		write(fd, "\n", 1);
	}
}
