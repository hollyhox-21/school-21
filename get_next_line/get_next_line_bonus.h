/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:26:26 by rjoella           #+#    #+#             */
/*   Updated: 2020/11/14 11:43:32 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

# if BUFFER_SIZE > 8000000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE	32
# endif

typedef struct			s_number_fd
{
	int					fd;
	char				*tail;
	struct s_number_fd	*next;
}						t_number_fd;
int						get_next_line(int fd, char **line);
int						ft_strlen(const char *s, char **tail, int flag);
char					*ft_strchr(const char *s, int c);
char					*ft_strdup(const char *str);
char					*ft_strjoin(char const *tail, char const *s2);
t_number_fd				*ft_lstnew(int fd);

#endif
