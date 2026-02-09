NAME = animal
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		main.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)
	@echo "\033[90mMakefile compiled successfully\033[0m"

clean:

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT: