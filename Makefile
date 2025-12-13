SRC_DIR = srcs
HDR_DIR = includes
FLAGS = -Wall -Wextra -Werror
CC = cc

MY_SRCS = chunk_sort.c free_memory.c lst_operations.c \
		main.c operations.c parse_args.c quick_sort.c \
		radix_sort.c search_idx.c sort_small_stack.c \
		utils1.c

SRCS = $(addprefix $(SRC_DIR)/, $(MY_SRCS))
OBJS = $(SRCS:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
# 	ar rcs $(NAME) $(OBJS)
	$(CC) $(FLAGS) -I$(HDR_DIR) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I$(HDR_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# output: all
# 	$(addprefix ./, $(NAME))

# leak: all
# 	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes $(addprefix ./, $(NAME))

# norm:
# 	norminette -R CheckDefine

.PHONY: all clean fclean