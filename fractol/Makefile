NAME = fractol
LIBMLX := ./MLX42
HEADERS := -I $(LIBMLX)/include

LIBFT = ./inc/libft/libft.a
PRINTF = ./inc/printf/libftprintf.a

SRCS = fractol.c \
       init.c \
       checks_n_strings.c \
       maf_utils.c \
       draw.c \
       color.c \
       color_group.c \
       hooks.c \
       ft_atof.c \
       error.c \

OBJS = $(SRCS:.c=.o)

LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -L "/Users/$(USER)/.brew/opt/glfw/lib/"

# ANSI color codes
COLOR_GREEN := \033[0;32m
COLOR_RESET := \033[0m

# Default target
all: libmlx $(LIBFT) $(PRINTF) $(NAME)

# Download MLX42 if not already present
$(LIBMLX):
	@if [ ! -d "$(LIBMLX)" ]; then \
		echo "$(COLOR_GREEN)Cloning MLX42 repository...$(COLOR_RESET)"; \
		git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX); \
	fi

# Build libft
$(LIBFT):
	@make -C ./inc/libft

# Build libftprintf
$(PRINTF):
	@make -C ./inc/printf

# Build libmlx
libmlx: $(LIBMLX)
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# Compile object files
%.o: %.c
	@cc -Wall -Wextra -Werror -c -g $< -o $@

# Link the final executable
$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@cc -Wall -Wextra -Werror -g $(OBJS) $(LIBS) $(LIBFT) $(PRINTF) $(HEADERS) -o $@
	@echo "$(COLOR_GREEN)fract-ol is compiled$(COLOR_RESET)"

# Clean up object files and libmlx build directory
clean:
	@rm -f $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make clean -C ./inc/libft
	@make clean -C ./inc/printf

# Full clean including the executable
fclean: clean
	@rm -f $(NAME)
	@rm -rdf $(LIBMLX)
	@make fclean -C ./inc/libft
	@make fclean -C ./inc/printf

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re libmlx

