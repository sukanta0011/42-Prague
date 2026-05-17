FLAGS = -Wall -Wextra -Werror -pthread
OUTPUT = codexion
LEAK_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
ARGS = 3 859 200 200 200 5 50 "edf"

SRCS = main.c initialize_coders.c cleaner.c\
		coder_routines.c heap_operations.c\
		heap_positions.c monitor.c parser.c\
		schedular.c utils.c initialize_dongles.c\
		schedular_operations.c


all:
	cc $(FLAGS) $(SRCS) -o $(OUTPUT)
	./$(OUTPUT) $(ARGS)

fclean:
	rm -rf $(OUTPUT)

leak:
	valgrind $(LEAK_FLAGS) ./$(OUTPUT) $(ARGS)