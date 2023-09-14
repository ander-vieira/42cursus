NAME = libftprintf.a

CFLAGS = -c -Wall -Wextra -Werror

SRCS = ft_printf.c
OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	gcc $(CFLAGS) $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all