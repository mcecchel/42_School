NAME    = libft.a
HNAME   = libft.h
FLAGS   = -Wall -Wextra -Werror

SRC     = ft_isalnum.c \
          ft_isalpha.c \
          ft_isascii.c \
          ft_isdigit.c \
          ft_isprint.c \
          ft_tolower.c \
          ft_toupper.c \
          ft_strchr.c \
          ft_strlcat.c \
          ft_strlcpy.c \
          ft_strlen.c \
          ft_strncmp.c \
          ft_strnstr.c \
          ft_strrchr.c \
          ft_atoi.c \
          ft_bzero.c \
          ft_memchr.c \
          ft_memcmp.c \
          ft_memcpy.c \
          ft_memmove.c \
          ft_memset.c \
          ft_calloc.c \
          ft_strdup.c \
          ft_substr.c \
          ft_strjoin.c \
          ft_strtrim.c \
          ft_split.c \
          ft_itoa.c \
          ft_strmapi.c \
          ft_striteri.c \
          ft_putchar_fd.c \
          ft_putstr_fd.c \
          ft_putendl_fd.c \
          ft_putnbr_fd.c

SRC_BONUS   = ft_lstnew.c \
                ft_lstadd_front.c \
                ft_lstsize.c \
                ft_lstlast.c \
                ft_lstadd_back.c \
                ft_lstdelone.c \
                ft_lstclear.c \
                ft_lstiter.c \

OBJ     = $(SRC:.c=.o)
OBJ_B   = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ_B)
	ar -rcs $(NAME) $(OBJ) $(OBJ_B)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_B)

fclean: clean
	rm -f $(NAME)

re: fclean all