#include "../includes/so_long.h"

void renderer(t_game *game)
{
	int x;
	int y;

	/* Clear the buffer */
	ft_memset(game->buffer->pixels, 0xFF, 
		game->buffer->width * game->buffer->height * BPP);
	
	/* Render each cell of the map (which draws background, walls, collectibles, exit, and player) */
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			render_cell(game, x, y);
			x++;
		}
		y++;
	}
	/* Update enemy positions, check collisions, and render enemy sprites */
	update_enemy_patrol(game);    
}

void	game_renderer(t_game *game)
{
	renderer(game);
	display_move_count(game);
}

void	update_animation(void *param)
{
	static int	counter = 0;
	t_game		*game;

	game = (t_game *)param;
	counter++;
	if (counter >= 10)
	{
		game->animation_frame = !game->animation_frame;
		counter = 0;
	}
}

