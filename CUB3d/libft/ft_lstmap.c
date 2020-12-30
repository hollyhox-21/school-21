/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:05:10 by rjoella           #+#    #+#             */
/*   Updated: 2020/10/30 20:49:10 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *res;
	t_list *buf;

	res = NULL;
	if (lst == NULL)
		return (NULL);
	if ((res = ft_lstnew(f(lst->content))) == NULL)
		return (NULL);
	while (lst)
	{
		if (lst->next)
		{
			if ((buf = ft_lstnew(f(lst->next->content))) == NULL)
			{
				ft_lstclear(&res, del);
				return (NULL);
			}
			ft_lstadd_back(&res, buf);
		}
		lst = lst->next;
	}
	return (res);
}
