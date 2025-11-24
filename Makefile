SRC_DIR = srcs
HDR_DIR = includes
FLAGS = -Wall -Wextra -Werror -g -O0 -D BUFFER_SIZE=10
CC = gcc

SRCS = get_next_line.c get_next_line_utils.c main.c
# SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c main.c
OBJS = $(SRCS:.c=.o)
NAME = a.out

all: $(NAME)

$(NAME): $(OBJS)
# 	ar rcs $(NAME) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

output: all
	$(addprefix ./, $(NAME))

leak: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes $(addprefix ./, $(NAME))

norm:
	norminette -R CheckDefine

.PHONY: all clean fclean out norm leak