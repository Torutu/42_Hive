NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c\
	   ft_printhex.c ft_printint.c ft_printptr.c\
	   ft_printuint.c ft_printstrc.c\

OBJS = $(SRCS:.c=.o)

INCL = ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C ./libft

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all

.PHONY: all re clean fclean
