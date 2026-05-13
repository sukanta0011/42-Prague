all:
	cc -Wall -Wextra -Werror main.c initializer.c cleaner.c

leak: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out