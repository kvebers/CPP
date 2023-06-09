NAME = bordom_signal_that_something_you_do_dose_not_give_you_satisfaction
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC =	main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp
			
SRC_O = $(SRC:%.cpp=%.o)
RM = rm -f

all: $(NAME)

$(NAME): $(SRC_O)
		c++ $(CFLAGS) $(SRC_O) -o $(NAME)

clean:
		$(RM) $(SRC_O)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re