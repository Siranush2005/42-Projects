NAME        = push_swap
BONUS_NAME  = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

LIBFT_DIR   = Libft
LIBFT       = Libft/libft.a

GNL_SRC     = get_next_line/get_next_line.c \
              get_next_line/get_next_line_utils.c


SRC         = main.c \
              main_utils.c \
              adaptive_sort.c \
              disorder.c \
              min_max_index_pos.c \
              indexing.c \
              is_sorted.c \
              isValidInput.c \
              ops_counter.c \
              push_to_stacks.c \
              rev_rotate_stacks.c \
              rotate_stacks.c \
              simple_sort.c \
              medium_sort.c \
              complex_sort.c \
              sorting_up_to_5.c \
              stack_utils.c \
              swap_top_stacks.c \
              benchmark_print.c \
              $(GNL_SRC)

OBJ         = $(SRC:.c=.o)


BONUS_SRC   = checker_bonus.c \
              main_utils.c \
              push_to_stacks.c \
              rev_rotate_stacks.c \
              rotate_stacks.c \
              stack_utils.c \
              swap_top_stacks.c \
              isValidInput.c \
              indexing.c \
              min_max_index_pos.c \
              is_sorted.c \
              $(GNL_SRC)

BONUS_OBJ   = $(BONUS_SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

bonus: $(LIBFT) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -L$(LIBFT_DIR) -lft -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re