
NAME = philo
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = src/
OBJ_DIR = objects/

SRC =	philo \
    	parse \
    	init_data \
    	routine \
    	time \
		utils \
    	monitor \
       	eat_1 \
    	eat_2 \
    	sleep \
    	think \
    	getters_1 \
    	getters_2 \
    	setters

SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC)))

OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC)))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "Philo is compiled"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@echo "Objects removed"

fclean: clean
	@$(RM) $(NAME)
	@echo "executable removed"

re: fclean all

.PHONY: all clean fclean re
