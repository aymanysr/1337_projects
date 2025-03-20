#include "../includes/so_long.h"

void	update_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	update_animation(game);
	game_renderer(game);
}