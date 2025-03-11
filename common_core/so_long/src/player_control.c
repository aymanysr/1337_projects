#include "../includes/so_long.h"

void player_coordinates(t_game *game, char c)
{
	if (c == 'r')
	{
		game->player.x_pos++;
		game->player.direction = 'r';
	}
	else if (c  == 'l')
	{
		game->player.x_pos--;
		game->player.direction = 'l';
	}
	else if (c == 'u')
	{
		game->player.y_pos--;
		game->player.direction = 'u';
	}
	else if (c == 'd')
	{
		game->player.y_pos++;
		game->player.direction = 'd';
	}
}

void	update_player_position(t_game *game, int x, int y, char direction)
{
	int	new_x;
	int	new_y;

	new_x = x;
	new_y = y;
	if (direction == 'r')
		new_x++;
	else if (direction == 'l')
		new_x--;
	else if (direction == 'u')
		new_y--;
	else if (direction == 'd')
		new_y++;
	game->map[y][x] = '0';
	game->map[new_y][new_x] = 'P';
	player_coordinates(game, direction);
}

static void	move_player(t_game *game, int dx, int dy, char direction)
{
	int	x;
	int	y;

	x = game->player.x_pos;
	y = game->player.y_pos;
	if (game->map[y + dy][x + dx] != '1')
	{
		if (game->map[y + dy][x + dx] == 'C'
			|| game->map[y + dy][x + dx] == '0')
		{
			if (game->map[y + dy][x + dx] == 'C')
				game->collectibles--;
			update_player_position(game, x, y, direction);
			game->move_count++;
			ft_printf("Move count increased to: %d\n", game->move_count); // Debug print


		}
		else if (game->map[y + dy][x + dx] == 'E')
		{
			if (game->collectibles == 0)
			{
				game->move_count++;
				game_renderer(game);
				img_destroyer(game, "[***] You won!", G);
			}
		}
	}
	else
		game->player.direction = direction;
}

int	key_hooks(int keycode, t_game *game)
{
	if (keycode == MLX_KEY_RIGHT || keycode == MLX_KEY_D)
		move_player(game, 1, 0, 'r');
	else if (keycode == MLX_KEY_LEFT || keycode == MLX_KEY_A)
		move_player(game, -1, 0, 'l' );
	else if (keycode == MLX_KEY_UP || keycode == MLX_KEY_W) 
		move_player(game, 0, -1, 'u');
	else if (keycode == MLX_KEY_DOWN || keycode == MLX_KEY_S)
		move_player(game, 0, 1, 'd');
	else if (keycode == MLX_KEY_ESCAPE)
		img_destroyer(game, "[.] You have pressed ESC", R);
	game_renderer(game);
	return (1);        
}

void	player_moover(mlx_key_data_t key_data, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key_data.action != MLX_PRESS)
		return ;
	if (key_data.key == MLX_KEY_ESCAPE)
		img_destroyer(game, "[.] You have pressed ESC", R);
	else
		key_hooks(key_data.key, game);
}
