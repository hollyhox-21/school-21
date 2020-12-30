/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:57:39 by rjoella           #+#    #+#             */
/*   Updated: 2020/12/25 00:17:53 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_pack_map(t_setting_map *sett_struct, t_list **head_map)
{
	if (!(sett_struct->map = ft_make_map(head_map, ft_lstsize(*head_map))))
		return (-1);
	if ((g_error = ft_validator3000(sett_struct->map)) < 0)
		return (g_error);
	return (1);
}

int	ft_pack_setting(t_setting_map *sett_str, t_list **head_set, char **str_chr)
{
	t_list	*tmp;
	int		i;

	tmp = *head_set;
	while (tmp)
	{
		i = -1;
		while (++i < ft_count_token(str_chr))
		{
			if (!ft_strncmp(tmp->content, str_chr[i], ft_strlen(str_chr[i])))
			{
				ft_check_type(tmp->content, str_chr[i], sett_str);
				break ;
			}
		}
		tmp = tmp->next;
	}
	return (ft_valid_setting(sett_str));
}

int	ft_parser_map(int fd_cub, t_list **head_map)
{
	char	*buf;
	int		res_gnl;
	int		flag;

	flag = 1;
	buf = NULL;
	while ((res_gnl = get_next_line(fd_cub, &buf)) > 0)
	{
		if (!*buf)
			free(buf);
		if (flag && !ft_strncmp(buf, "", ft_strlen(buf)))
			continue ;
		flag = 0;
		ft_lstadd_back(head_map, ft_lstnew(buf));
	}
	ft_lstadd_back(head_map, ft_lstnew(buf));
	if (res_gnl == -1)
		return (-2);
	return (1);
}

int	ft_parser_setting(int fd_cub, t_list **head_setting, char **str_chr)
{
	char	*buf;
	int		flg[3];

	flg[0] = 8;
	buf = NULL;
	while (flg[0] && (flg[2] = get_next_line(fd_cub, &buf)) > 0)
	{
		if ((g_error = ft_check_str(&buf)) < 0)
			return (g_error);
		flg[1] = -1;
		while (++flg[1] < ft_count_token(str_chr))
		{
			if (!ft_strncmp(buf, str_chr[flg[1]], ft_strlen(str_chr[flg[1]])))
			{
				ft_lstadd_back(head_setting, ft_lstnew(buf));
				flg[0]--;
				break ;
			}
		}
	}
	if (flg[2] < 0)
		return (-2);
	return (1);
}

int	ft_parser(int fd_cub, t_all *all)
{
	t_list	*head_setting;
	t_list	*head_map;
	char	**str_chr;

	head_setting = NULL;
	head_map = NULL;
	if ((g_error = ft_null_struct(&all->setting)) < 0)
		return (g_error);
	if ((g_error = ft_arr_type(&str_chr)) < 0)
		return (g_error);
	if ((g_error = ft_parser_setting(fd_cub, &head_setting, str_chr)) < 0)
		return (g_error);
	if ((g_error = ft_parser_map(fd_cub, &head_map)) < 0)
		return (g_error);
	if ((g_error = ft_pack_setting(all->setting, &head_setting, str_chr)) < 0)
		return (g_error);
	if ((g_error = ft_pack_map(all->setting, &head_map)) < 0)
		return (g_error);
	ft_free_lst(&head_setting, 1);
	ft_free_lst(&head_map, 2);
	ft_free(str_chr);
	return (1);
}
