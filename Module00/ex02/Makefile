NAME = Account
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98 -fsanitize=address -pedantic
RM = rm -f

SRCS = Account.cpp

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