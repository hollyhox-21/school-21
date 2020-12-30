/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:03:53 by rjoella           #+#    #+#             */
/*   Updated: 2020/10/30 18:16:56 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *buf;

	if (lst == NULL)
		return ;
	while ((*lst) != NULL)
	{
		buf = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		*lst = buf;
	}
}
