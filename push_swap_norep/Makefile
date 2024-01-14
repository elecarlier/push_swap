NAME = push_swap
LIBFT = $(LIBFTDIR)/libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFTDIR = ./libft

SRCS = 	main.c biggy_sort.c check_error.c push.c reverse_rotate.c rotate.c swap.c target.c tiny_sort.c stack_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -g $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) -g $(CFLAGS) -I$(LIBFTDIR) -I . -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re test
