/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:17:52 by rjoella           #+#    #+#             */
/*   Updated: 2020/11/14 11:18:15 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_number_fd		*ft_lstnew(int fd)
{
	t_number_fd	*new;

	if (!(new = (t_number_fd*)(malloc(sizeof(t_number_fd)))))
		return (NULL);
	new->fd = fd;
	new->tail = NULL;
	new->next = NULL;
	return (new);
}

int				ft_strlen(const char *s, char **tail, int flag)
{
	int		count;

	if (flag == 1)
	{
		count = 0;
		while (*(s + count) != '\0')
			count++;
		return (count);
	}
	if (flag == 2)
	{
		if (!*tail)
		{
			if (!(*tail = ft_strdup("")))
				return (-1);
		}
	}
	return (0);
}

char			*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != c)
	{
		s++;
		if (*s == '\0' && c == '\0')
			return ((char *)s);
		if (*s == '\0')
			return (NULL);
	}
	return ((char *)s);
}

char			*ft_strdup(const char *str)
{
	int		count;
	char	*buf;

	if (!str)
		return (NULL);
	count = 0;
	while (*(str + count) != '\0')
		count++;
	if ((buf = (char *)malloc(count + 1)) == NULL)
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

char			*ft_strjoin(char const *tail, char const *s2)
{
	int		i;
	int		j;
	char	*buf;

	i = 0;
	j = 0;
	if (!tail || !s2)
		return (NULL);
	if (!(buf = (char *)malloc(sizeof(char) *
	(ft_strlen(tail, NULL, 1) + ft_strlen(s2, NULL, 1) + 1))))
		return (NULL);
	while (s2[j] != '\0' || tail[i] != '\0')
	{
		while (tail[i] != '\0')
		{
			buf[i] = tail[i];
			i++;
		}
		buf[i + j] = s2[j];
		j++;
		if (s2[j] == '\0')
			break ;
	}
	buf[i + j] = '\0';
	return (buf);
}
