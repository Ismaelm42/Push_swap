

NAME = push_swap

SRC =	main.c					\
		push_swap_init.c		\
		push_swap_check.c		\
		push_swap_movs.c		\
		push_swap_movs_ab.c		\
		push_swap_target.c		\
		push_swap_cost.c		\
		push_swap_make_moves.c	\
		push_swap_algorithm.c	\
		push_swap_utils.c		\

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
	make -C ./libft clean

.PHONY : all clean fclean re
