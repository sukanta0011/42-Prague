SRC_DIR = srcs
CHECKER_DIR = checker_srcs
HDR_DIR = includes
FLAGS = -Wall -Wextra -Werror
CC = cc

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

MY_SRCS = chunk_sort.c free_memory.c lst_operations.c \
		main.c operations.c parse_args.c quick_sort.c \
		radix_sort.c search_idx.c sort_small_stack.c \
		utils1.c

CHECKER_SRCS = free_memory.c lst_operations.c \
		checker_main.c operations.c parse_args.c utils1.c

SRCS = $(addprefix $(SRC_DIR)/, $(MY_SRCS))
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = $(addprefix $(CHECKER_DIR)/, $(CHECKER_SRCS))
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

NAME = push_swap
BONUS_NAME = checker

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) -I$(HDR_DIR) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I$(HDR_DIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH) all

bonus: $(NAME) $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(FLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean