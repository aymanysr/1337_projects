#include "../includes/so_long.h"

void    vars_initializer(t_game *game)
{
    game->image.width = 1;
    game->image.height = 1;
    game->player.x_pos = 0;
    game->player.y_pos = 0;
    game->player.direction = 'd';
    game->exit.x_pos = 0;
    game->exit.y_pos = 0;
    game->collectibles = 0;
    game->players = 0;
    game->exits = 0;
    game->move_count = 1;
}