/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pars_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 14:08:33 by rjoella           #+#    #+#             */
/*   Updated: 2020/12/25 00:17:56 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_all *data, int x, int y, int color)
{
	char	*dst;

	dst = data->win.addr + (y * data->win.line_l +
	x * (data->win.bpp / 8));
	*(unsigned int*)dst = color;
}

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int		ft_count_token(char **str_chr)
{
	int	count;

	count = 0;
	while (str_chr[count])
	{
		count++;
	}
	return (count);
}

int		ft_arr_type(char ***str_chr)
{
	char	*str;

	str = "R NO SO WE EA S F C";
	if (!(*str_chr = ft_split(str, ' ')))
		return (-1);
	return (1);
}

void	ft_free_lst(t_list **lst, int flag)
{
	t_list	*tmp;

	if (flag == 1)
	{
		while (*lst)
		{
			tmp = *lst;
			free(tmp->content);
			*lst = (*lst)->next;
			free(tmp);
		}
	}
	if (flag == 2)
	{
		while (*lst)
		{
			tmp = *lst;
			*lst = (*lst)->next;
			free(tmp);
		}
	}
}
