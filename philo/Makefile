NAME = philo
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = src/

SRCS =  $(SRC_DIR)main.c \
        $(SRC_DIR)check_args.c \
        $(SRC_DIR)eat_utils.c \
        $(SRC_DIR)error.c \
        $(SRC_DIR)gets.c \
        $(SRC_DIR)gets_utils.c \
        $(SRC_DIR)monitor.c \
        $(SRC_DIR)munch.c \
        $(SRC_DIR)routine.c \
        $(SRC_DIR)set.c \
        $(SRC_DIR)think.c \
        $(SRC_DIR)time.c \
        $(SRC_DIR)utils.c \
        $(SRC_DIR)zzz.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

