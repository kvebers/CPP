NAME =	wow_this_excersise_is_actually_good
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC =	main.cpp

SRC_O = $(SRC:%.cpp=%.o)
RM = rm -f

all: $(NAME)

$(NAME): $(SRC_O)
		c++ $(CFLAGS) $(SRC_O) -o $(NAME)

%.o: %.cpp
		c++ $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(SRC_O)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re