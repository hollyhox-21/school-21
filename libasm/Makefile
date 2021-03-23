# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 15:23:45 by rjoella           #+#    #+#              #
#    Updated: 2021/03/22 19:44:17 by rjoella          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
FUNCTIONS = ft_strlen \
			ft_strcpy \
			ft_strcmp \
			ft_write \
			ft_read \
			ft_strdup

OBJ = $(patsubst %,%.o,$(FUNCTIONS))
SRC = $(patsubst %,%.s,$(FUNCTIONS))
CFLAGS = -Wall -Wextra -Werror
CC = gcc $(CFLAGS)
ACC = nasm -f macho64
TEST = test

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	
$(OBJ): %.o:%.s ./libasm.h
	$(ACC) $< -o $@

clean:
	@rm -f $(patsubst %,%.o,$(FUNCTIONS))

fclean: clean
	@rm -f $(NAME) $(TEST)

test: $(NAME)
	$(CC) main.c -L. -lasm -o $(TEST)

re: fclean all