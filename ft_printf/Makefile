NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = 	ft_print_char.c\
		ft_print_hex_lowercase.c\
		ft_print_hex_uppercase.c\
		ft_print_int_or_dec.c\
		ft_print_percent.c\
		ft_print_pointer.c\
		ft_print_string.c\
		ft_print_unsigned_dec.c\
		ft_printf.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
