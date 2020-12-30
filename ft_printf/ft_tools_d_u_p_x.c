/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_d_u_p_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:14:53 by rjoella           #+#    #+#             */
/*   Updated: 2020/11/25 13:20:34 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_work_with_nb(long int *nb, t_spec *obj, char const *pref, int base)
{
	char	*ch_nb;

	if (*nb < 0)
	{
		*nb = *nb * -1;
		if (!(obj->signed_nb = ft_strdup(pref)))
			return (NULL);
	}
	else if (obj->type == 'p')
	{
		if (!(obj->signed_nb = ft_strdup(pref)))
			return (NULL);
	}
	else
		obj->signed_nb = NULL;
	if (!(ch_nb = ft_itoa_base(*nb, base)))
		return (NULL);
	if (!ft_strncmp(ch_nb, "0", ft_strlen(ch_nb)) && obj->precision != -1)
	{
		if (!(ch_nb = ft_strdup("")))
			return (NULL);
	}
	return (ch_nb);
}

char	*ft_join_simbol_one(char **res, t_spec *obj, int flag)
{
	char	*tmp;

	if (flag == 1)
	{
		tmp = *res;
		if (!(*res = ft_strjoin(*res, obj->signed_nb)))
			return (NULL);
		free(tmp);
	}
	if (flag == 2)
	{
		tmp = *res;
		if (!(*res = ft_strjoin(*res, " ")))
			return (NULL);
		free(tmp);
	}
	return (NULL);
}

char	*ft_join_simbol_two(char **res, int flag)
{
	char	*tmp;

	if (flag == 3)
	{
		tmp = *res;
		if (!(*res = ft_strjoin(*res, "0")))
			return (NULL);
		free(tmp);
	}
	if (flag == 4)
	{
		tmp = *res;
		if (!(*res = ft_strjoin(" ", *res)))
			return (NULL);
		free(tmp);
	}
	return (NULL);
}

char	*ft_check_precision(char **res, char **ch_nb, t_spec *obj)
{
	char *tmp;

	if (obj->signed_nb)
		ft_join_simbol_one(res, obj, 1);
	while ((obj->precision--) - ft_strlen(*ch_nb) > 0)
		ft_join_simbol_two(res, 3);
	tmp = *res;
	if (!(*res = ft_strjoin(*res, *ch_nb)))
		return (NULL);
	free(tmp);
	if (obj->flags == '-')
	{
		while (obj->width - ft_strlen(*res) > 0)
		{
			ft_join_simbol_one(res, obj, 2);
			obj->precision--;
		}
	}
	while (obj->width - ft_strlen(*res) > 0)
	{
		ft_join_simbol_two(res, 4);
		obj->precision--;
	}
	return (NULL);
}

char	*ft_check_flags(char **res, char **ch_nb, t_spec *obj)
{
	char *tmp;

	if (obj->signed_nb)
	{
		ft_join_simbol_one(res, obj, 1);
		obj->width = obj->width - ft_strlen(obj->signed_nb);
	}
	if (obj->flags == '0')
	{
		while ((obj->width--) - ft_strlen(*ch_nb) > 0)
			ft_join_simbol_two(res, 3);
	}
	while ((obj->width--) - ft_strlen(*ch_nb) > 0)
		ft_join_simbol_two(res, 4);
	tmp = *res;
	if (!(*res = ft_strjoin(*res, *ch_nb)))
		return (NULL);
	free(tmp);
	return (NULL);
}
