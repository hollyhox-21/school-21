/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_setting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 14:03:32 by rjoella           #+#    #+#             */
/*   Updated: 2020/12/29 10:19:59 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_pars_color(char *p_val, int i)
{
	char	**str_rgb;
	int		int_rgb[3];

	str_rgb = ft_split(p_val, ',');
	while (i < 3)
	{
		if (str_rgb[i] && i < ft_count_string(p_val, ','))
		{
			if (!ft_check_rgb(&str_rgb[i], &int_rgb[i]))
				return (-6);
			i++;
		}
		else
		{
			int_rgb[i] = -1;
			i++;
		}
	}
	ft_free(str_rgb);
	if (int_rgb[0] < 0 || int_rgb[0] > 255 || int_rgb[1] < 0 ||
		int_rgb[1] > 255 || int_rgb[2] < 0 || int_rgb[2] > 255)
		return (-1);
	return (create_trgb(0, int_rgb[0], int_rgb[1], int_rgb[2]));
}

void	ft_read_color_f_s(t_setting_map *res, char *buf, char *type)
{
	char	*p_val;

	p_val = ft_strchr(buf, ' ');
	if (!ft_strncmp(type, "F", ft_strlen(type)))
	{
		res->res_col.floor = ft_pars_color(p_val, 0);
	}
	if (!ft_strncmp(type, "C", ft_strlen(type)))
	{
		res->res_col.ceiling = ft_pars_color(p_val, 0);
	}
}

void	ft_read_textures(t_setting_map *res, char *buf, char *type)
{
	char	*p_val;

	p_val = buf;
	while (*p_val && ft_strchr("NOSWEA ", *p_val))
		p_val++;
	if (*p_val && !ft_strncmp(type, "NO", ft_strlen(type)))
		res->res_tex.no = ft_strdup(p_val);
	if (*p_val && !ft_strncmp(type, "SO", ft_strlen(type)) &&
		ft_strncmp(type, "S", ft_strlen(type)))
		res->res_tex.so = ft_strdup(p_val);
	if (*p_val && !ft_strncmp(type, "WE", ft_strlen(type)))
		res->res_tex.we = ft_strdup(p_val);
	if (*p_val && !ft_strncmp(type, "EA", ft_strlen(type)))
		res->res_tex.ea = ft_strdup(p_val);
	if (*p_val && !ft_strncmp(type, "S", ft_strlen(type)))
		res->res_tex.s = ft_strdup(p_val);
}

void	ft_read_resolution(t_setting_map *res, char *buf, int i, int j)
{
	char	*p_val;
	char	**num;

	p_val = buf;
	while (*p_val == 'R')
		p_val++;
	num = ft_split(p_val, ' ');
	if (ft_count_token(num) != 2)
		ft_errors(-4);
	while (num[j])
	{
		if (ft_isdigit(num[j][i]))
			i++;
		else
			ft_errors(-4);
		if (!num[j][i])
		{
			i = 0;
			j++;
		}
	}
	res->res_reso.width = ft_atoi(num[0]);
	res->res_reso.hight = ft_atoi(num[1]);
	ft_free(num);
}

void	ft_check_type(char *buf, char *type, t_setting_map *res)
{
	if (!ft_strncmp(buf, "R ", ft_strlen("R ")))
		ft_read_resolution(res, buf, 0, 0);
	if (!ft_strncmp(buf, "NO ", ft_strlen("NO ")) ||
		!ft_strncmp(buf, "SO ", ft_strlen("SO ")) ||
		!ft_strncmp(buf, "WE ", ft_strlen("WE ")) ||
		!ft_strncmp(buf, "EA ", ft_strlen("EA ")) ||
		!ft_strncmp(buf, "S ", ft_strlen("S ")))
		ft_read_textures(res, buf, type);
	if (!ft_strncmp(buf, "F ", ft_strlen("F ")) ||
		!ft_strncmp(buf, "C ", ft_strlen("C ")))
		ft_read_color_f_s(res, buf, type);
}
