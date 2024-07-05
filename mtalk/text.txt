NAMECL = client
NAMESR = server

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
LIBFT = ./libft/libft.a
PRINTF = ./printf/libftprintf.a

SSRC = server.c \

CSRC = client.c \

SOBJ = $(SSRC:.c=.o)

COBJ = $(CSRC:.c=.o)

start:
	@make all

$(LIBFT):
	@make -C ./libft
$(PRINTF):
	@make -C ./printf

$(NAMECL): ${COBJ} $(LIBFT) $(PRINTF)
	$(CC)	$(CFLAGS)	$(COBJ)	$(PRINTF)	$(LIBFT) -o $(NAMECL)

$(NAMESR): ${SOBJ} $(LIBFT) $(PRINTF)
	$(CC)	$(CFLAGS)	$(SOBJ)	$(PRINTF)	$(LIBFT) -o $(NAMESR)

all : $(NAMECL) $(NAMESR)


clean:
	@rm -f $(COBJ)
	@rm -f $(SOBJ)
	@make clean  -C ./libft

fclean: clean
	@rm -f  $(NAMECL)
	@rm -f  $(NAMESR)
	@make fclean -C  ./libft

re: fclean all

.PHONY: start  all clean fclean re
