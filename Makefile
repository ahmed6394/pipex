CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
LIBFT_NAME = libft/libft.a

SRC = src/pipex.c src/utiles.c
OBJ = $(SRC:.c=.o)

LIBFT_SRC = libft/ft_bzero.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c \
      libft/ft_memset.c libft/ft_strchr.c libft/ft_strlcpy.c libft/ft_strlcat.c libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_tolower.c libft/ft_toupper.c \
      libft/ft_calloc.c libft/ft_strdup.c libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c \
      libft/ft_itoa.c libft/ft_split.c libft/ft_strmapi.c libft/ft_striteri.c libft/ft_atoi.c libft/ft_strcmp.c # List all libft source files
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

all: $(LIBFT_NAME) $(NAME)

$(NAME): $(OBJ) $(LIBFT_NAME)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_NAME) -o $(NAME)

$(LIBFT_NAME): $(LIBFT_OBJ)
	ar rcs $(LIBFT_NAME) $(LIBFT_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(LIBFT_OBJ)

fclean: clean
	rm -f $(NAME) $(LIBFT_NAME)

re: fclean all

