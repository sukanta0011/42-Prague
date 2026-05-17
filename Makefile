FLAGS = -Wall -Wextra -Werror -pthread
OUTPUT = codexion
LEAK_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes

SRCS = main.c initializer.c cleaner.c\
		coder_routines.c heap_operations.c\
		heap_positions.c monitor.c parser.c\
		schedular.c utils.c


all:
	cc $(FLAGS) $(SRCS) -o $(OUTPUT)
	./$(OUTPUT)

fclean:
	rm -rf $(OUTPUT)

leak:
	valgrind $(LEAK_FLAGS) ./$(OUTPUT)