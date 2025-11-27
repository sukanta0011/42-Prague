FLAGS = -Wall -Wextra -Werror
CC = cc

SRCS = ft_printf.c write_nbr.c write_unbr.c validator.c\
		num_paddings.c write_str.c write_adds.c\
		utils1.c utils2.c parse_specifier.c parse_values.c

OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
# NAME = a.out

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# $(NAME): $(OBJS)
# 	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

bonus: all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

output: all
	$(addprefix ./, $(NAME))

leak: all
	valgrind --leak-check=full $(addprefix ./, $(NAME))

norm:
	norminette -R CheckDefine

t: all
	$(CC) -o test tester.c -L. -lftprintf
	./test

.PHONY: all clean fclean out norm leak bonus t