#include "../includes/so_long.h"

void game_renderer(t_game *game)
{
    int x;
    int y;

    y = 0;
    load_elements(game);
    load_player(game);
    while (y < game->map_length)
    {
        x = 0;
        renderer(game, x, y);
        ++y;
    }
    
}