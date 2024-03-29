/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:40:49 by rjoella           #+#    #+#             */
/*   Updated: 2020/10/29 12:02:16 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (c);
	}
	if (c >= 65 && c <= 90)
	{
		return (c + 32);
	}
	return (c);
}
