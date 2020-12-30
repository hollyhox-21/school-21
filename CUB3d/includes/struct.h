/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 20:11:55 by rjoella           #+#    #+#             */
/*   Updated: 2020/12/27 17:46:17 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct				s_resolution
{
	int						width;
	int						hight;
}							t_resolution;

typedef struct				s_textures
{
	char					*no;
	char					*so;
	char					*we;
	char					*ea;
	char					*s;
}							t_textures;

typedef struct				s_color_f_s
{
	int						floor;
	int						ceiling;
}							t_color_f_s;

typedef struct				s_setting_map
{
	struct s_resolution		res_reso;
	struct s_textures		res_tex;
	struct s_color_f_s		res_col;
	char					**map;
}							t_setting_map;

typedef struct				s_win
{
	void					*mlx;
	void					*win;
	void					*img;
	void					*addr;
	int						line_l;
	int						bpp;
	int						en;
	char					*path;
	int						w;
	int						h;
}							t_win;

typedef struct				s_img_texture
{
	struct s_win			img_so;
	struct s_win			img_no;
	struct s_win			img_we;
	struct s_win			img_ea;
	struct s_win			img_s;
}							t_img_texture;

typedef struct				s_point
{
	int						x;
	int						y;
	int						simb;
}							t_point;

typedef struct				s_sprite_mas
{
	float					spr_x;
	float					spr_y;
	float					dist;
	int						num;
}							t_sprite_mas;

typedef struct				s_plr
{
	float					pos_x;
	float					pos_y;
	float					dir_x;
	float					dir_y;
	float					plane_x;
	float					plane_y;
	float					camera_x;
	float					ray_dir_x;
	float					ray_dir_y;
	int						map_x;
	int						map_y;
	float					side_dist_x;
	float					side_dist_y;
	float					delta_dist_x;
	float					delta_dist_y;
	float					perp_wall_dist;
	int						step_x;
	int						step_y;
	int						hit;
	int						side;
	int						line_height;
	int						draw_start;
	int						draw_end;
	float					wall_x;
	int						tex_x;
	int						tex_y;
	float					step;
	float					tex_pos;
}							t_plr;

typedef struct				s_sprite
{
	float					sprite_x;
	float					sprite_y;
	float					inv_det;
	float					transform_x;
	float					transform_y;
	int						sprite_screen_x;
	int						sprite_hight;
	int						sprite_width;
	int						draw_start_y;
	int						draw_start_x;
	int						draw_end_y;
	int						draw_end_x;
	int						stripe;
	int						tex_x;
	int						tex_y;
	int						y;
	int						d;
}							t_sprite;

typedef struct				s_keys
{
	int						w;
	int						s;
	int						a;
	int						d;
	int						up;
	int						down;
}							t_keys;

typedef struct				s_all
{
	struct s_win			win;
	struct s_plr			plr;
	struct s_sprite			sprt;
	struct s_point			point;
	struct s_setting_map	*setting;
	struct s_img_texture	text;
	struct s_keys			keys;
}							t_all;
#endif
