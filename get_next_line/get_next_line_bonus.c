/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:15:55 by rjoella           #+#    #+#             */
/*   Updated: 2020/11/16 17:07:29 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void			ft_lstadd_back(t_number_fd **lst, t_number_fd *new)
{
	t_number_fd *tmp;

	if (new && lst)
	{
		if ((*lst) == NULL)
		{
			*lst = new;
			return ;
		}
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int				ft_check_tail(char **tail, char **line)
{
	char	*p_n;
	char	*tmp;

	if ((p_n = ft_strchr(*tail, '\n')))
	{
		*p_n = '\0';
		p_n++;
		if (!(*line = ft_strdup(*tail)))
			return (-1);
		if (!(tmp = ft_strdup(p_n)))
			return (-1);
		free(*tail);
		*tail = tmp;
		return (1);
	}
	if (!(*line = ft_strdup(*tail)))
		return (-1);
	free(*tail);
	*tail = NULL;
	return (0);
}

t_number_fd		*check_node(t_number_fd **lst, int fd)
{
	t_number_fd	*tmp_lst;
	t_number_fd *node;

	if (!*lst)
		ft_lstadd_back(&*lst, ft_lstnew(fd));
	node = NULL;
	tmp_lst = *lst;
	while (tmp_lst)
	{
		if (tmp_lst->fd == fd)
		{
			node = tmp_lst;
			break ;
		}
		if (!(tmp_lst->next))
		{
			ft_lstadd_back(&*lst, ft_lstnew(fd));
			tmp_lst = tmp_lst->next;
			node = tmp_lst;
			break ;
		}
		tmp_lst = tmp_lst->next;
	}
	return (node);
}

int				get_next_line(int fd, char **line)
{
	static t_number_fd	*fd_tails = NULL;
	char				buf[BUFFER_SIZE + 1];
	int					res_read;
	char				*tmp;
	t_number_fd			*node;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	node = check_node(&fd_tails, fd);
	if (ft_strlen(NULL, &(node->tail), 2) == -1)
		return (-1);
	while ((res_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (res_read == -1)
			return (-1);
		buf[res_read] = '\0';
		tmp = node->tail;
		if (!(node->tail = ft_strjoin(node->tail, buf)))
			return (-1);
		free(tmp);
		if ((tmp = ft_strchr(node->tail, '\n')))
			return (ft_check_tail(&(node->tail), line));
	}
	if (res_read == -1)
		return (-1);
	return (ft_check_tail(&(node->tail), line));
}
