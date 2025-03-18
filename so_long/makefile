NAME = so_long

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	MAIN_LDFLAGS = -L ./lib/MLX42/build -lmlx42 -lX11 -lXext -lm -pthread -lglfw -ldl
else ifeq ($(UNAME_S),Darwin)
	GLFW_PATH = $(shell brew --prefix glfw)
	MAIN_LDFLAGS = -L ./lib/MLX42/build -lmlx42 \
        		-L $(GLFW_PATH)/lib -lglfw \
            	-framework OpenGL -framework AppKit -ldl -pthread -lm
endif

SRC = $(addprefix src/, main.c map_parser.c error_handling.c banner.c player_control.c player_assets.c render_manager.c assets_init.c assets_loader.c map_validation.c textures.c render_core.c cleanup.c map_utils.c update_game.c)
BONUS = $(addprefix bonus/, move_count_bonus.c textures_bonus.c enemy_control_bonus.c enemy_init_bonus.c enemy_texture_cleanup_bonus.c enemy_ctrl_helper_bonus.c) 
GNL_SRC = $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c)
LIBFT_SRC = $(wildcard libft/*.c )
PRINTF_SRC = $(addprefix ft_printf/, ft_print_percent.c ft_printf_char.c ft_printf_hex_upper.c ft_printf_hex.c ft_printf_int.c ft_printf_pointer.c ft_printf_str.c ft_printf_uint.c ft_printf.c ft_putchar.c ft_printf_strlen.c)
OBJ := $(SRC:%.c=%.o)
OBJ_BONUS := $(BONUS:%.c=%.o)
GNL_OBJ := $(GNL_SRC:%.c=%.o)
PRINTF_OBJ := $(PRINTF_SRC:%.c=%.o)
LIBFT_OBJ := $(LIBFT_SRC:%.c=%.o)
CCFLAGS = -g -Wextra -Wall -Werror -Wunreachable-code
INCLUDES = -I ./lib/MLX42/include -I ./includes

# MLX Settings
MLX_DIR		= mlx
MLX_LINK	= -Lmlx -lmlx -framework OpenGL -framework AppKit

all: mlx42 $(NAME)

$(NAME): $(OBJ) $(OBJ_BONUS) $(GNL_OBJ) $(PRINTF_OBJ) $(LIBFT_OBJ)
	gcc $(CCFLAGS) -fsanitize=address $^ $(MAIN_LDFLAGS) -o $@

%.o: %.c
	gcc $(CCFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS) $(GNL_OBJ) $(PRINTF_OBJ) $(LIBFT_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Build MLX42 library
mlx42: lib/MLX42/build/libmlx42.a
lib/MLX42/build/libmlx42.a:
	@echo "Building MLX42 library..."
	@if [ ! -d "lib/MLX42" ]; then git clone https://github.com/codam-coding-college/MLX42.git lib/MLX42; fi
	@cmake -S lib/MLX42 -B lib/MLX42/build -DCMAKE_BUILD_TYPE=Release
	@cmake --build lib/MLX42/build --target mlx42 -j4


libft:
	@echo "$(CYAN) Compiling...Please wait!\n"
	@make --silent -C libft

ft_printf:
	@make --silent -C ft_printf

.PHONY: all clean fclean re mlx42 libft ft_printf get_next_line
