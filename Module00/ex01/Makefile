NAME = phonebook
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98 -fsanitize=address
RM = rm -f

SRCS = main.cpp Contact.cpp PhoneBook.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT: