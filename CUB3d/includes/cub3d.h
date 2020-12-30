/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:58:35 by rjoella           #+#    #+#             */
/*   Updated: 2020/12/29 10:24:12 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "struct.h"
# include "../minilibx_opengl_20191021/mlx.h"
# include "../libft/libft.h"
# define BUFFER_SIZE 10
# define MS 0.1
# define RS 0.05

int		g_error;

int		get_next_line(int fd, char **line);
int		ft_count_string(char const *str, char c);
void	*ft_free(char **split_str);
/*
**		ft_parser
*/
int		ft_pack_map(t_setting_map *sett_struct, t_list **head_map);
int		ft_pack_setting(t_setting_map *sett_struct,
		t_list **head_setting, char **str_chr);
int		ft_parser_map(int fd_cub, t_list **head_map);
int		ft_parser_setting(int fd_cub, t_list **head_setting, char **str_chr);
int		ft_parser(int fd_cub, t_all *all);
/*
**		ft_pars_setting
*/
int		ft_pars_color(char *p_val, int i);
void	ft_read_color_f_s(t_setting_map *res, char *buf, char *type);
void	ft_read_textures(t_setting_map *res, char *buf, char *type);
void	ft_read_resolution(t_setting_map *res, char *buf, int i, int j);
void	ft_check_type(char *buf, char *type, t_setting_map *res);
/*
**		utils_pars_one
*/
void	my_mlx_pixel_put(t_all *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
int		ft_count_token(char **str_chr);
int		ft_arr_type(char ***str_chr);
void	ft_free_lst(t_list **lst, int flag);
/*
**		utils_pars_two
*/
int		ft_check_str(char **buf);
int		ft_check_env(int x, int y, char **map, int i);
int		ft_null_struct(t_setting_map **res);
int		ft_check_rgb(char **str_rgb, int *str_nb);
/*
**		valid_config_file
*/
int		ft_validator3000(char **map);
char	**ft_make_map(t_list **head_map, int size);
int		ft_valid_setting(t_setting_map *sett_struct);
int		ft_close();
/*
**		valid_setting_utils
*/
int		ft_add_spaces(char ***map);
int		ft_check_spaces(int x, int y, char **map);
int		ft_check_outline(int x, int y, char **map);
int		ft_chr_start(int *x, int *y, char **map, int *simb);
int		ft_check_valid_simbol(char **map, int x, int y);
/*
**		RENDER_part_one
*/
void	ft_draw_celling(t_all *all, int x, int *y);
void	ft_draw_world(t_all *all, int x, int *y, int color);
void	ft_draw_floor(t_all *all, int x, int *y);
void	ft_fov(t_all *all, int x);
void	render(t_all *all);
/*
**		RENDER_part_two
*/
void	ft_distance_for_side(t_all *all);
void	ft_found_side(t_all *all);
void	ft_draw_s_draw_e(t_all *all);
void	ft_tex_x(t_all *all);
void	ft_tex_y(t_all *all);
/*
**		get_colors
*/
int		get_color_sprite(t_all *all, int x, int y);
int		get_color_north(t_all *all, int x, int y);
int		get_color_south(t_all *all, int x, int y);
int		get_color_west(t_all *all, int x, int y);
int		get_color_east(t_all *all, int x, int y);
/*
**		KEYS
*/
void	ft_up_down(t_all *all, int keycode);
void	ft_l_r(t_all *all, int keycode, float *old_dir_x, float *old_plane_x);
int		ft_release(int keycode, t_all *all);
void	ft_left_right(t_all *all, int keycode);
int		ft_move(int keycode, t_all *all);
/*
**		INIT_imgs_xpm
*/
int		ft_init_images(t_all *all);
int		ft_init_images_two(t_all *all);
/*
**		DRAW_SPRITES
*/
void	ft_sprt_screen(t_all *all, t_sprite_mas sprite[],
		int sprite_order[], int i);
void	ft_sprite_w_h(t_all *all);
void	ft_draw_sprite(t_all *all, float z_buffer[], int *clr);
void	sprits(t_all *all, float z_buffer[]);
/*
**		SPRITE_UTILS
*/
void	ft_swap_sprite(t_sprite_mas *a, t_sprite_mas *b);
void	ft_sort_sprite(t_sprite_mas arr[], int count);
int		ft_count_sprite(char **map);
void	cast_sprite_mass(t_sprite_mas *sprite, char **map);
/*
**		INIT_head_win
*/
int		ft_check_param(char *param_one, char *param_two);
void	ft_init_start_vars(t_all *all);
void	ft_turn_plr(t_all *all, char p);
int		init_head_win(t_all *all, int color);
/*
**		ft_screen
*/
int		make_head(unsigned char *bmp_head,
		unsigned char *bmp_fhead, t_all *all);
int		make_file_scr(unsigned char *bmp_head,
		unsigned char *bmp_fhead, t_all *all);
int		ft_creat_screen(t_all *all);
/*
**		ft_errors
*/
void	ft_errors(int err);
/*
**		mouse
*/
int		ft_mouse(int x, int y, t_all *all);
#endif
