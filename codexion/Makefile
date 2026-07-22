FLAGS = -Wall -Wextra -Werror -pthread
LEAK_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
# LEAK_FLAGS = --tool=helgrind --history-level=approx --max-threads=1000

ARGS = 5 1000 200 200 200 5 50 "fifo"

SRCS = main.c initialize_coders.c cleaner.c\
		coder_routines.c heap_operations.c\
		heap_positions.c monitor.c parser.c\
		schedular.c utils1.c initialize_dongles.c\
		schedular_operations.c utils2.c

OBJS = $(SRCS:.c=.o)

NAME = codexion

all: $(NAME)

$(NAME): $(OBJS)
	cc $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME) $(ARGS)

leak: all
	valgrind $(LEAK_FLAGS) ./$(NAME) $(ARGS)

.PHONY: all clean fclean re leak
