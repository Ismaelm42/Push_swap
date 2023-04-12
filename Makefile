

NAME = a.out

SRC = push_swap.c

OBJT = $(SRC:.c=.o)

LIBFT = libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

MAKEFLAGS += --quiet

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C ./libft

$(NAME): $(LIBFT) $(OBJT)
	${CC} $(CFLAGS) $(SRC) $(LIBFT) -o ${NAME}

clean:
	$(RM) $(OBJT)
	make -C ./libft clean

fclean: clean
	$(RM) $(NAME)
	make -C ./libft fclean
#cambiar por $(MAKE) fclean, más comprensible
re: fclean all
	make clean

.PHONY : all clean fclean re
