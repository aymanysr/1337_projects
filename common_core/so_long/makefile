NAME = so_long

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	LDFLAGS = -L ./lib/MLX42/build -lmlx42 -lX11 -lXext -lm -pthread -lglfw -ldl
else ifeq ($(UNAME_S),Darwin)
	GLFW_PATH = $(shell brew --prefix glfw)
	LDFLAGS = -L ./lib/MLX42/build -L $(GLFW_PATH)/lib -lmlx42 -lglfw -framework OpenGL -framework AppKit -ldl -pthread -lm
endif

SRC = $(addprefix src/, main.c map_parser.c)
GNL_SRC = $(addprefix gnl/, get_next_line.c get_next_line_utils.c)
LIBFT_SRC = $(wildcard libft/*.c )
PRINTF_SRC = $(addprefix ft_printf/, ft_print_percent.c ft_printf_char.c ft_printf_hex_upper.c ft_printf_hex.c ft_printf_int.c ft_printf_pointer.c ft_printf_str.c ft_printf_uint.c ft_printf.c ft_putchar.c ft_strlen.c)
OBJ := $(SRC:%.c=%.o)
GNL_OBJ := $(GNL_SRC:%.c=%.o)
PRINTF_OBJ := $(PRINTF_SRC:%.c=%.o)
LIBFT_OBJ := $(LIBFT_SRC:%.c=%.o)
CCFLAGS = -Wextra -Wall -Werror -Wunreachable-code
INCLUDES = -I ./includes -I ./lib/MLX42/include

# MLX Settings
MLX_DIR		= mlx
MLX_LINK	= -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ) $(LIBFT_OBJ)
	gcc $(CCFLAGS) -fsanitize=address $^ $(MLX_LINK) -o $@

%.o: %.c
	gcc $(CCFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ) $(LIBFT_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Build MLX42 library
clone_mlx42:
	@git clone https://github.com/codam-coding-college/MLX42.git lib/MLX42

mlx42:
	@echo "$(YELLOW)Building MLX42 library...$(DEF_COLOR)"
	@cmake ./lib/MLX42 -B ./lib/MLX42/build
	@make -C ./lib/MLX42/build -j4

libft:
	@echo "$(CYAN) Compiling...Please wait!\n"
	@make --silent -C libft

ft_printf:
	@make --silent -C ft_printf

.PHONY: all clean fclean re mlx42 libft ft_printf gnl
