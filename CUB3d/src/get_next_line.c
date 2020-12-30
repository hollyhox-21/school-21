/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:15:55 by rjoella           #+#    #+#             */
/*   Updated: 2020/12/25 00:18:00 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_cook_tail(char **tail)
{
	if (!*tail)
	{
		if (!(*tail = ft_strdup("")))
			return (-1);
	}
	return (0);
}

int		ft_check_tail(char **tail, char **line)
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

int		get_next_line(int fd, char **line)
{
	static char *tail = NULL;
	char		buf[BUFFER_SIZE + 1];
	int			res_read;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (ft_cook_tail(&tail) == -1)
		return (-1);
	while ((res_read = read(fd, buf, BUFFER_SIZE)) > 0 && res_read != -1)
	{
		buf[res_read] = '\0';
		tmp = tail;
		if (!(tail = ft_strjoin(tail, buf)))
			return (-1);
		free(tmp);
		if (ft_strchr(tail, '\n'))
			return (ft_check_tail(&tail, line));
	}
	if (res_read == -1)
		return (-1);
	return (ft_check_tail(&tail, line));
}
