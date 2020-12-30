NAME = libftprintf.a
FUNCTIONS = ft_atoi \
			ft_bzero \
			ft_itoa_base \
			ft_print_percent \
			ft_print_c \
			ft_print_s \
			ft_print_d_i \
			ft_print_p \
			ft_print_u \
			ft_print_x \
			ft_printf \
			ft_putchar_fd \
			ft_putnbr_fd \
			ft_putstr_fd \
			ft_strchr \
			ft_strdup \
			ft_strjoin \
			ft_strlen \
			ft_strncmp \
			ft_substr \
			ft_toupper \
			ft_tools_d_u_p_x \
			ft_parser

OBJ = $(patsubst %,%.o,$(FUNCTIONS))

SRC = $(patsubst %,%.c,$(FUNCTIONS))

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): %.o:%.c ./ft_printf.h
	gcc -c $(CFLAGS) $< -o $@

clean:
	@rm -f $(patsubst %,%.o,$(FUNCTIONS))

fclean: clean
	@rm -f $(NAME)

re: fclean all