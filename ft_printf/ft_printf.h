/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:25:47 by rjoella           #+#    #+#             */
/*   Updated: 2020/12/29 10:39:37 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct		s_specifications
{
	int				flags;
	int				width;
	int				precision;
	char			type;
	char			*signed_nb;
}					t_spec;

int					ft_printf(const char *str, ...);
int					ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
int					ft_atoi(const char *str);
char				*ft_strdup(const char *str);
char				*ft_substr(char const *s, int start, int len);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_itoa_base(long long int n, int base);
void				ft_putchar_fd(char c, int fd);
int					ft_putstr_fd(char *s, int fd);
int					ft_strncmp(const char *s1, const char *s2, size_t c);
void				ft_toupper(char **c);
int					ft_parser(char **piese_str, va_list *ap);
char				*ft_work_with_nb(long int *nb, t_spec *obj,
					char const *pref, int base);
char				*ft_join_simbol_one(char **res, t_spec *obj, int flag);
char				*ft_join_simbol_two(char **res, int flag);
char				*ft_check_precision(char **res, char **ch_nb, t_spec *obj);
char				*ft_check_flags(char **res, char **ch_nb, t_spec *obj);
int					ft_print_percent(t_spec *obj);
int					ft_print_c(t_spec *obj, va_list *ap);
int					ft_print_s(t_spec *obj, va_list *ap);
int					ft_print_d_i(t_spec *obj, va_list *ap);
int					ft_print_u(t_spec *obj, va_list *ap);
int					ft_print_p(t_spec *obj, va_list *ap);
int					ft_print_x(t_spec *obj, va_list *ap);
#endif
