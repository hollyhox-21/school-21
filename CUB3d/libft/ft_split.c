/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 10:11:57 by rjoella           #+#    #+#             */
/*   Updated: 2020/11/04 14:40:22 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_strlen_word(char const *str, int start, char c)
{
	int	i;

	i = 0;
	while (str[start] != '\0' && str[start] != c)
	{
		i++;
		start++;
	}
	return (i);
}

int		ft_count_string(char const *str, char c)
{
	int i;
	int word;
	int count;

	i = 0;
	count = 0;
	while (str[i] == c && str[i] != '\0')
		i++;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && word == 0)
		{
			word = 1;
			count++;
		}
		if (str[i] == c)
			word = 0;
		i++;
	}
	return (count);
}

void	*ft_free(char **split_str)
{
	int i;

	i = 0;
	while (split_str[i])
	{
		free(split_str[i]);
		i++;
	}
	free(split_str);
	return (NULL);
}

char	**ft_allocation_split(char const *s, char c, int i, int k)
{
	int		count_char;
	int		count_string;
	char	**split_str;

	count_string = ft_count_string(s, c);
	if (!(split_str = (char **)malloc((count_string + 1) * sizeof(char *))))
		return (NULL);
	*(split_str + count_string) = NULL;
	while (count_string > 0)
	{
		while (s[i] == c)
			i++;
		count_char = ft_strlen_word(s, i, c);
		if (!(split_str[k] = (char *)malloc(count_char * sizeof(char) + 1)))
			return (ft_free(split_str));
		i = i + count_char;
		count_string--;
		k++;
	}
	return (split_str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		p;
	int		count_string;
	int		count_char;
	char	**split_str;

	if (s == NULL)
		return (NULL);
	if ((split_str = ft_allocation_split(s, c, 0, 0)) == NULL)
		return (NULL);
	i = 0;
	p = 0;
	count_string = ft_count_string(s, c);
	while (split_str[p])
	{
		while (s[i] == c)
			i++;
		count_char = ft_strlen_word(s, i, c);
		ft_strlcpy(split_str[p], s + i, count_char + 1);
		i = i + count_char;
		p++;
	}
	return (split_str);
}
