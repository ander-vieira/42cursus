NAME = harlFilter

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Harl.cpp
HDRS = Harl.hpp

all: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	c++ $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re