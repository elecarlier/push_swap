NAME = pushswap
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFTDIR = ./libft

SRCS = 	main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTDIR)/$(LIBFTNAME)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)
	@ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFTDIR) -c -o $@ $<

clean:
	@rm -f $(OBJS)
	@cd $(LIBFTDIR) && make clean

testclean:
	@rm -f test

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean

re: fclean all

test: $(NAME)
	@$(CC) main.c -L. -lpushswap -o test
	@./test
	@rm -r ./test

.PHONY: all clean fclean re test
