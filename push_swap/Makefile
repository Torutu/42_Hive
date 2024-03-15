NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f

SRC =	error_check.c \
			init_a_to_b.c \
			init_b_to_a.c \
			push_swap.c \
			push.c \
			rev_rotate.c \
			rotate.c \
			sort_stacks.c \
			sort_three.c \
			split.c \
			stack_init.c \
			stack_utils.c \
			swap.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): ${OBJ}
	$(CC)	$(CFLAGS)	$(OBJ)	-o	$(NAME)

clean:
	rm	-f	$(OBJ)

fclean:	clean
	rm	-f	$(NAME)

re: fclean	all

.PHONY: all clean fclean re