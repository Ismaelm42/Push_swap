# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 16:00:43 by imoro-sa          #+#    #+#              #
#    Updated: 2023/04/28 16:00:46 by imoro-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap

BONUS = checker

SRC =	main.c					\
		push_swap_init.c		\
		push_swap_check.c		\
		push_swap_movs.c		\
		push_swap_movs_ab.c		\
		push_swap_target.c		\
		push_swap_cost.c		\
		push_swap_make_moves.c	\
		push_swap.c				\
		push_swap_utils.c		\

SRCBONUS =	checker.c				\
			push_swap_init.c		\
			push_swap_check.c		\
			push_swap_movs.c		\
			push_swap_movs_ab.c		\
			push_swap_target.c		\
			push_swap_cost.c		\
			push_swap_make_moves.c	\
			push_swap.c				\
			push_swap_utils.c		\
			checker_movs.c			\
			checker_movs_ab.c		\

OBJT = $(SRC:.c=.o)

OBJTBONUS = $(SRCBONUS:.c=.o)

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

$(BONUS): $(LIBFT) $(OBJTBONUS)
	${CC} $(CFLAGS) $(SRCBONUS) $(LIBFT) -o ${BONUS}

bonus: $(BONUS)

clean:
	$(RM) $(OBJT)
	$(RM) $(OBJTBONUS)
	make -C ./libft clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS)
	make -C ./libft fclean

re: fclean all

.PHONY : all clean fclean re
