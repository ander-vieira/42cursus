NAME = animal

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Animal.cpp Brain.cpp Dog.cpp Cat.cpp
HDRS = Animal.hpp Brain.hpp Dog.hpp Cat.hpp

all: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	c++ $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re