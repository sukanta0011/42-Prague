FLAGS = -Wall -Wextra -Werror
CC = cc
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS = ft_printf.c write_nbr.c write_unbr.c validator.c\
		num_paddings.c write_str.c write_adds.c\
		utils1.c utils2.c parse_specifier.c parse_values.c

OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH) all

bonus: all

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all bonus clean fclean re