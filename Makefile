NAME = push_swap

SRCS = $(wildcard mandatory/*.c)

OBJS = $(SRCS:.c=.o)
LIBFT_OBJS = $(wildcard libft/**/*.o)

CC = cc
CFLAGS = -c -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft bonus
	$(CC) -o $(NAME) $(OBJS) libft/libft.a 

%.o : %.c
	$(CC) $(CFLAGS) $^ -o $@

clean :
	make -C libft clean
	rm -f $(OBJS)

fclean : clean
	make -C libft fclean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re