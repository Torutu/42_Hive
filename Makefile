# Variables
NAME = test
LIBMLX    := ./MLX42
HEADERS    := -I $(LIBMLX)/include

LIBFT = ./inc/libft/libft.a
PRINTF = ./inc/printf/libftprintf.a

SRCS = fractol.c \
       init.c \
       checks_n_strings.c \
       maf_utils.c \
       draw.c \
	   color.c \
	   color_group.c \


OBJS= $(SRCS:.c=.o)

LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -L "/Users/$(USER)/.brew/opt/glfw/lib/"

# Default target
all: libmlx $(LIBFT) $(PRINTF) $(NAME)

# Build libft
$(LIBFT):
	@make -C ./inc/libft

# Build libftprintf
$(PRINTF):
	@make -C ./inc/printf

# Build libmlx
libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# Compile object files
%.o: %.c
	cc -Wall -Wextra -Werror -c -fsanitize=address -g $< -o $@

# Link the final executable
$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	cc -Wall -Wextra -Werror -fsanitize=address -g $(OBJS) $(LIBS) $(LIBFT) $(PRINTF) $(HEADERS) -o $@

# Clean up object files and libmlx build directory
clean:
	@rm -f $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make clean -C ./inc/libft
	@make clean -C ./inc/printf

# Full clean including the executable
fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./inc/libft
	@make fclean -C ./inc/printf

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re libmlx

