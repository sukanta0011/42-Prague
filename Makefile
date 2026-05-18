FLAGS = -Wall -Wextra -Werror -pthread
LEAK_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
ARGS = 3 1000 200 200 200 5 50 "edf"

SRCS = main.c initialize_coders.c cleaner.c\
		coder_routines.c heap_operations.c\
		heap_positions.c monitor.c parser.c\
		schedular.c utils.c initialize_dongles.c\
		schedular_operations.c

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

out: all
	./$(NAME) $(ARGS)

leak:
	valgrind $(LEAK_FLAGS) ./$(OUTPUT) $(ARGS)

.PHONY: all clean fclean re leak
