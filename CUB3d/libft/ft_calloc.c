/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:45:28 by rjoella           #+#    #+#             */
/*   Updated: 2020/11/07 18:07:06 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	int		i;

	i = count * size;
	if ((mem = malloc(count * size)) == NULL)
		return (NULL);
	ft_bzero(mem, i);
	return (mem);
}
