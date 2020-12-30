# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/27 18:10:01 by rjoella           #+#    #+#              #
#    Updated: 2020/12/30 14:05:40 by rjoella          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
FILE_CUB = draw_sprites \
			main \
			ft_errors \
			ft_get_colors \
			ft_pars_setting \
			ft_parser \
			ft_screen \
			ft_utils_pars_one \
			ft_utils_pars_two \
			init_head_win \
			init_imgs_xpm \
			keys \
			render_part_one \
			render_part_two \
			sprite_utils \
			valid_config_file \
			valid_setting_utils \
			get_next_line

FILE_CUB_BONUS = draw_sprites \
					main \
					ft_errors \
					ft_get_colors \
					ft_pars_setting \
					ft_parser \
					ft_screen \
					ft_utils_pars_one \
					ft_utils_pars_two \
					init_imgs_xpm \
					keys \
					render_part_one \
					render_part_two \
					sprite_utils \
					valid_config_file \
					valid_setting_utils \
					get_next_line \
					init_head_win_bonus \
					mouse_bonus

ifdef MAKE_BONUS
	OBJ_CUB = $(patsubst %,%.o,$(FILE_CUB_BONUS))
else
	OBJ_CUB = $(patsubst %,%.o,$(FILE_CUB))
endif

CFLAGS = -Wall -Wextra -Werror

COMPILE_FLAGS = -framework OpenGL -framework Appkit

LIB_MLX = ./minilibx_opengl_20191021 -lmlx $(COMPILE_FLAGS)
LIB_FT = ./libft -lft

LINK_LIBS = -L$(LIB_MLX) -L$(LIB_FT)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_CUB) ./includes/cub3d.h
	make -C ./minilibx_opengl_20191021
	make -C ./libft
	gcc $(CFLAGS) $(OBJ_CUB) $(LINK_LIBS) -o $(NAME)

$(OBJ_CUB): %.o:./src/%.c
	gcc -c $(CFLAGS) $< -o $@

bonus:
	$(MAKE) MAKE_BONUS=0 all

clean:
	@rm -f ./*.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

norm:
	@norminette ./src ./includes/