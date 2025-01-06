NAME    = libftprintf.a
HNAME   = ft_printf.h
FLAGS   = -Wall -Wextra -Werror

SRC     =	ft_aux.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_percent.c \
			ft_putdecimal.c \
			ft_putunsign.c \
			ft_puthexamin.c \
			ft_puthexamai.c \
			ft_putptr.c \
			ft_printf.c \

OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all